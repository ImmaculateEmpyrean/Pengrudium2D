#include "stdafx.h"

#include "entityComponentSystem/scene.h"
#include "entityComponentSystem/entity.h"
#include "entityComponentSystem/component.h"

#include "entityComponentSystem/systems/scriptProcessingSystem.h"

#include "eventSubscriptionSystem/eventBroadcastStation.h"

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

class testEvent : public observerEvent
{
public:
	testEvent::testEvent(penguin2D::entity sender)
		:observerEvent(sender)
	{}
	virtual penguin2D::signalType getSignalType()
	{
		return 5;
	}
};

int main()
{
	initializeEngine();
	std::shared_ptr<scene> sc = std::make_shared<scene>();

	penguin2D::entity ent	=	entity::createEntity(sc);
	penguin2D::entity ent2	=	entity::createEntity(sc);

	ent.addSubscription(ent2, 5);
	ent2.broadcastEvent<testEvent>();

	while (true)
	{
		auto mail  = eventBroadcastStation::retrieveMail(ent);
		if (mail.size() > 0 )
		{
			logConsoleInfo("guess I recieved some mail.");
		}
	}
}