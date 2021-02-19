#include "stdafx.h"

#include "entityComponentSystem/scene.h"
#include "entityComponentSystem/entity.h"
#include "entityComponentSystem/component.h"

#include "entityComponentSystem/systems/scriptProcessingSystem.h"

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
	std::shared_ptr<scene> sc = std::make_shared<scene>();

	entity ent(sc);
	ent.addComponent<nameComponent>(std::string("hanna"));
	ent.addComponent<scriptComponent>(new testScriptComponent(ent));

	for(int i=0;i<1000;i++)
	{
		penguin2D::scheduleOnUpdateSystem(sc);
	}
}