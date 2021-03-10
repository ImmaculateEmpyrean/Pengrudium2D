#pragma once
#include<memory>
#include<queue>

#include "eventSubscriptionSystem/events.h"
#include "entityComponentSystem/internal/entityI.h"

namespace penguin2D
{
	class eventBroadcastStation
	{
	public:
		eventBroadcastStation() = default;

	public:
		static void addSubscription(entityI observer, entityI observee, signalType signal);	
		static void addSubscription(entityI observer, eventType globalEventType);

		static void removeSubscription(entityI observer, entityI observee, signalType signal);
		static void removeSubscription(entityI observer, entityI observee);
		static void removeSubscription(entityI observer, eventType globalEventType);
		static void removeSubscription(entityI observer);

		static void broadcastEvent		(std::shared_ptr<eventBase> brdcstEvent);
		static void broadcastGlobalEvent(std::shared_ptr<eventBase> brdcstEvent);
		static void broadcastSignal		(std::shared_ptr<observerEvent> brdcstEvent);

		static std::queue<std::shared_ptr<eventBase>> retrieveMail(entityI reciever);	
	};
}