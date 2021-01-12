#include "stdafx.h"

namespace penguin2D
{
	static std::once_flag logInitializerFlag;
	static void initializeLog()
	{
		spdlog::set_pattern("%^[%T] %n : %v%$");
	}

	consoleLog::consoleLog()
	{
		//call the initialize function of the library only once at the start of the program.. 
		std::call_once(logInitializerFlag, []() {
			initializeLog();
			});

		m_handle = spdlog::stdout_color_mt("default");
		m_handle->set_level(spdlog::level::trace);
	}

	fileLog::fileLog()
	{
		//call the initialize function of the library only once at the start of the program..
		std::call_once(logInitializerFlag, []() {
			initializeLog();
			});

		m_handle = spdlog::basic_logger_mt("defaultFileLogger", "log/log.txt");
		m_handle->set_level(spdlog::level::trace);


		m_trace_handle = spdlog::basic_logger_mt("defaultTraceLogger",	"log/logTrace.txt");
		m_trace_handle->set_level(spdlog::level::trace);
		
		m_info_handle = spdlog::basic_logger_mt("defaultInfoLogger",		"log/logInfo.txt");
		m_info_handle->set_level(spdlog::level::info);
		
		m_warn_handle = spdlog::basic_logger_mt("defaultWarnLogger",		"log/logWarn.txt");
		m_warn_handle->set_level(spdlog::level::warn);
		
		m_error_handle = spdlog::basic_logger_mt("defaultErrorLogger",	"log/logError.txt");
		m_error_handle->set_level(spdlog::level::err);
		
		m_critical_handle = spdlog::basic_logger_mt("defaultCriticalLogger", "log/logCritical.txt");
		m_critical_handle->set_level(spdlog::level::critical);


		m_unclassified_handle = spdlog::basic_logger_mt("defaultUnspecifiedLogger", "log/logUnspecified.txt");
		m_unclassified_handle->set_level(spdlog::level::err);
	}
	

	consoleLog log::getConsoleLogger()
	{
		static consoleLog cLog;
		return cLog;
	}

	fileLog log::getFileLogger()
	{
		static fileLog fLog;
		return fLog;
	}
}