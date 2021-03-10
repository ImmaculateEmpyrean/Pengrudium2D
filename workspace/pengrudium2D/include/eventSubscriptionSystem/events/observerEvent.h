#pragma once
#include "eventSubscriptionSystem/Events/eventBase.h"
#include "entityComponentSystem/internal/entityI.h"

#include<optional>

namespace penguin2D
{
	class observerEvent : public penguin2D::eventBase
	{
	public:
		observerEvent() = delete;
		observerEvent(penguin2D::entityI sender)
			: eventBase(),m_sender(sender)
		{}

		virtual ~observerEvent() {};

	public:
		virtual eventType	getEventType() { return eventType::observer; };
		virtual signalType	getSignalType() = 0;

		//this only has a try get component because the sender may be invalid by the time we try to get its component..
		//as of this writing.. the ABA problem may potentially exist as I have not checked entt..
		template<typename T>
		std::optional<T> tryGetSenderComponent()	{return m_sender.tryGetComponent<T>();};
		
		//note- this looks more useful than it is.. only atomic operations are guarenteed u cannot assume this component still exists after 
		//		any amount of time whatsoever.
		template<typename T>
		bool senderHasComponent() { return m_sender.componentExists<T>(); };

	private:
		penguin2D::entityI m_sender;
	};
}