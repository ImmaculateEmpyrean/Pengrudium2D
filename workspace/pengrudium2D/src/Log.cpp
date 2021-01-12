#include "stdafx.h"
#include "Log.h"




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

		m_handle = spdlog::basic_logger_mt("defaultFileLogger", "log.txt");
		m_handle->set_level(spdlog::level::trace);
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