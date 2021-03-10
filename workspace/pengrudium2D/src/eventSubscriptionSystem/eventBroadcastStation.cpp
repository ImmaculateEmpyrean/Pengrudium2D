#include "stdafx.h"
#include "eventSubscriptionSystem/eventBroadcastStation.h"

#include "entityComponentSystem/entity.h"

#include "asynqro/asynqro"

#include "uuid.h"
#include "entityComponentSystem/component/idComponent.h"

using namespace penguin2D;

static struct box
{
	box()
	{
		m_intrestedGlobalEvents.resize(7,0);
	}

	//all the entities being observed by this observer
	std::unordered_map<uuids::uuid, std::set<signalType>> observees;
	//all the global events this observer is intrested in
	std::vector<std::uint32_t> m_intrestedGlobalEvents;

	//the queue of all the events polled for this observer
	std::queue<std::shared_ptr<eventBase>> m_eventBuffer;

	//this mutex is to be acquired to gain write access to this box as a ehole..
	std::mutex boxMutex;
};

static std::unordered_map<uuids::uuid, box> storage;

namespace penguin2D
{
	void eventBroadcastStation::addSubscription(entityI observer, entityI observee, signalType signal)
	{
		auto idObserver = observer.getComponent<idComponent>().m_id;
		auto idObservee = observee.getComponent<idComponent>().m_id;

		auto iter = storage[idObserver].observees.find(idObservee);

		if (iter != storage[idObserver].observees.end())
		{
			std::lock_guard gaurd(storage[idObserver].boxMutex);
			iter->second.emplace(signal);
		}
		else
		{
			std::lock_guard gaurd(storage[idObserver].boxMutex);
			storage[idObserver].observees.emplace(std::make_pair(idObservee, std::set<signalType>({ signal })));
		}
	}
	void eventBroadcastStation::addSubscription(entityI observer, eventType globalEventType)
	{
		auto idObserver = observer.getComponent<idComponent>().m_id;
		{
			std::lock_guard gaurd(storage[idObserver].boxMutex);
			storage[idObserver].m_intrestedGlobalEvents[(unsigned int)globalEventType] = 1;
		}
	}


	void eventBroadcastStation::removeSubscription(entityI observer, entityI observee, signalType signal)
	{
		auto idObserver = observer.getComponent<idComponent>().m_id;
		auto idObservee = observee.getComponent<idComponent>().m_id;

		auto iter = storage[idObserver].observees.find(idObservee);

		if (iter != storage[idObserver].observees.end())
		{
			std::lock_guard gaurd(storage[idObserver].boxMutex);
			iter->second.erase(signal);
		}
		else return;
	}
	void eventBroadcastStation::removeSubscription(entityI observer, entityI observee)
	{
		auto idObserver = observer.getComponent<idComponent>().m_id;
		auto idObservee = observee.getComponent<idComponent>().m_id;

		storage[idObserver].observees.erase(idObservee);
	}
	void eventBroadcastStation::removeSubscription(entityI observer,eventType globalEvent)
	{
		auto idObserver = observer.getComponent<idComponent>().m_id;

		{
			std::lock_guard gaurd(storage[idObserver].boxMutex);
			storage[idObserver].m_intrestedGlobalEvents[(std::uint32_t)globalEvent] = 0;
		}
	}
	void eventBroadcastStation::removeSubscription(entityI observer)
	{
		auto idObserver = observer.getComponent<idComponent>().m_id;
		storage.erase(idObserver);
	}


	void eventBroadcastStation::broadcastEvent(std::shared_ptr<eventBase> brdcstEvent)
	{
		//check if the recieved event is potentially an observer event..
		auto brdcstEventObserver = std::dynamic_pointer_cast<observerEvent>(brdcstEvent);

		if (brdcstEventObserver)
			broadcastSignal(brdcstEventObserver);
		else
			broadcastGlobalEvent(brdcstEvent);
	}
	void eventBroadcastStation::broadcastGlobalEvent(std::shared_ptr<eventBase> brdcstEvent)
	{
		//the job scheduler in the future is expected to have an api defined specifically for this engine in question 
		asynqro::tasks::runAndForget(asynqro::tasks::TaskPriority::Regular,[brdcstEvent]() {
			for (auto& i : storage)
			{
				box& bx = i.second;
				if (bx.m_intrestedGlobalEvents[(uint32_t)brdcstEvent->getEventType()] == 1)
				{
					std::lock_guard<std::mutex> gaurd(bx.boxMutex);
					bx.m_eventBuffer.push(brdcstEvent);
				}
			}
		});
	}
	void eventBroadcastStation::broadcastSignal(std::shared_ptr<observerEvent> brdcstEvent)
	{
		//the job scheduler in the future is expected to have an api defined specifically for this engine in question 
		asynqro::tasks::runAndForget(asynqro::tasks::TaskPriority::Regular,[brdcstEvent]() {
			for (auto& i : storage)
			{
				box& bx = i.second;
				uuids::uuid senderID;

				auto optionalId = brdcstEvent->tryGetSenderComponent<idComponent>();
				if (optionalId.has_value())
					senderID = (*optionalId).m_id;
				else
					logConsoleError("detected an entity with no id.. this is probably extremely dangerous {} {}",__LINE__,__FUNCSIG__);

				if (bx.observees.find(senderID) != bx.observees.end())
				{
					if (bx.observees[senderID].find(brdcstEvent->getSignalType()) != bx.observees[senderID].end())
					{
						std::lock_guard<std::mutex> gaurd(bx.boxMutex);
						bx.m_eventBuffer.push(brdcstEvent);
					}
				}
			}
			});
	}


	std::queue<std::shared_ptr<eventBase>> eventBroadcastStation::retrieveMail(entityI reciever)
	{
		auto idObserver = reciever.getComponent<idComponent>().m_id;
		std::queue<std::shared_ptr<eventBase>> eventBuffer;
		
		{
			std::lock_guard gaurd(storage[idObserver].boxMutex);
			eventBuffer = std::move(storage[idObserver].m_eventBuffer);
			storage[idObserver].m_eventBuffer.empty();
		}

		return std::move(eventBuffer);
	}
}