#include "stdafx.h"
#include "entityComponentSystem/systems/scriptProcessingSystem.h"

#include "entityComponentSystem/entity.h"
#include "entityComponentSystem/scene.h"

#include "entityComponentSystem/component/scriptComponent.h"

#include <entt.h>

using namespace std;
using namespace penguin2D;
using namespace glm;
using namespace entt;

void penguin2D::scheduleOnUpdateSystem(shared_ptr<scene> scenePtr)
{
	auto& registry = scenePtr->getRegistry();
	auto& view = registry.view<scriptComponent>();
	
	for (auto& i : view)
	{
		penguin2D::entity obj(i, scenePtr);
		auto& scrComponent = obj.getComponent<scriptComponent>();
		scrComponent.m_script->onUpdate();
	}
}