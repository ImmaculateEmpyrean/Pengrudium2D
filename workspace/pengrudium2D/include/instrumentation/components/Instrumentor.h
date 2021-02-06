#pragma once
#include <string>
#include <stack>
#include <chrono>

#include <fstream>
#include <filesystem>

#include "nlohmann/json.hpp"
#include "profilerResult.h"
#include "instrumentationSession.h"

namespace penguin2D {
    namespace instrumentation {
        class instrumentor
        {
        public:
            instrumentor()  = default;
            ~instrumentor() = default;

            void beginSession(const std::string& name, const std::filesystem::path& filepath = "results.json");
            void endSession();

            void initializeFile();
            void writeProfile(const profileResult& result);

            void flushToFile();

            static instrumentor& get();
        };
    }
}