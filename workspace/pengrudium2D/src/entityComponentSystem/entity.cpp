#include "stdafx.h"
#include "entityComponentSystem/entity.h"
#include "entityComponentSystem/component.h"

#include "eventSubscriptionSystem/eventBroadcastStation.h"

namespace penguin2D
{
	entity::entity(entt::entity entity, std::shared_ptr<scene> scenePtr)
		:	entityI(entity,scenePtr)
	{}
	entity::entity(std::shared_ptr<scene> scenePtr)
		:	entityI(scenePtr)
	{}


	penguin2D::entity entity::createEntity(std::shared_ptr<scene> scenePtr)
	{
		return entity(scenePtr);
	}


	void entity::addSubscription(penguin2D::eventType eveType)
	{
		penguin2D::eventBroadcastStation::addSubscription(*this, eveType);
	}
	void entity::addSubscription(penguin2D::entity observee, penguin2D::signalType sigType)
	{
		penguin2D::eventBroadcastStation::addSubscription(*this, observee, sigType);
	}


	void entity::removeSubscription(penguin2D::eventType eveType)
	{
		penguin2D::eventBroadcastStation::removeSubscription(*this, eveType);
	}
	void entity::removeSubscription(penguin2D::entity observee)
	{
		penguin2D::eventBroadcastStation::removeSubscription(*this, observee);
	}
	void entity::removeSubscription(penguin2D::entity observee, penguin2D::signalType sig)
	{
		penguin2D::eventBroadcastStation::removeSubscription(*this, observee, sig);
	}
	void entity::removeSubscription()
	{
		penguin2D::eventBroadcastStation::removeSubscription(*this);
	}
}