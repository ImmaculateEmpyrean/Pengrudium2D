#include "stdafx.h"
#include "engineLogTest.h"

#undef PTest_DEBUG
#define PEngine_DEBUG

#include "Log.h"

namespace engineLogCheck
{
	void performChecks()
	{
		std::cout << "testing if the log library works as intended in the engine.." << std::endl;
		{
			std::cout << "testing log console" << std::endl;
			{
				std::cout << "level 1 - " << std::endl;
				std::cout << "this test proves that the macro logConsole is indeed working" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logConsoleTrace	  ("tracing the statement");
				logConsoleInfo	  ("this statement is information");
				logConsoleWarn	  ("this is a warning to all who heed it ...");
				logConsoleError   ("this is an error hopefully you are seeing me");
				logConsoleCritical("well there is something critically wrong.. so long youll probably notice as ill likely go boom..");
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 2 - " << std::endl;
				int a = 69;
				std::cout << "this test proves that automatic indexing indeed works when using logConsole" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logConsoleTrace	  ("this is level 0 on the logConsole and i am printing an argument using automatic indexing : {}", a);
				logConsoleInfo	  ("this is level 1 on the logConsole and i am printing an argument using automatic indexing : {}", a);
				logConsoleWarn	  ("this is level 2 on the logConsole and i am printing an argument using automatic indexing : {}", a);
				logConsoleError	  ("this is level 3 on the logConsole and i am printing an argument using automatic indexing : {}", a);
				logConsoleCritical("this is level 4 on the logConsole and i am printing an argument using automatic indexing : {}", a);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 3 - " << std::endl;
				int a = 69, b = 286;
				std::cout << "this test proves that automatic indexing works when using logConsole and that some arguments can be dropped which are passed into the macro" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logConsoleTrace	  ("this is level 0 on the logConsole and i am providing more arguments than required.. : {}", a, b);
				logConsoleInfo	  ("this is level 1 on the logConsole and i am providing more arguments than required.. : {}", a, b);
				logConsoleWarn	  ("this is level 2 on the logConsole and i am providing more arguments than required.. : {}", a, b);
				logConsoleError	  ("this is level 3 on the logConsole and i am providing more arguments than required.. : {}", a, b);
				logConsoleCritical("this is level 4 on the logConsole and i am providing more arguments than required.. : {}", a, b);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 4 - " << std::endl;
				int a = 69, b = 286;
				std::cout << "this test proves that manual indexing works when using logConsole and that some arguments can be dropped which are passed into the macro" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logConsoleTrace	  ("this is level 0 on the logConsole and i am choosing which argument to print : {1}", a, b);
				logConsoleInfo	  ("this is level 1 on the logConsole and i am choosing which argument to print : {1}", a, b);
				logConsoleWarn	  ("this is level 2 on the logConsole and i am choosing which argument to print : {1}", a, b);
				logConsoleError	  ("this is level 3 on the logConsole and i am choosing which argument to print : {1}", a, b);
				logConsoleCritical("this is level 4 on the logConsole and i am choosing which argument to print : {1}", a, b);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 5 - " << std::endl;
				int a = 69, b = 286, c = 4;
				std::cout << "this test proves that manual indexing works when using logConsole" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logConsoleTrace	  ("this is level 0 on the logConsole and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				logConsoleInfo	  ("this is level 1 on the logConsole and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				logConsoleWarn	  ("this is level 2 on the logConsole and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				logConsoleError	  ("this is level 3 on the logConsole and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				logConsoleCritical("this is level 4 on the logConsole and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 6 - " << std::endl;
				char		ch = 'q';
				int			Inum = 69;
				float		Fnum = 69.0f;
				double		Dnum = 69.0;
				bool		ques = true;
				std::string str = "ria regnum";

				std::string stigma = "the only reason i exist is to prove a point..";
				std::cout << "this test proves that different arguments are indeed being printed by the logConsole using automatic indexing" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logConsoleTrace	  ("this is level 0 on logConsole and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				logConsoleInfo	  ("this is level 1 on logConsole and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				logConsoleWarn	  ("this is level 2 on logConsole and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				logConsoleError	  ("this is level 3 on logConsole and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				logConsoleCritical("this is level 4 on logConsole and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 7 - " << std::endl;
				char		ch = 'q';
				int			Inum = 69;
				float		Fnum = 69.0f;
				double		Dnum = 69.0;
				bool		ques = true;
				std::string str = "ria regnum";

				std::string stigma = "the only reason i exist is to prove a point..";
				std::cout << "this test proves that different arguments are indeed being printed by the logConsole using manual indexing" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logConsoleTrace	  ("this is level 0 on logConsole and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				logConsoleInfo	  ("this is level 1 on logConsole and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				logConsoleWarn	  ("this is level 2 on logConsole and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				logConsoleError	  ("this is level 3 on logConsole and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				logConsoleCritical("this is level 4 on logConsole and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		{
			std::cout << "testing log file" << std::endl;
			{
				std::cout << "level 1 - " << std::endl;
				std::cout << "this test proves that the macro logFile indeed works atleast barely" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logFileTrace   ("this is level 0 of the log");
				logFileInfo	   ("this is level 1 of the log");
				logFileWarn	   ("this is level 2 of the log");
				logFileError   ("this is level 3 of the log");
				logFileCritical("this is level 4 of the log");
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 2 - " << std::endl;
				int a = 69;
				std::cout << "this test proves that automatic indexing works in the macro logFile" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logFileTrace	("this is level 0 of the log and i am printing a arguments : {}", a);
				logFileInfo		("this is level 1 of the log and i am printing a arguments : {}", a);
				logFileWarn		("this is level 2 of the log and i am printing a arguments : {}", a);
				logFileError	("this is level 3 of the log and i am printing a arguments : {}", a);
				logFileCritical	("this is level 4 of the log and i am printing a arguments : {}", a);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 3 - " << std::endl;
				int a = 69, b = 286;
				std::cout << "this test proves that some elements passed can be safely dropped while using the logFile macro and automatic indexing" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logFileTrace	("this is level 0 of the log and i am providing more arguments than required.. : {}", a, b);
				logFileInfo		("this is level 1 of the log and i am providing more arguments than required.. : {}", a, b);
				logFileWarn		("this is level 2 of the log and i am providing more arguments than required.. : {}", a, b);
				logFileError	("this is level 3 of the log and i am providing more arguments than required.. : {}", a, b);
				logFileCritical	("this is level 4 of the log and i am providing more arguments than required.. : {}", a, b);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 4 - " << std::endl;
				int a = 69, b = 286;
				std::cout << "this test proves that some elements passed can be safely dropped while using the logFile macro and manual indexing" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logFileTrace	("this is level 0 of the log and i am choosing which argument to print : {1}", a, b);
				logFileInfo		("this is level 1 of the log and i am choosing which argument to print : {1}", a, b);
				logFileWarn		("this is level 2 of the log and i am choosing which argument to print : {1}", a, b);
				logFileError	("this is level 3 of the log and i am choosing which argument to print : {1}", a, b);
				logFileCritical	("this is level 4 of the log and i am choosing which argument to print : {1}", a, b);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 5 - " << std::endl;
				int a = 69, b = 286, c = 4;
				std::cout << "this test proves that manual indexing works when using logFile" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logFileTrace	("this is level 0 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				logFileInfo		("this is level 1 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				logFileWarn		("this is level 2 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				logFileError	("this is level 3 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				logFileCritical	("this is level 4 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 6 - " << std::endl;
				char		ch = 'q';
				int			Inum = 69;
				float		Fnum = 69.0f;
				double		Dnum = 69.0;
				bool		ques = true;
				std::string str = "ria regnum";

				std::string stigma = "the only reason i exist is to prove a point..";
				std::cout << "this test proves that different arguments are indeed being printed by the logFile using automatic indexing" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logFileTrace	("this is level 0 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				logFileInfo		("this is level 1 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				logFileWarn		("this is level 2 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				logFileError	("this is level 3 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				logFileCritical	("this is level 4 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 7 - " << std::endl;
				char		ch = 'q';
				int			Inum = 69;
				float		Fnum = 69.0f;
				double		Dnum = 69.0;
				bool		ques = true;
				std::string str = "ria regnum";

				std::string stigma = "the only reason i exist is to prove a point..";
				std::cout << "this test proves that different arguments are indeed being printed by the logFile using manual indexing" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logFileTrace	("this is level 0 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				logFileInfo		("this is level 1 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				logFileWarn		("this is level 2 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				logFileError	("this is level 3 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				logFileCritical	("this is level 4 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		{
			std::cout << "testing log" << std::endl;
			{
				std::cout << "level 1 - " << std::endl;
				std::cout << "this test proves that the macro log is indeed working" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logTrace	("this is level 0 of the log");
				logInfo		("this is level 1 of the log");
				logWarn		("this is level 2 of the log");
				logError	("this is level 3 of the log");
				logCritical	("this is level 4 of the log");
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 2 - " << std::endl;
				int a = 69;
				std::cout << "this test proves that automatic indexing indeed works when using log" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logTrace	("this is level 0 of the log and i am printing a arguments : {}", a);
				logInfo		("this is level 1 of the log and i am printing a arguments : {}", a);
				logWarn		("this is level 2 of the log and i am printing a arguments : {}", a);
				logError	("this is level 3 of the log and i am printing a arguments : {}", a);
				logCritical	("this is level 4 of the log and i am printing a arguments : {}", a);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 3 - " << std::endl;
				int a = 69, b = 286;
				std::cout << "this test proves that automatic indexing works when using log and that some arguments can be dropped which are passed into the macro" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logTrace	("this is level 0 of the log and i am providing more arguments than required.. : {}", a, b);
				logInfo		("this is level 1 of the log and i am providing more arguments than required.. : {}", a, b);
				logWarn		("this is level 2 of the log and i am providing more arguments than required.. : {}", a, b);
				logError	("this is level 3 of the log and i am providing more arguments than required.. : {}", a, b);
				logCritical	("this is level 4 of the log and i am providing more arguments than required.. : {}", a, b);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 4 - " << std::endl;
				int a = 69, b = 286;
				std::cout << "this test proves that manual indexing works when using log and that some arguments can be dropped which are passed into the macro" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logTrace	("this is level 0 of the log and i am choosing which argument to print : {1}", a, b);
				logInfo		("this is level 1 of the log and i am choosing which argument to print : {1}", a, b);
				logWarn		("this is level 2 of the log and i am choosing which argument to print : {1}", a, b);
				logError	("this is level 3 of the log and i am choosing which argument to print : {1}", a, b);
				logCritical	("this is level 4 of the log and i am choosing which argument to print : {1}", a, b);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 5 - " << std::endl;
				int a = 69, b = 286, c = 4;
				std::cout << "this test proves that manual indexing works when using log" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logTrace	("this is level 0 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				logInfo		("this is level 1 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				logWarn		("this is level 2 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				logError	("this is level 3 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				logCritical	("this is level 4 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 6 - " << std::endl;
				char		ch = 'q';
				int			Inum = 69;
				float		Fnum = 69.0f;
				double		Dnum = 69.0;
				bool		ques = true;
				std::string str = "ria regnum";

				std::string stigma = "the only reason i exist is to prove a point..";
				std::cout << "this test proves that different arguments are indeed being printed by the log using automatic indexing" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logTrace	("this is level 0 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				logInfo		("this is level 1 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				logWarn		("this is level 2 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				logError	("this is level 3 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				logCritical	("this is level 4 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;

			{
				std::cout << "level 7 - " << std::endl;
				char		ch = 'q';
				int			Inum = 69;
				float		Fnum = 69.0f;
				double		Dnum = 69.0;
				bool		ques = true;
				std::string str = "ria regnum";

				std::string stigma = "the only reason i exist is to prove a point..";
				std::cout << "this test proves that different arguments are indeed being printed by the log using manual indexing" << std::endl;
				std::cout << "----------------------------------------------------------" << std::endl;
				logTrace	("this is level 0 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				logInfo		("this is level 1 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				logWarn		("this is level 2 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				logError	("this is level 3 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				logCritical	("this is level 4 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			std::cout << std::endl;
		}
	}
}