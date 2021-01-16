@mainpage  UserGuide For Getting Started Using The Engine
@tableofcontents

@section GettingStarted
## To Get Started Using The Engine
* Download or clone the repository from this github [Page](https://github.com/ImmaculateEmpyrean/pengrudium2D)
* The tools folder is located in the root directory downloaded from github.
* Run the generateSolution.bat script inside the folder tools
* Once the script executes successfully it should have generated three different    solution files. (visual studio 2019 solution files if you are on windows).
* The three solution files are located in the directories -
    * workspace/devPengrudium2D.sln
    * workspace/test/pengrudium2DTests.sln
    * workspace/example/pengrudium2DExamples.sln
    
@section Brief explanations on the solution files and their structure
## Roles Of The Various Solution Files
* the workspace/devPengrudium2D.sln is the main solution file you must consider using as it is intended for developing the engine or something with the engine. 
  * the editor project inside this solution contains an editor intended to be used for development of games using this engine.
  * the pengrudium2D project inside this solution contains is the actual engine. as of now it only compiles into a static lib with all the required symbols inside it.
  there is no need to explicitly link any other dependency to this lib file. all dependencies are compiled and placed into the engine's lib file automatically when the engine is being compiled. ``please see the section on the symbols expected in your executable if you are using some other executable and not sandbox.``
  * the sandbox project is an executable already setup to allow for shipping of the game. it should serve as a reference for your own executable and you donot want to use this as your executable without careful consideration. ``even when a new project is being started which solely depends on this engine, there is still atleast one good reason to NOT use this project as new updates to the engine may cause merge conflicts because someone somewhere tweaked the sandbox project a little.``

* The workspace workspace/test/pengrudium2DTests.sln contains all the project associated with testing some module of the engine. ``this solution can also serve as examples but the engine is way too barebones to say anything with certainity.``

* The workspace workspace/example/pengrudium2DExamples contains all the projects associated with providing the user some working examples on the best practices of coding with the engine.

@section structure of the project
## Compile The Engine And Get It Running 
* the engine is compiled as a static library and can be included in any executable of your choosing.
* compile the engine using the solution devPengrudium2D the engine incorporates in it all the necessary dependencies in its one lib file.
* the header files are a different matter entirely.
  * the engines header files can be grabbed from the include directory located in the path workspace\pengrudium2D\include
  * the spdlog header files can be grabbed from the path workspace\vendor\spdlog\spdlog-1.8.2\include
  * ``the most upto date list of what header files to be grabbed is always stored in the premake5.lua file available in the path workspace\pengrudium2D\premake5.lua``
    * it is fairly easy to locate which are the header files required - simply take a look at the includedirs entry in the file. then search for the keys present there in the main lua file located in the path workspace/premake5.lua.      

@section Symbols expected to be defined in the executable by the engine 

## Symbols expected to be defined in the executable by the engine