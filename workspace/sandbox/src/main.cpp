#include "stdafx.h"
#include "cacheLineSize.h"

#include "core/symbols.h"
#include "instrumentation/instrumentation.h"

#include "entityComponentSystem/entity.h"

#include "entityComponentSystem/component/nameComponent.h"

#include "entt.h"

using namespace penguin2D;

int main()
{
	std::shared_ptr<penguin2D::scene> scenePtr = std::make_shared<penguin2D::scene>();

	penguin2D::entity ent(scenePtr);
	std::cout << std::boolalpha << ent.componentExists<nameComponent>() << std::endl;
	ent.addComponent<penguin2D::nameComponent>(std::string("hanna"));

	auto name = ent.getComponent<penguin2D::nameComponent>();
	name.m_name = "han";
	
	ent.updateComponent<nameComponent>(name);

	auto name2 = ent.getComponent<nameComponent>();
	std::cout << std::boolalpha << ent.componentExists<nameComponent>() << std::endl;
	std::cout << name2.m_name;
}