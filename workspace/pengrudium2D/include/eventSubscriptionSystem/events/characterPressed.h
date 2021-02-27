#pragma once
#include "eventSubscriptionSystem/eventType.h"
#include "eventBase.h"

namespace penguin2D
{
	class characterPressed :public eventBase
	{
	public:
		characterPressed() = delete;
		characterPressed(unsigned int characterPressed)
			: m_characterPressed(characterPressed)
		{}

	public:
		virtual eventType GetEventType() override { return eventType::characterPressed; }
		
		unsigned int m_characterPressed;
	};
}