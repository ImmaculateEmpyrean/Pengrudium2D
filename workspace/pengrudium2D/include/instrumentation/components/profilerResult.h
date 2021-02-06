#pragma once
#include <string>
#include <chrono>
#include <algorithm>
#include <fstream>

namespace penguin2D
{
    namespace instrumentation
    {
        struct profileResult
        {
            std::string m_name;
            long long m_startPoint;
            long long m_endPoint;
            uint32_t  m_threadID;
        };
    }
}