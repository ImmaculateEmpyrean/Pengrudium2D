#pragma once
#include "eventSubscriptionSystem/eventType.h"
#include "eventBase.h"

namespace penguin2D
{
	class keyPressed :public eventBase
	{
	public:
		keyPressed(int key,int scancode,int action,int mods)
			: m_key(key), m_scancode(scancode), m_action(action) , m_mods(mods)
		{}

	public:
		virtual eventType getEventType() override { return eventType::keyPressed; }

		int m_key;
		int m_scancode;
		int m_action;
		int m_mods;
	};
}