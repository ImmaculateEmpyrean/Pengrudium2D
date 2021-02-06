#pragma once
#include<iostream>
#include<vector>
#include<string>

#include "instrumentation/instrumentation.h"

namespace penguin2D
{
#define PROFILER_NEWSESSION(name,filepath) penguin2D::instrumentation::instrumentor::get().beginSession(std::string(name),std::filesystem::path(filepath));
#define PROFILER_ENDSESSION() penguin2D::instrumentation::instrumentor::get().endSession();

//start helper macros
#define variableName #time
#define varline variableName __LINE__
//ended helper macros

#define PROFILER_TIME_FUNCTION penguin2D::instrumentation::instrumentationTimer varLine(__FUNCSIG__);
#define PROFILER_TIME_SCOPE(name) penguin2D::instrumentation::instrumentationTimer varLine(name);
}