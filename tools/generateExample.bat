call generateDevelopmentEnvironment.bat

@echo off
pushd %~dp0\..\workspace\example\
call %~dp0\premake5.exe vs2019
popd
PAUSE