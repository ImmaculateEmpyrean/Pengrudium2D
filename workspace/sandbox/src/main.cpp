#include "stdafx.h"
#include "cacheLineSize.h"

#include "core/symbols.h"
#include "instrumentation/instrumentation.h"

#include "entityComponentSystem/entity.h"

#include "entityComponentSystem/component/nameComponent.h"
#include "entityComponentSystem/component/transformComponent.h"

#include "entt.h"

using namespace penguin2D;

int main()
{
	std::shared_ptr<penguin2D::scene> scenePtr = std::make_shared<penguin2D::scene>();

	penguin2D::entity ent(scenePtr);
	std::cout << std::boolalpha << ent.componentExists<nameComponent>() << std::endl;
	ent.addComponent<transformComponent>(glm::mat4(15.0f));

	auto transform = ent.getComponent<transformComponent>();
	transform.m_transform = glm::mat4(2.0f);
	
	ent.updateComponent<transformComponent>(transform);

	auto trans = ent.getComponent<transformComponent>();
	std::cout << std::boolalpha << ent.componentExists<transformComponent>() << std::endl;
	std::cout << trans.m_transform[0][0] << std::endl;
}