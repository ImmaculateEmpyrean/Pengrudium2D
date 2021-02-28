#pragma once
#include "eventSubscriptionSystem/eventType.h"
#include "eventBase.h"

namespace penguin2D
{
	class cursorPositionChanged :public eventBase
	{
	public:
		cursorPositionChanged(int xpos,int ypos)
			: m_xpos(xpos), m_ypos(ypos)
		{}

	public:
		virtual eventType getEventType() override { return eventType::cursorPositionChanged; }
		
		int m_xpos;
		int m_ypos;
	};

}