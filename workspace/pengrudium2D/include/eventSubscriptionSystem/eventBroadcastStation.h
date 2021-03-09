#pragma once
#include<memory>
#include<queue>

#include "eventSubscriptionSystem/events.h"

namespace penguin2D
{

	class entity;

	class eventBroadcastStation
	{
	public:
		eventBroadcastStation() = default;

	public:
		static void addSubscription(entity observer, entity observee, signalType signal);	
		static void addSubscription(entity observer, eventType globalEventType);

		static void removeSubscription(entity observer, entity observee, signalType signal);
		static void removeSubscription(entity observer, eventType globalEventType);

		static void broadcastGlobalEvent(std::shared_ptr<eventBase> brdcstEvent);
		static void broadcastSignal(std::shared_ptr<observerEvent> brdcstEvent);

		static std::queue<std::shared_ptr<eventBase>> retrieveMail(entity reciever);	
	};
}