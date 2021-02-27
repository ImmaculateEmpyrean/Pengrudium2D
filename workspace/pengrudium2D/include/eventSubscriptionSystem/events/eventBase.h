#pragma once
#include "eventSubscriptionSystem/eventType.h"

namespace penguin2D
{
	class eventBase
	{
	public:
		virtual ~eventBase() {};

	public:
		virtual eventType GetEventType() = 0;

	};
}