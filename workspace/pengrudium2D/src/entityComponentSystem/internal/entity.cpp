#include "stdafx.h"
#include "entityComponentSystem/entity.h"
#include "entityComponentSystem/component.h"

using namespace entt;
using namespace penguin2D;

static uuids::uuid_random_generator uuidGenerator;

namespace penguin2D
{
	namespace penguin2DI
	{
		void initializeUUIDGeneration()
		{
			std::random_device rd;
			auto seed_data = std::array<int, std::mt19937::state_size> {};
			std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
			std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
			std::mt19937 generator(seq);
			uuidGenerator = uuids::uuid_random_generator(generator);
		}
	}
}


namespace penguin2D
{
	entityI::entityI(entt::entity entity, std::shared_ptr<scene> scenePtr)
		:
		m_id(entity),
		m_sceneRef(scenePtr)
	{}

	entityI::entityI(std::shared_ptr<scene> scenePtr)
		:
		m_sceneRef(scenePtr)
	{	
		m_id = m_sceneRef->m_sceneRegistry.create();
	}

	entityI entityI::createEntity(std::shared_ptr<scene> scenePtr)
	{
		entityI ent(scenePtr);
		ent.addComponent<idComponent>(uuidGenerator());

		return ent;
	}
}