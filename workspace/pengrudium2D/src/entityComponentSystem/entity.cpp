#include "stdafx.h"
#include "entityComponentSystem/entity.h"

#include "entt.h"

using namespace entt;
using namespace penguin2D;

namespace penguin2D
{
	entity::entity(std::uint32_t entity, std::shared_ptr<scene> scenePtr)
		:
		m_id((entt::entity)entity),
		m_sceneRef(scenePtr)
	{}

	entity::entity(std::shared_ptr<scene> scenePtr)
		:
		m_sceneRef(scenePtr)
	{
		m_id = m_sceneRef->m_sceneRegistry.create();
	}
}