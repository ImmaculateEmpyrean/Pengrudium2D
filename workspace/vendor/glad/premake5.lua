project "glad"
    kind "StaticLib"
    language "c"
    staticruntime "on"

    targetdir("../../bin/"  .. outputdir .. "/%{prj.name}")
    objdir("../../bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "glad/src/glad.c",
        "glad/include/khr/khrplatform.h",
        "glad/include/glad/glad.h"
    }

    includedirs { 
        "glad/include/",
        "glad/src/"
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