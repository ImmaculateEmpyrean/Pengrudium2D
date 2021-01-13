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
		consoleLog(const std::string& logName);

	public:
		std::shared_ptr<spdlog::logger> m_log_handle = nullptr;
	};

	class fileLog
	{
	public:
		fileLog(const std::string& logName);
	
	public:
		std::shared_ptr<spdlog::logger> m_log_handle = nullptr; //this is the global file to which all logs are to be written..
		
		std::shared_ptr<spdlog::logger> m_log_trace_handle		= nullptr;
		std::shared_ptr<spdlog::logger> m_log_info_handle			= nullptr;
		std::shared_ptr<spdlog::logger> m_log_warn_handle			= nullptr;
		std::shared_ptr<spdlog::logger> m_log_error_handle		= nullptr;
		std::shared_ptr<spdlog::logger> m_log_critical_handle		= nullptr;
	};

	class log
	{
	public:
		static consoleLog getConsoleLoggerEngine();
		static consoleLog getConsoleLoggerEditor();
		static consoleLog getConsoleLoggerExecutable();
		static consoleLog getConsoleLoggerTest();
		static consoleLog getConsoleLoggerExample();

		static fileLog getFileLoggerEngine();
		static fileLog getFileLoggerEditor();
		static fileLog getFileLoggerExecutable();
		static fileLog getFileLoggerTest();
		static fileLog getFileLoggerExample();
	};
}

#if defined(PEngine_DEBUG)
	#define logConsoleTrace(...)	penguin2D::log::getConsoleLoggerEngine().m_log_handle->trace	(__VA_ARGS__);
	#define logConsoleInfo(...)		penguin2D::log::getConsoleLoggerEngine().m_log_handle->info		(__VA_ARGS__);
	#define logConsoleWarn(...)		penguin2D::log::getConsoleLoggerEngine().m_log_handle->warn		(__VA_ARGS__);
	#define logConsoleError(...)	penguin2D::log::getConsoleLoggerEngine().m_log_handle->error	(__VA_ARGS__);
	#define logConsoleCritical(...)	penguin2D::log::getConsoleLoggerEngine().m_log_handle->critical (__VA_ARGS__);


	#define logFileTrace(...)		penguin2D::log::getFileLoggerEngine().m_log_trace_handle()->trace(__VA_ARGS__);
	#define logFileInfo(...)		penguin2D::log::getFileLoggerEngine().m_log_info_handle()->trace(__VA_ARGS__);
	#define logFileWarn(...)		penguin2D::log::getFileLoggerEngine().m_log_warn_handle()->trace(__VA_ARGS__);
	#define logFileError(...)		penguin2D::log::getFileLoggerEngine().m_log_error_handle()->trace(__VA_ARGS__);
	#define logFileCritical(...)	penguin2D::log::getFileLoggerEngine().m_log_critical_handle()->trace(__VA_ARGS__);


	#define logTrace(...)			logConsoleTrace(__VA_ARGS__);\
									logFileTrace(__VA_ARGS__);
									

	#define logInfo(...)			logConsoleInfo(__VA_ARGS__);\
									logFileInfo(__VA_ARGS__);

	#define logWarn(...)			logConsoleWarn(__VA_ARGS__);\
									logFileWarn(__VA_ARGS__);

	#define logError(...)			logConsoleError(__VA_ARGS__);\
									logFileError(__VA_ARGS__);

	#define logCritical(...)		logConsoleCritical(__VA_ARGS__);\
									logFileCritical(__VA_ARGS__);
												
#elif defined(PEditor_DEBUG)
#define logConsoleTrace(...)	penguin2D::log::getConsoleLoggerEditor().m_log_handle->trace	(__VA_ARGS__);
#define logConsoleInfo(...)		penguin2D::log::getConsoleLoggerEditor().m_log_handle->info		(__VA_ARGS__);
#define logConsoleWarn(...)		penguin2D::log::getConsoleLoggerEditor().m_log_handle->warn		(__VA_ARGS__);
#define logConsoleError(...)	penguin2D::log::getConsoleLoggerEditor().m_log_handle->error	(__VA_ARGS__);
#define logConsoleCritical(...)	penguin2D::log::getConsoleLoggerEditor().m_log_handle->critical (__VA_ARGS__);


