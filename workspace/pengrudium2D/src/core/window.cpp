#include "stdafx.h"
#include "core/window.h"

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<imgui.h>

namespace penguin2D
{
	window::~window()
	{
		//fill it later 
	}

	void window::move(window&& rhs)
	{
		m_title  = std::move(rhs.m_title);
		m_width	 = std::move(rhs.m_width);
		m_height = std::move(rhs.m_height);

		m_winPtr = rhs.m_winPtr;
		rhs.m_winPtr = nullptr;
	}
}