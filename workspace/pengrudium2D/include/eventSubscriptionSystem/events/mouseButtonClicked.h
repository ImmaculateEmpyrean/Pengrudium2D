#pragma once
#include "eventSubscriptionSystem/eventType.h"
#include "eventBase.h"

namespace penguin2D
{
	class mouseButtonClicked :public eventBase
	{
	public:
		mouseButtonClicked(int button,int action,int mods)
			: m_button(button), m_action(action) , m_mods(mods)
		{}

	public:
		virtual eventType getEventType() override { return eventType::mouseButtonClicked; }

		int m_button;
		int m_action;
		int m_mods;
	};
}