#define logFileTrace(...)		penguin2D::log::getFileLoggerEditor().m_log_trace_handle()->trace(__VA_ARGS__);
#define logFileInfo(...)		penguin2D::log::getFileLoggerEditor().m_log_info_handle()->trace(__VA_ARGS__);
#define logFileWarn(...)		penguin2D::log::getFileLoggerEditor().m_log_warn_handle()->trace(__VA_ARGS__);
#define logFileError(...)		penguin2D::log::getFileLoggerEditor().m_log_error_handle()->trace(__VA_ARGS__);
#define logFileCritical(...)	penguin2D::log::getFileLoggerEditor().m_log_critical_handle()->trace(__VA_ARGS__);


#define logTrace(...)			logConsoleTrace(__VA_ARGS__);\
									logFileTrace(__VA_ARGS__);


#define logInfo(...)			logConsoleInfo(__VA_ARGS__);\
									logFileInfo(__VA_ARGS__);

#define logWarn(...)			logConsoleWarn(__VA_ARGS__);\
									logFileWarn(__VA_ARGS__);

#define logError(...)			logConsoleError(__VA_ARGS__);\
									logFileError(__VA_ARGS__);

#define logCritical(...)		logConsoleCritical(__VA_ARGS__);\
									logFileCritical(__VA_ARGS__);

#elif defined(PExecutable_DEBUG)
#define logConsoleTrace(...)	penguin2D::log::getConsoleLoggerExecutable().m_log_handle->trace	(__VA_ARGS__);
#define logConsoleInfo(...)		penguin2D::log::getConsoleLoggerExecutable().m_log_handle->info		(__VA_ARGS__);
#define logConsoleWarn(...)		penguin2D::log::getConsoleLoggerExecutable().m_log_handle->warn		(__VA_ARGS__);
#define logConsoleError(...)	penguin2D::log::getConsoleLoggerExecutable().m_log_handle->error	(__VA_ARGS__);
#define logConsoleCritical(...)	penguin2D::log::getConsoleLoggerExecutable().m_log_handle->critical (__VA_ARGS__);


#define logFileTrace(...)		penguin2D::log::getFileLoggerExecutable().m_log_trace_handle()->trace(__VA_ARGS__);
#define logFileInfo(...)		penguin2D::log::getFileLoggerExecutable().m_log_info_handle()->trace(__VA_ARGS__);
#define logFileWarn(...)		penguin2D::log::getFileLoggerExecutable().m_log_warn_handle()->trace(__VA_ARGS__);
#define logFileError(...)		penguin2D::log::getFileLoggerExecutable().m_log_error_handle()->trace(__VA_ARGS__);
#define logFileCritical(...)	penguin2D::log::getFileLoggerExecutable().m_log_critical_handle()->trace(__VA_ARGS__);


#define logTrace(...)			logConsoleTrace(__VA_ARGS__);\
									logFileTrace(__VA_ARGS__);


#define logInfo(...)			logConsoleInfo(__VA_ARGS__);\
									logFileInfo(__VA_ARGS__);

#define logWarn(...)			logConsoleWarn(__VA_ARGS__);\
									logFileWarn(__VA_ARGS__);

#define logError(...)			logConsoleError(__VA_ARGS__);\
									logFileError(__VA_ARGS__);

#define logCritical(...)		logConsoleCritical(__VA_ARGS__);\
									logFileCritical(__VA_ARGS__);

