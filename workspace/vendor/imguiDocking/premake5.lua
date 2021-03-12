project "imgui"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("../../"..outputdir.."/%{prj.name}")
	objdir ("../../bin-int/"..outputdir.."/%{prj.name}")

	files
	{
		"imconfig.h",
		"imgui.h",
		"imgui.cpp",
		"imgui_draw.cpp",
		"imgui_internal.h",
		"imgui_widgets.cpp",
		"imstb_rectpack.h",
		"imstb_textedit.h",
		"imstb_truetype.h",
		"imgui_demo.cpp"
	}

	includedir {
		"imgui"
	}

	 filter "configurations:debug"
        defines{
          "PEngine_DEBUG"
        }
        runtime "Debug"
        symbols "on"
        buildoptions "/MTd"
        
    filter "configurations:release"
        defines{
            "PEngine_SHIP"
        }
        runtime "Release"
        optimize "on"
        buildoptions "/MT"
    
    filter "platforms:Windows"
        defines{
            "PEngine_BUILDING_FOR_WINDOWS"
        }
        
    filter "system:windows"
        systemversion "latest"

        defines{
            "PEngine_BUILDING_ON_WINDOWS"
        }