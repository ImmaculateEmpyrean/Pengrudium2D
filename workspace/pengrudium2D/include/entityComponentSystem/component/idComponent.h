#pragma once
#include "uuid.h"

namespace penguin2D
{
	struct idComponent
	{
		idComponent() = delete;
		idComponent(uuids::uuid id)
			: m_id(id)
		{}

		uuids::uuid m_id;
	};
}