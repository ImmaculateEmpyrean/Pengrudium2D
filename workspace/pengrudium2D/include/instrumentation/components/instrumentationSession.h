#pragma once
#include<string>
#include<fstream>

#include<nlohmann/json.hpp>

namespace penguin2D {
    namespace instrumentation {
        struct instrumentationSession
        {
            std::string m_sessionName = "untitled session";
            std::filesystem::path outputFilePath;

            nlohmann::json m_jsonFile;
        };
    }
}