#pragma once
#include<iostream>
#include<vector>
#include<string>

#include<optional>
#include<utility>
#include<memory>

#include "entt.h"
#include "scene.h"

//#include "eventSubscriptionSystem/eventBroadcastStation.h"

namespace penguin2D
{
	class entity
	{
	public:
		entity() = delete; //no entity can be created without first specifying which scene it belongs to..
		entity(entt::entity entity,std::shared_ptr<scene> scenePtr);

	private:
		entity(std::shared_ptr<scene> scenePtr);

	public:
		static entity createEntity(std::shared_ptr<scene> scenePtr);

	public:
		template<typename T,typename... ARGS>
		void addComponent(ARGS... args)
		{
			m_sceneRef->m_sceneRegistry.emplace<T>(m_id, std::forward<ARGS>(args)...);
		}

		template<typename T>
		void updateComponent(T& obj)
		{
			m_sceneRef->m_sceneRegistry.replace<T>(m_id, obj);
		}
		template<typename T>
		bool componentExists()
		{
			return m_sceneRef->m_sceneRegistry.has<T>(m_id);
		}

		template<typename T>
		T& getComponent()
		{
			return m_sceneRef->m_sceneRegistry.get<T>(m_id);
		}
		template<typename T>
		std::optional<T> tryGetComponent()
		{
			auto component = m_sceneRef->m_sceneRegistry.try_get<T>(m_id);
			if (component)
				return (*component);
			else
				return { };
		}

		template<typename T>
		void deleteComponent()
		{
			m_sceneRef->m_sceneRegistry.remove<T>(m_id);
		}


		template<typename EVENT,typename... ARGS>
		void broadcastGlobalEvent(ARGS... args)
		{
			std::shared_ptr<EVENT> brdcstEvent = std::make_shared<EVENT>(std::forward(args...));
			penguin2D::eventBroadcastStation::broadcastGlobalEvent(brdcstEvent);
		}
		

		/*void broadcastSignal	 (penguin2D::signalType signalNumber);
		
		void addSubscription(penguin2D::eventType sigTyp);
		void addSubscription(penguin2D::entity observee, penguin2D::signalType sig);

		void removeSubscription(penguin2D::eventType eventType);
		void removeSubscription(penguin2D::entity observee);
		void removeSubscription(penguin2D::entity observee, penguin2D::signalType sig);*/

	private:
		entt::entity m_id;
		std::shared_ptr<scene> m_sceneRef = nullptr;

	};
}