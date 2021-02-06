#include "stdafx.h"
#include "instrumentation/components/instrumentationTimer.h"

using namespace penguin2D;
using namespace instrumentation;


instrumentationTimer::instrumentationTimer(const std::string& name)
	: m_name(name), m_stopped(false)
{
	m_startTimepoint = std::chrono::high_resolution_clock::now();
}
instrumentationTimer::~instrumentationTimer()
{
    if (!m_stopped)
        stop();
}


void instrumentationTimer::stop()
{
    auto endTimepoint = std::chrono::high_resolution_clock::now();

    long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimepoint).time_since_epoch().count();
    long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

    uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
    instrumentor::get().writeProfile({ m_name, start, end, threadID });

    m_stopped = true;
}