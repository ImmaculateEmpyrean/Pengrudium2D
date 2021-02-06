#pragma once
#include<string>
#include<chrono>
#include<thread>

#include "Instrumentor.h"

namespace penguin2D {
    namespace instrumentation {
        class instrumentationTimer
        {
        public:
            instrumentationTimer(const std::string& name);
            ~instrumentationTimer();

            void stop();

        private:
            std::string m_name = "noName";
            std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimepoint;
            bool m_stopped =false;
        };
    }
}