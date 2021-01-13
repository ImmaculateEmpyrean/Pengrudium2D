project "logTest" -- a good enough project name for the project which literally is the engine
    kind "ConsoleApp"
    language "C++" 
    cppdialect "C++17" -- better go with the best fully supported standrad for c++ as of this writing.

    targetdir ("../bin/"..outputdir.."/%{prj.name}")
    objdir    ("../bin-int/"..outputdir.."/%{prj.name}")

    pchheader "stdafx.h"
    pchsource "src/PCH/stdafx.cpp"

    files{
        "src/**.hpp",
        "src/**.hxx",
        "src/**.h",
        "src/**.cpp",
    }

    defines{
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs {
        "%{IncludeDir.pengrudium2D}",
        "%{IncludeDir.spdlog}",
        "src/PCH"
    }

    links{
        "pengrudium2D"
    }

    filter "configurations:debug"
        defines{
          "PTest_DEBUG"
        }
        runtime "Debug"
        symbols "on"
        buildoptions "/MTd"
        
    filter "configurations:release"
        defines{
            "PTest_SHIP"
        }
        runtime "Release"
        optimize "on"
        buildoptions "/MT"
    
    filter "platforms:Windows"
        defines{
            "P_TEST_BUILDING_FOR_WINDOWS"
        }
        
    filter "system:windows"
        systemversion "latest"

        defines{
            "P_TEST_BUILDING_ON_WINDOWS"
        }