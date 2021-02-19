#pragma once
#include "entityComponentSystem/scene.h"
#include "entityComponentSystem/entity.h"

namespace penguin2D
{
	class scriptable
	{
	public:
		scriptable() = delete; //cant allow no entity to be specified..
		scriptable(penguin2D::entity ent)
			:
			m_entity(std::make_shared<penguin2D::entity>(ent))
		{}

		virtual void onStart  ()	{};
		virtual void onUpdate ()	{};
		virtual void onDestroy()	{};

	protected:
		template<typename T>
		T& getComponent()
		{	return m_entity->getComponent<T>();	}

		template<typename T,typename... ARGS>
		void addComponent()	
		{	m_entity->setComponent<T>(std::forward(ARGS)...);	}

	private:
		std::shared_ptr<entity> m_entity;
	};


	struct scriptComponent
	{
	public:
		scriptComponent() = delete;
		scriptComponent(scriptable* scrPointer)
			: m_script(scrPointer)
		{}


		std::shared_ptr<scriptable> m_script;
	};
}