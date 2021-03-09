#pragma once
#include<iostream>
#include<string>
#include<vector>

#include "entt.h"

namespace penguin2D
{
	class entityI;

	class scene
	{
	public:
		scene();

	public:
		entt::registry& getRegistry() { return m_sceneRegistry; };
		void clear() { m_sceneRegistry.clear(); }

	private:
		entt::registry m_sceneRegistry;

		friend class penguin2D::entityI;
	};
}