#elif defined(PTest_DEBUG)
#define logConsoleTrace(...)	penguin2D::log::getConsoleLoggerTest().m_log_handle->trace		(__VA_ARGS__);
#define logConsoleInfo(...)		penguin2D::log::getConsoleLoggerTest().m_log_handle->info		(__VA_ARGS__);
#define logConsoleWarn(...)		penguin2D::log::getConsoleLoggerTest().m_log_handle->warn		(__VA_ARGS__);
#define logConsoleError(...)	penguin2D::log::getConsoleLoggerTest().m_log_handle->error		(__VA_ARGS__);
#define logConsoleCritical(...)	penguin2D::log::getConsoleLoggerTest().m_log_handle->critical	(__VA_ARGS__);


#define logFileTrace(...)		penguin2D::log::getFileLoggerTest().m_log_trace_handle()->trace(__VA_ARGS__);
#define logFileInfo(...)		penguin2D::log::getFileLoggerTest().m_log_info_handle()->trace(__VA_ARGS__);
#define logFileWarn(...)		penguin2D::log::getFileLoggerTest().m_log_warn_handle()->trace(__VA_ARGS__);
#define logFileError(...)		penguin2D::log::getFileLoggerTest().m_log_error_handle()->trace(__VA_ARGS__);
#define logFileCritical(...)	penguin2D::log::getFileLoggerTest().m_log_critical_handle()->trace(__VA_ARGS__);


#define logTrace(...)			logConsoleTrace(__VA_ARGS__);\
									logFileTrace(__VA_ARGS__);


#define logInfo(...)			logConsoleInfo(__VA_ARGS__);\
									logFileInfo(__VA_ARGS__);

#define logWarn(...)			logConsoleWarn(__VA_ARGS__);\
									logFileWarn(__VA_ARGS__);

#define logError(...)			logConsoleError(__VA_ARGS__);\
									logFileError(__VA_ARGS__);

#define logCritical(...)		logConsoleCritical(__VA_ARGS__);\
									logFileCritical(__VA_ARGS__);
#elif defined(PExample_DEBUG)
#define logConsoleTrace(...)	penguin2D::log::getConsoleLoggerExample().m_log_handle->trace	 (__VA_ARGS__);
#define logConsoleInfo(...)		penguin2D::log::getConsoleLoggerExample().m_log_handle->info	 (__VA_ARGS__);
#define logConsoleWarn(...)		penguin2D::log::getConsoleLoggerExample().m_log_handle->warn	 (__VA_ARGS__);
#define logConsoleError(...)	penguin2D::log::getConsoleLoggerExample().m_log_handle->error	 (__VA_ARGS__);
#define logConsoleCritical(...)	penguin2D::log::getConsoleLoggerExample().m_log_handle->critical (__VA_ARGS__);


#define logFileTrace(...)		penguin2D::log::getFileLoggerExample().m_log_trace_handle()->trace(__VA_ARGS__);
#define logFileInfo(...)		penguin2D::log::getFileLoggerExample().m_log_info_handle()->trace(__VA_ARGS__);
#define logFileWarn(...)		penguin2D::log::getFileLoggerExample().m_log_warn_handle()->trace(__VA_ARGS__);
#define logFileError(...)		penguin2D::log::getFileLoggerExample().m_log_error_handle()->trace(__VA_ARGS__);
#define logFileCritical(...)	penguin2D::log::getFileLoggerExample().m_log_critical_handle()->trace(__VA_ARGS__);


#define logTrace(...)			logConsoleTrace(__VA_ARGS__);\
									logFileTrace(__VA_ARGS__);


#define logInfo(...)			logConsoleInfo(__VA_ARGS__);\
									logFileInfo(__VA_ARGS__);

#define logWarn(...)			logConsoleWarn(__VA_ARGS__);\
									logFileWarn(__VA_ARGS__);

#define logError(...)			logConsoleError(__VA_ARGS__);\
									logFileError(__VA_ARGS__);

#define logCritical(...)		logConsoleCritical(__VA_ARGS__);\
									logFileCritical(__VA_ARGS__);
#else
#define logConsole(level,...) //log replaced with nothing as no relevant symbol was found..
#define logFile(level,...)	  //log replaced with nothing as no relevant symbol was found..		

#define log(level,...)		  //log replaced with nothing as no relevant symbol was found..
#endif 