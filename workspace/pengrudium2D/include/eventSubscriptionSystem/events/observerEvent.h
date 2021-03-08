#pragma once
#include "eventSubscriptionSystem/Events/eventBase.h"
#include "entityComponentSystem/entity.h"

namespace penguin2D
{
	using signalType = std::uint32_t;

	class observerEvent : public penguin2D::eventBase
	{
	public:
		observerEvent() = delete;
		observerEvent(penguin2D::entity sender)
			: eventBase(),m_sender(sender)
		{}

		virtual ~observerEvent() {};

	public:
		virtual eventType	getEventType() { return eventType::observer; };
		virtual signalType	getSignalType() = 0;

		template<typename T>
		T getSenderComponent() { return m_sender.getComponent<T>(); };
		template<typename T>
		bool senderHasComponent() { return m_sender.componentExists<T>(); };

	private:
		penguin2D::entity m_sender;
	};
}