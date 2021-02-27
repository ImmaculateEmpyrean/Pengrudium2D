#pragma once
#include<memory>
#include<vector>
#include<string>

#include "events.h"

namespace penguin2D
{
	class eventBroadcastStation
	{
	public:
		eventBroadcastStation() = default; //there is no point in constructing this object since all its methods are pretty much static..

	public:
		static void addSubscription();
		static void removeSubscription();

		static void broadcastSignal();
		static void retrieveMail();
	};
}