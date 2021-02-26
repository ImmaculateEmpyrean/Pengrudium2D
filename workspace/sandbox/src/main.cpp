#include "stdafx.h"

#include "entityComponentSystem/scene.h"
#include "entityComponentSystem/entity.h"
#include "entityComponentSystem/component.h"

#include "entityComponentSystem/systems/scriptProcessingSystem.h"

#include "core/core.h"

using namespace penguin2D;

struct testScriptComponent : scriptable
{
public:
	testScriptComponent() = delete; //since scriptable cannot be default constructed..
	testScriptComponent(penguin2D::entity& ent)
		:
		scriptable(ent)
	{}

	virtual void onUpdate()
	{
		logConsoleInfo("update called");
		logConsoleInfo("name of this entity is : {}", tryGetComponent<nameComponent>().value_or(nameComponent("test")).m_name);
	}
};

int main()
{
	initializeEngine();
	std::shared_ptr<scene> sc = std::make_shared<scene>();
	auto ent = entity::createEntity(sc);

	std::cout << "entity id : " << ent.getComponent<idComponent>().m_id << std::endl;
}