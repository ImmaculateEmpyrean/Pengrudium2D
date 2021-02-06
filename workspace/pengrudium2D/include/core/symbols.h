#pragma once
#include<iostream>
#include<vector>
#include<string>

#include "instrumentation/instrumentation.h"

namespace penguin2D
{
#define PROFILER_NEWSESSION(name,filepath) penguin2D::instrumentation::instrumentor::get().beginSession(std::string(name),std::filesystem::path(filepath));
#define PROFILER_ENDSESSION() penguin2D::instrumentation::instrumentor::get().endSession();
#define PROFILER_TIME_FUNCTION() penguin2D::instrumentation::instrumentationTimer::instrumentationTimer(__FUNCSIG__);
#define PROFILER_TIME_SCOPE(name) penguin2D::instrumentation::instrumentationTimer::instrumentationTimer(name);
}