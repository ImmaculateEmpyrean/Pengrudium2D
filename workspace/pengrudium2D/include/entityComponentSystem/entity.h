#pragma once
#include "internal/entityI.h"
#include "eventSubscriptionSystem/eventType.h"

namespace penguin2D
{
	class entity : public entityI
	{
	public:
		// entityI cannot be created using default constructor
		entity() = delete; 
		entity(entt::entity entity, std::shared_ptr<scene> scenePtr);

	protected:
		entity(std::shared_ptr<scene> scenePtr);

	public:
		static entity createEntity(std::shared_ptr<scene> scenePtr);

	public:
		template<typename EVENTCLASS, typename... ARGS>
		void broadcastEvent(ARGS... args)
		{
			std::shared_ptr<EVENTCLASS> brdcstEvent = std::make_shared<EVENTCLASS>(*this,std::forward(args)...);
			penguin2D::eventBroadcastStation::broadcastEvent(brdcstEvent);
		}

		void addSubscription(penguin2D::eventType eveType);
		void addSubscription(penguin2D::entity observee, penguin2D::signalType sig);

		//used to remove a singular global event subscription
		void removeSubscription(penguin2D::eventType eventType); 
		//used to remove an observee subscription
		void removeSubscription(penguin2D::entity observee);  
		//used to remove a specific event subscription from an observee..
		void removeSubscription(penguin2D::entity observee, penguin2D::signalType sig);
		//used to remove all subscriptions to all events..
		void removeSubscription();

	private:

	};
}