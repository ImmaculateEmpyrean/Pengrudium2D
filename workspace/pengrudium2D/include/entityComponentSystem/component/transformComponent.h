#pragma once
#include <glm/glm.hpp>

namespace penguin2D
{
	struct transformComponent
	{
		transformComponent() = default;
		transformComponent(glm::mat4 transform)
			:m_transform(transform)
		{}

		glm::mat4 m_transform = glm::mat4(1.0f);
	};
}