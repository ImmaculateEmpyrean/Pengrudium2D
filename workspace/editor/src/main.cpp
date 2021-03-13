#include "stdafx.h"
#include "core/entryPoint.h"

# include <imgui.h>
# define IMGUI_DEFINE_MATH_OPERATORS
# include <imgui_internal.h>
# include <imgui_node_editor.h>

using namespace penguin2D;
namespace ed = ax::NodeEditor;

class editorApp : public app
{
public:
	editorApp()
		: app("penguin2D editor", 1280, 720)
	{
		config.SettingsFile = "demoConfigSettings.json";
		g_Context = ed::CreateEditor(&config);
	}

    void drawBasicNode(int& uniqueId,std::string nodeName)
    {
        ed::BeginNode(uniqueId++);
        ImGui::Text(nodeName.c_str());
        ed::BeginPin(uniqueId++, ed::PinKind::Input);
        ImGui::Text("-> In");
        ed::EndPin();
        ImGui::SameLine();
        ed::BeginPin(uniqueId++, ed::PinKind::Output);
        ImGui::Text("Out ->");
        ed::EndPin();
        ed::EndNode();
    }

	void execute()
	{
        int uniqueId = 1;

        //ImGui::SetNextWindowSizeConstraints(ImVec2{ 1920.0f,1080.0f }, ImVec2{ 1920.0f,1080.0f });
        ImGui::Begin("window");
        ed::SetCurrentEditor(g_Context);
        
        ed::Begin("My Editor", ImVec2(0.0f, 0.0f));
        drawBasicNode(uniqueId, "testNode1");
        drawBasicNode(uniqueId, "testNode2");
        ed::End();

        ed::SetCurrentEditor(nullptr);
        ImGui::End();

        ImGui::ShowMetricsWindow();
	}

private:
	ed::Config config;
	ed::EditorContext* g_Context = nullptr;
};

std::unique_ptr<app> penguin2D::getStartupApp()
{
	return std::make_unique<editorApp>();
}