#pragma once
#include<string>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace penguin2D
{
	class consoleLog
	{
	public:
		consoleLog();
		operator std::shared_ptr<spdlog::logger>() { return m_handle; };
		std::shared_ptr<spdlog::logger> get() { return m_handle; };

	private:
		std::shared_ptr<spdlog::logger> m_handle = nullptr;
	};

	class fileLog
	{
	public:
		fileLog();
		operator std::shared_ptr<spdlog::logger>() { return m_handle; };
		std::shared_ptr<spdlog::logger> get() { return m_handle; };

	private:
		std::shared_ptr<spdlog::logger> m_handle = nullptr;
	};

	class log
	{
	public:
		static consoleLog getConsoleLogger();
		static fileLog getFileLogger();

		template<typename T,typename... args>
		static void write(T logObject, int level, args... logToWrite)
		{
			switch (level)
			{
			case 0: logObject.get()->trace(logToWrite...);
				break;
			case 1: logObject.get()->info(logToWrite...);
				break;
			case 2: logObject.get()->warn(logToWrite...);
				break;
			case 3: logObject.get()->error(logToWrite...);
				break;
			case 4: logObject.get()->critical(logToWrite...);
				break;
			default: logObject.get()->critical("logger level is not as expected.. using error as a fallback");
					 logObject.get()->error(logToWrite...);
				break;
			}
		}
	};
}

#if defined(PE_DEBUG)
	#define logConsole(level,...)	penguin2D::log::write	 (penguin2D::log::getConsoleLogger(),level,__VA_ARGS__);
	#define logFile(strength,...)	penguin2D::fileLog::write(penguin2D::log::getFileLogger(),level,__VA_ARGS__);
	
	#define log(strength,...)		penguin2D::log::write	 (penguin2D::log::getConsoleLogger(),level,__VA_ARGS__);\
									penguin2D::fileLog::write(penguin2D::log::getFileLogger(), level, __VA_ARGS__);

#else
#define consoleLog(strength,...)		
#define fileLog(strength,...)			
#define log(strength,...)				

#endif 