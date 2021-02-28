#include "stdafx.h"
#include "eventSubscriptionSystem/eventBroadcastStation.h"

#include "uuid.h"
#include "entityComponentSystem/component/idComponent.h"

using namespace penguin2D;

static struct box
{
	box()
	{
		m_intrestedEvents.resize(7,0);
	}

	std::unordered_map<uuids::uuid, std::set<signalType>> observees;

	std::vector<std::uint32_t> m_intrestedEvents;
	std::queue<std::shared_ptr<eventBase>> m_eventBuffer;

	std::mutex boxMutex;
};

static std::unordered_map<uuids::uuid, box> storage;

namespace penguin2D
{
	void eventBroadcastStation::addSubscription(entity observer, entity observee, signalType signal)
	{
		auto idObserver = observer.getComponent<idComponent>().m_id;
		auto idObservee = observer.getComponent<idComponent>().m_id;

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
	void eventBroadcastStation::addSubscription(entity observer, eventType globalEventType)
	{
		auto idObserver = observer.getComponent<idComponent>().m_id;
		{
			std::lock_guard gaurd(storage[idObserver].boxMutex);
			storage[idObserver].m_intrestedEvents[(unsigned int)globalEventType] = 1;
		}
	}


	void eventBroadcastStation::removeSubscription(entity observer, entity observee, signalType signal)
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
	void eventBroadcastStation::removeSubscription(entity observer,eventType globalEvent)
	{
		auto idObserver = observer.getComponent<idComponent>().m_id;

		{
			std::lock_guard gaurd(storage[idObserver].boxMutex);
			storage[idObserver].m_intrestedEvents[(std::uint32_t)globalEvent] = 0;
		}
	}


	void eventBroadcastStation::broadcastGlobalEvent(std::shared_ptr<eventBase> brdcstEvent)
	{
		//the job scheduler is required for this implementation
	}
	void eventBroadcastStation::broadcastSignal(std::shared_ptr<observerEvent> brdcstEvent)
	{
		//the job scheduler is required for this implementation
	}


	std::queue<std::shared_ptr<eventBase>> eventBroadcastStation::retrieveMail(entity reciever)
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