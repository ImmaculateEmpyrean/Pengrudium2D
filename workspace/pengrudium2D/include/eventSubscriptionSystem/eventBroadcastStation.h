#pragma once
#include<memory>
#include<vector>
#include<string>

#include "entityComponentSystem/entity.h"
#include "eventSubscriptionSystem/events.h"

namespace penguin2D
{
	class eventBroadcastStation
	{
	public:
		eventBroadcastStation() = default; //there is no point in constructing this object since all its methods are pretty much static..

	public:
		static void addSubscription(penguin2D::entity observer, penguin2D::entity observee);
		static void addSubscription(penguin2D::entity observer, penguin2D::eventType globalEventType);

		static void removeSubscription(penguin2D::entity observer, penguin2D::eventType globalEventType);

		static void broadcastSignal();
		static void retrieveMail();
	};
}