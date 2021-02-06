#include "stdafx.h"
#include "instrumentation/components/Instrumentor.h"

using namespace penguin2D;
using namespace instrumentation;


//global variables
static std::stack<penguin2D::instrumentation::instrumentationSession> sessionStack;

void instrumentor::beginSession(const std::string& name, const std::filesystem::path& filepath)
{
    sessionStack.push({name, filepath});
}
void instrumentor::endSession()
{
    flushToFile();
    sessionStack.pop();
}


void instrumentor::initializeFile()
{
    sessionStack.top().m_jsonFile["otherData"] = "";
    sessionStack.top().m_jsonFile["traceEvents"] = nlohmann::json::array();
}
void instrumentor::writeProfile(const profileResult& result)
{
    std::string profileResultName = result.m_name;

    nlohmann::json profilerEvent = nlohmann::json::object();
    profilerEvent["cat"]  = "function";
    profilerEvent["dur"]  = (result.m_endPoint - result.m_startPoint);
    profilerEvent["name"] = profileResultName;
    profilerEvent["ph"] = "X";
    profilerEvent["pid"] = 0;
    profilerEvent["tid"] = result.m_threadID;
    profilerEvent["ts"] = result.m_startPoint;
    
    sessionStack.top().m_jsonFile["traceEvents"].push_back(profilerEvent);
}
void instrumentor::flushToFile()
{
    if (sessionStack.size() >= 0)
    {
        std::ofstream file(sessionStack.top().outputFilePath,std::ios::trunc);
        sessionStack.top().m_jsonFile >> file;
        file.close();
    }
    else
        logConsoleError("cannot write instrumentation data to file as m_currentSession is not set")
}


instrumentor& instrumentor::get()
{
    static instrumentor inst;
    return inst;
}