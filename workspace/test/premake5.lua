workspace "pengrudium2DTests"
    architecture "x86_64"
    startproject "pengrudium2D"

    configurations{
        "debug",  --this is supposed to be the          debug version of all three namely the editor,engine and game.
        "release" --this is supposed to be the shipping ready version of all three namely the editor,engine and game.
    }

    platforms{
        "Windows" --the default platform is windows, possibly android will be supported in the near future
    }

    flags{
        "MultiprocessorCompile" --Enable Visual Studio to use multiple compiler processes when building. -from https://github.com/premake/premake-core/wiki/flags
    }

    --the output directory for the generated executable is set using this variable "TODO make this possible to be input by the user."
    outputdir = "%{cfg.buildcfg}-%{cfg.platform}-%{cfg.system}-%{cfg.architecture}"

    --a map to store all include directory paths which we wish to make the compiler lookat.
    IncludeDir = {}
    IncludeDir["pengrudium2D"]  = "%{wks.location}/../pengrudium2D/include" -- use this to access the header files associated to pengrudium2D project(the meat of this initiative). more easily.
    IncludeDir["spdlog"]        = "%{wks.location}/../vendor/spdlog/spdlog-1.8.2/include" -- use this to access the header files associated to pengrudium2D project(the meat of this initiative). more easily.
    IncludeDir["entt"]          = "%{wks.location}/../vendor/entt/entt-3.6.0/entt" -- use this to access the header files associated to pengrudium2D project(the meat of this initiative). more easily.
    IncludeDir["nlohmannJson"]  = "%{wks.location}/../vendor/nlohmannJson/nlohmann-3.9.1"
    IncludeDir["glm"]           = "%{wks.location}/../vendor/glm/glm-0.9.9.8"
    IncludeDir["stduuid"]       = "%{wks.location}/../vendor/stduuid/stduuid-1.0/include"
    IncludeDir["googletest"]	= "%{wks.location}/../vendor/googleTest/googletest"
    
    --the grouping refers to all the projects generated using third party source code.
    group "vendor"
    	include "../vendor/googleTest"
    group ""

    --this is the engine that is to be tested
   externalproject "pengrudium2D"
   	location "../pengrudium2D"
   	uuid "57940020-8E99-AEB6-271F-61E0F7F6B73B"
   	kind "StaticLib"
   	language "C++"

    --the tests included must have their own premake5.lua file in their own folder..
    include "logTest"
    include "googletestDummy"