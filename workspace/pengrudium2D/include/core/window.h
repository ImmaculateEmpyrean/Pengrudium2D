#pragma once
#include<string>
#include<memory>
#include<utility>

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<imgui.h>

namespace penguin2D
{
	class window
	{
	public:
		window(std::string title, int width, int height)
			: m_title(title), m_width(width), m_height(height)
		{}
		~window();

	public:
		window(const window& rhs) = delete;
		window(window&& rhs)noexcept { move(std::move(rhs)); }
		window& operator=(const window& rhs) = delete;
		window& operator=(window&& rhs)noexcept { move(std::move(rhs)); }

	public:
		std::string getWindowTitle()const noexcept	{ return m_title; }
		int getWindowWidth()		const noexcept	{ return m_width; }
		int getWindowHeight()		const noexcept	{ return m_height; }
		std::pair<int, int> getWindowDiamensions()	const	{return std::make_pair(m_width,m_height); }

	private:
		void move(window&& rhs);

	private:
		std::string m_title = "untitledWindow";
		int m_width  = 0;
		int m_height = 0;

		GLFWwindow* m_winPtr = nullptr;
	};
}