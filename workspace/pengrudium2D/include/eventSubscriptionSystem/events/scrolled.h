#pragma once
#include "eventSubscriptionSystem/eventType.h"
#include "eventBase.h"

namespace penguin2D
{

	class scrolled :public eventBase
	{
	public:
		scrolled(double xoffset,double yoffset)
			: m_xoffset(xoffset), m_yoffset(yoffset)
		{}

	public:
		virtual eventType getEventType() override { return eventType::scrolled; }

		double m_xoffset;
		double m_yoffset;
	};
}