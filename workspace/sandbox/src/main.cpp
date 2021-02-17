#include "stdafx.h"
#include "cacheLineSize.h"

#include "core/symbols.h"
#include "instrumentation/instrumentation.h"

#include "entityComponentSystem/entity.h"

#include "entityComponentSystem/component/nameComponent.h"

int main()
{
	std::shared_ptr<penguin2D::scene> scenePtr = std::make_shared<penguin2D::scene>();

	penguin2D::entity ent(scenePtr);
	ent.addComponent<penguin2D::nameComponent>(std::string("hanna"));

	auto name = ent.getComponent<penguin2D::nameComponent>();
	std::cout << name.m_name;
}