#include "stdafx.h"
#include "core/window.h"

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<imgui.h>
#include"imgui_impl_opengl3.h"
#include"imgui_impl_glfw.h"

namespace penguin2D
{
	window::window(std::string title, int width, int height)
		: m_title(title), m_width(width), m_height(height)
	{
		if (!glfwInit())
		{
			logConsoleCritical("glfw initialization failed quitting program");
			exit(-1);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_winPtr = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
		if (!m_winPtr)
		{
			logConsoleCritical("window creation failed, quitting program");
			glfwTerminate();
			exit(-1);
		}

		glfwMakeContextCurrent(m_winPtr);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			logConsoleCritical("failed to initialize glad, quitting program");
			glfwTerminate();
			exit(-1);
		}


		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		auto io = &ImGui::GetIO();
		io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(m_winPtr, true);
		ImGui_ImplOpenGL3_Init("#version 130");

		logConsoleInfo("initialized window successfully");
		logConsoleInfo("graphic card in usuage : {}", glGetString(GL_VENDOR));
		logConsoleInfo("opengl renderer in use : {}", glGetString(GL_RENDERER));
		logConsoleInfo("GLSL version : {}", glGetString(GL_SHADING_LANGUAGE_VERSION));
		logConsoleInfo("GL   version : {}", glGetString(GL_VERSION));
	}
	window::~window()
	{
		if (m_winPtr != nullptr)
		{
			glfwDestroyWindow(m_winPtr);
			m_winPtr = nullptr;
		}
	}

	void window::move(window&& rhs)
	{
		m_title = std::move(rhs.m_title);
		m_width = std::move(rhs.m_width);
		m_height = std::move(rhs.m_height);

		m_winPtr = rhs.m_winPtr;
		rhs.m_winPtr = nullptr;
	}


	void window::preNewFrameProcess()
	{

	}
	void window::postNewFrameProcess()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(m_winPtr);
		glfwPollEvents();
	}
}