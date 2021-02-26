project "editor" -- a good enough project name for the project which literally is the engine
    kind "ConsoleApp"
    language "C++" 
    cppdialect "C++17" -- better go with the best fully supported standrad for c++ as of this writing.
    
    targetdir ("../bin/"..outputdir.."/%{prj.name}")
    objdir    ("../bin-int/"..outputdir.."/%{prj.name}")

    pchheader "stdafx.h"
    pchsource "src/PCH/stdafx.cpp"

    files{
        "src/**.h",
        "src/**.hxx",
        "src/**.hpp",
        "src/**.cpp"
    }

    defines{
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs {
        "%{IncludeDir.pengrudium2D}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.entt}",
        "%{IncludeDir.nlohmannJson}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stduuid}",
        "src",
        "src/PCH"
    }

    links
    {
        "pengrudium2D"
    }

    filter "configurations:debug"
        defines{
          "PEditor_DEBUG"
        }
        runtime "Debug"
        symbols "on"
        buildoptions "/MTd"
        
    filter "configurations:release"
        defines{
            "PEditor_SHIP"
        }
        runtime "Release"
        optimize "on"
        buildoptions "/MT"
    
    filter "platforms:Windows"
        defines{
            "PEditor_BUILDING_FOR_WINDOWS"
        }
        
    filter "system:windows"
        systemversion "latest"

        defines{
            "PEditor_BUILDING_ON_WINDOWS"
        }