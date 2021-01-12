project "pengrudium2D" -- a good enough project name for the project which literally is the engine
    kind "StaticLib"   -- the archietecture goes something like, engine will be linked to any game which wants to use it statically there is no good reason to go dll.
    language "C++" 
    cppdialect "C++17" -- better go with the best fully supported standrad for c++ as of this writing.

    targetdir ("../bin/"..outputdir.."/%{prj.name}")
    objdir    ("../bin-int/"..outputdir.."/%{prj.name}")

    pchheader "stdafx.h"
    pchsource "src/PCH/stdafx.cpp"

    files{
        "include/**.h",
        "include/**.hpp",
        "include/**.hxx",
        "src/**.cpp"
    }

    defines{
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs {
        "%{IncludeDir.pengrudium2D}",
        "%{IncludeDir.spdlog}",
        "src/PCH"
    }

    filter "configurations:debug"
        defines{
          "PE_DEBUG"
        }
        runtime "Debug"
        symbols "on"
        buildoptions "/MTd"
        
    filter "configurations:release"
        defines{
            "PE_SHIP"
        }
        runtime "Release"
        optimize "on"
        buildoptions "/MT"
    
    filter "platforms:Windows"
        defines{
            "PE_BUILDING_FOR_WINDOWS"
        }
        
    filter "system:windows"
        systemversion "latest"

        defines{
            "PE_BUILDING_ON_WINDOWS"
        }