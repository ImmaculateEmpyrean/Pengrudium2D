project "GLFW"
    kind "StaticLib"
    language "c"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "glfw-3.3.2/include/GLFW/glfw3.h",
        "glfw-3.3.2/include/GLFW/glfw3native.h",
        "glfw-3.3.2/src/glfw_config.h",
		"glfw-3.3.2/src/context.c",
		"glfw-3.3.2/src/init.c",
		"glfw-3.3.2/src/input.c",
		"glfw-3.3.2/src/monitor.c",
		"glfw-3.3.2/src/vulkan.c",
		"glfw-3.3.2/src/window.c"
    }

    defines{
    	"_CRT_SECURE_NO_WARNINGS"
    }

    includedirs { 
        "glfw-3.3.2/include/",
        "glfw-3.3.2/src/"
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
            "PEngine_BUILDING_FOR_WINDOWS", 
            "_GLFW_WIN32" -- use the windows api to draw the window and other stuff says this macro..
        }
        files
		{
			"glfw-3.3.2/src/win32_init.c",
			"glfw-3.3.2/src/win32_joystick.c",
			"glfw-3.3.2/src/win32_monitor.c",
			"glfw-3.3.2/src/win32_time.c",
			"glfw-3.3.2/src/win32_thread.c",
			"glfw-3.3.2/src/win32_window.c",
			"glfw-3.3.2/src/wgl_context.c",
			"glfw-3.3.2/src/egl_context.c",
			"glfw-3.3.2/src/osmesa_context.c"
		}
        
    filter "system:windows"
        systemversion "latest"

        defines{
            "PEngine_BUILDING_ON_WINDOWS"
        }