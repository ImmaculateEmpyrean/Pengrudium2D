#pragma once
#include<string>

namespace penguin2D
{
	struct nameComponent
	{
		nameComponent() = default;
		nameComponent(std::string name)
			: m_name(name)
		{}


		std::string m_name = "untitled";
	};
}