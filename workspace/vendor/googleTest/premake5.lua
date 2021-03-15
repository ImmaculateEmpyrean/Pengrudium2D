project "googletest" -- a good enough project name for the project which literally is the engine
    kind "StaticLib"   -- the archietecture goes something like, engine will be linked to any game which wants to use it statically there is no good reason to go dll.
    language "C++" 
    cppdialect "C++17" -- better go with the best fully supported standrad for c++ as of this writing.

    targetdir ("../../bin/"..outputdir.."/%{prj.name}")
    objdir    ("../../bin-int/"..outputdir.."/%{prj.name}")

    files{
        "googletest/gtest/**.h",
        "googletest/src/**.h",
        "googletest/src/**.cc"
    }

    defines{
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs {
        "googletest"
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