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

	public:
		template<typename... args>
		static void write(consoleLog logObj,int level,args... logToWrite)
		{
			switch (level)
			{
			case 0: logObj.m_handle->trace(logToWrite...);
				break;
			case 1: logObj.m_handle->info(logToWrite...);
				break;
			case 2: logObj.m_handle->warn(logToWrite...);
				break;
			case 3: logObj.m_handle->error(logToWrite...);
				break;
			case 4: logObj.m_handle->critical(logToWrite...);
				break;
			default:
				logObj.m_handle->critical("logger level is not as expected unable to log at chosen level defaulting to error..");
				logObj.m_handle->error(logToWrite...);
				break;
			}
		}
	private:
		std::shared_ptr<spdlog::logger> m_handle = nullptr;
	};

	class fileLog
	{
	public:
		fileLog();
		operator std::shared_ptr<spdlog::logger>() { return m_handle; };
		std::shared_ptr<spdlog::logger> get() { return m_handle; };

	public:
		template<typename... args>
		static void write(fileLog logObj,int level,args... logToWrite)
		{
			switch (level)
			{
			case 0:  logObj.m_handle->trace(logToWrite...);
					 logObj.m_trace_handle->trace(logToWrite...);
				break;

			case 1:  logObj.m_handle->info(logToWrite...);
					 logObj.m_info_handle->info(logToWrite...);
				break;
			case 2:  logObj.m_handle->warn(logToWrite...);
					 logObj.m_warn_handle->warn(logToWrite...);
				break;
			case 3:  logObj.m_handle->error(logToWrite...);
					 logObj.m_error_handle->error(logToWrite...);
				break;
			case 4:  logObj.m_handle->critical(logToWrite...);
					 logObj.m_critical_handle->critical(logToWrite...);
				break;
			default: logObj.m_handle->critical("logger level is not as expected unable to log at chosen level defaulting to error..");
					 logObj.m_handle->error(logToWrite...);

					 logObj.m_unclassified_handle->error(logToWrite...);
				break;
			}
		}
	private:
		std::shared_ptr<spdlog::logger> m_handle = nullptr; //this is the global file to which all logs are to be written..
		
		std::shared_ptr<spdlog::logger> m_trace_handle		= nullptr;
		std::shared_ptr<spdlog::logger> m_info_handle			= nullptr;
		std::shared_ptr<spdlog::logger> m_warn_handle			= nullptr;
		std::shared_ptr<spdlog::logger> m_error_handle		= nullptr;
		std::shared_ptr<spdlog::logger> m_critical_handle		= nullptr;
		std::shared_ptr<spdlog::logger> m_unclassified_handle = nullptr;
	};

	class log
	{
	public:
		static consoleLog getConsoleLogger();
		static fileLog getFileLogger();
	};
}

#if defined(PE_DEBUG)
	#define logConsole(level,...)	penguin2D::consoleLog::write(penguin2D::log::getConsoleLogger(),level,__VA_ARGS__);
	#define logFile(level,...)		penguin2D::fileLog::write(penguin2D::log::getFileLogger(),level,__VA_ARGS__);
	
	#define log(level,...)			penguin2D::consoleLog::write(penguin2D::log::getConsoleLogger(),level,__VA_ARGS__);\
									penguin2D::fileLog::write(penguin2D::log::getFileLogger()   ,level, __VA_ARGS__);

#else
#define consoleLog(level,...)		
#define fileLog(level,...)			
#define log(level,...)
#endif 