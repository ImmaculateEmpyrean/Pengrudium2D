project "imgui"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("../../bin/"..outputdir.."/%{prj.name}")
	objdir ("../../bin-int/"..outputdir.."/%{prj.name}")

	files
	{
		"imgui/**.h",
		"imgui/**.cpp" --consciously decided to include imgui demo.. as it will be easier to draw demo window when needed. 
	}

	includedirs {
		"imgui",
		"../glfw/glfw-3.3.2/include",
		"../glad/glad/include"
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