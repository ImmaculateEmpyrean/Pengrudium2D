#include "stdafx.h"

int main()
{
	std::cout << "testing if the log library works as intended.." << std::endl;
	{
		std::cout << "testing log console" << std::endl;
		{
			std::cout << "level 1 - " << std::endl;
			std::cout << "----------------------------------------------------------" << std::endl;
			logConsole(0, "this is level 0 of the log");
			logConsole(1, "this is level 1 of the log");
			logConsole(2, "this is level 2 of the log");
			logConsole(3, "this is level 3 of the log");
			logConsole(4, "this is level 4 of the log");
			logConsole(5, "this is level 5 of the log");
			std::cout << "----------------------------------------------------------" << std::endl;
		}
		std::cout << std::endl;

		{
			std::cout << "level 2 - " << std::endl;
			int a = 69;
			std::cout << "----------------------------------------------------------" << std::endl;
			logConsole(0, "this is level 0 of the log and i am printing a arguments : {}", a);
			logConsole(1, "this is level 1 of the log and i am printing a arguments : {}", a);
			logConsole(2, "this is level 2 of the log and i am printing a arguments : {}", a);
			logConsole(3, "this is level 3 of the log and i am printing a arguments : {}", a);
			logConsole(4, "this is level 4 of the log and i am printing a arguments : {}", a);
			logConsole(5, "this is level 5 of the log and i am printing a arguments : {}", a);
			std::cout << "----------------------------------------------------------" << std::endl;
		}
		std::cout << std::endl;

		{
			std::cout << "level 3 - " << std::endl;
			int a = 69, b = 286;
			std::cout << "----------------------------------------------------------" << std::endl;
			logConsole(0, "this is level 0 of the log and i am providing more arguments than required.. : {}", a, b);
			logConsole(1, "this is level 1 of the log and i am providing more arguments than required.. : {}", a, b);
			logConsole(2, "this is level 2 of the log and i am providing more arguments than required.. : {}", a, b);
			logConsole(3, "this is level 3 of the log and i am providing more arguments than required.. : {}", a, b);
			logConsole(4, "this is level 4 of the log and i am providing more arguments than required.. : {}", a, b);
			logConsole(5, "this is level 5 of the log and i am providing more arguments than required.. : {}", a, b);
			std::cout << "----------------------------------------------------------" << std::endl;
		}
		std::cout << std::endl;

		{
			std::cout << "level 4 - " << std::endl;
			int a = 69, b = 286;
			std::cout << "----------------------------------------------------------" << std::endl;
			logConsole(0, "this is level 0 of the log and i am choosing which argument to print : {1}", a, b);
			logConsole(1, "this is level 1 of the log and i am choosing which argument to print : {1}", a, b);
			logConsole(2, "this is level 2 of the log and i am choosing which argument to print : {1}", a, b);
			logConsole(3, "this is level 3 of the log and i am choosing which argument to print : {1}", a, b);
			logConsole(4, "this is level 4 of the log and i am choosing which argument to print : {1}", a, b);
			logConsole(5, "this is level 5 of the log and i am choosing which argument to print : {1}", a, b);
			std::cout << "----------------------------------------------------------" << std::endl;
		}
		std::cout << std::endl;

		{
			std::cout << "level 5 - " << std::endl;
			int a = 69, b = 286, c = 4;
			std::cout << "----------------------------------------------------------" << std::endl;
			logConsole(0, "this is level 0 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
			logConsole(1, "this is level 1 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
			logConsole(2, "this is level 2 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
			logConsole(3, "this is level 3 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
			logConsole(4, "this is level 4 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
			logConsole(5, "this is level 5 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
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
			std::cout << "----------------------------------------------------------" << std::endl;
			logConsole(0, "this is level 0 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
			logConsole(1, "this is level 1 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
			logConsole(2, "this is level 2 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
			logConsole(3, "this is level 3 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
			logConsole(4, "this is level 4 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
			logConsole(5, "this is level 5 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
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
			std::cout << "----------------------------------------------------------" << std::endl;
			logConsole(0, "this is level 0 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
			logConsole(1, "this is level 1 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
			logConsole(2, "this is level 2 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
			logConsole(3, "this is level 3 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
			logConsole(4, "this is level 4 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
			logConsole(5, "this is level 5 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
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
		std::cout << "----------------------------------------------------------" << std::endl;
		logFile(0, "this is level 0 of the log");
		logFile(1, "this is level 1 of the log");
		logFile(2, "this is level 2 of the log");
		logFile(3, "this is level 3 of the log");
		logFile(4, "this is level 4 of the log");
		logFile(5, "this is level 5 of the log");
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "level 2 - " << std::endl;
		int a = 69;
		std::cout << "----------------------------------------------------------" << std::endl;
		logFile(0, "this is level 0 of the log and i am printing a arguments : {}", a);
		logFile(1, "this is level 1 of the log and i am printing a arguments : {}", a);
		logFile(2, "this is level 2 of the log and i am printing a arguments : {}", a);
		logFile(3, "this is level 3 of the log and i am printing a arguments : {}", a);
		logFile(4, "this is level 4 of the log and i am printing a arguments : {}", a);
		logFile(5, "this is level 5 of the log and i am printing a arguments : {}", a);
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "level 3 - " << std::endl;
		int a = 69, b = 286;
		std::cout << "----------------------------------------------------------" << std::endl;
		logFile(0, "this is level 0 of the log and i am providing more arguments than required.. : {}", a, b);
		logFile(1, "this is level 1 of the log and i am providing more arguments than required.. : {}", a, b);
		logFile(2, "this is level 2 of the log and i am providing more arguments than required.. : {}", a, b);
		logFile(3, "this is level 3 of the log and i am providing more arguments than required.. : {}", a, b);
		logFile(4, "this is level 4 of the log and i am providing more arguments than required.. : {}", a, b);
		logFile(5, "this is level 5 of the log and i am providing more arguments than required.. : {}", a, b);
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "level 4 - " << std::endl;
		int a = 69, b = 286;
		std::cout << "----------------------------------------------------------" << std::endl;
		logFile(0, "this is level 0 of the log and i am choosing which argument to print : {1}", a, b);
		logFile(1, "this is level 1 of the log and i am choosing which argument to print : {1}", a, b);
		logFile(2, "this is level 2 of the log and i am choosing which argument to print : {1}", a, b);
		logFile(3, "this is level 3 of the log and i am choosing which argument to print : {1}", a, b);
		logFile(4, "this is level 4 of the log and i am choosing which argument to print : {1}", a, b);
		logFile(5, "this is level 5 of the log and i am choosing which argument to print : {1}", a, b);
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "level 5 - " << std::endl;
		int a = 69, b = 286, c = 4;
		std::cout << "----------------------------------------------------------" << std::endl;
		logFile(0, "this is level 0 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
		logFile(1, "this is level 1 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
		logFile(2, "this is level 2 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
		logFile(3, "this is level 3 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
		logFile(4, "this is level 4 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
		logFile(5, "this is level 5 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
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
		std::cout << "----------------------------------------------------------" << std::endl;
		logFile(0, "this is level 0 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
		logFile(1, "this is level 1 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
		logFile(2, "this is level 2 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
		logFile(3, "this is level 3 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
		logFile(4, "this is level 4 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
		logFile(5, "this is level 5 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
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
		std::cout << "----------------------------------------------------------" << std::endl;
		logFile(0, "this is level 0 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
		logFile(1, "this is level 1 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
		logFile(2, "this is level 2 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
		logFile(3, "this is level 3 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
		logFile(4, "this is level 4 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
		logFile(5, "this is level 5 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
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
		std::cout << "----------------------------------------------------------" << std::endl;
		log(0, "this is level 0 of the log");
		log(1, "this is level 1 of the log");
		log(2, "this is level 2 of the log");
		log(3, "this is level 3 of the log");
		log(4, "this is level 4 of the log");
		log(5, "this is level 5 of the log");
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "level 2 - " << std::endl;
		int a = 69;
		std::cout << "----------------------------------------------------------" << std::endl;
		log(0, "this is level 0 of the log and i am printing a arguments : {}", a);
		log(1, "this is level 1 of the log and i am printing a arguments : {}", a);
		log(2, "this is level 2 of the log and i am printing a arguments : {}", a);
		log(3, "this is level 3 of the log and i am printing a arguments : {}", a);
		log(4, "this is level 4 of the log and i am printing a arguments : {}", a);
		log(5, "this is level 5 of the log and i am printing a arguments : {}", a);
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "level 3 - " << std::endl;
		int a = 69, b = 286;
		std::cout << "----------------------------------------------------------" << std::endl;
		log(0, "this is level 0 of the log and i am providing more arguments than required.. : {}", a, b);
		log(1, "this is level 1 of the log and i am providing more arguments than required.. : {}", a, b);
		log(2, "this is level 2 of the log and i am providing more arguments than required.. : {}", a, b);
		log(3, "this is level 3 of the log and i am providing more arguments than required.. : {}", a, b);
		log(4, "this is level 4 of the log and i am providing more arguments than required.. : {}", a, b);
		log(5, "this is level 5 of the log and i am providing more arguments than required.. : {}", a, b);
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "level 4 - " << std::endl;
		int a = 69, b = 286;
		std::cout << "----------------------------------------------------------" << std::endl;
		log(0, "this is level 0 of the log and i am choosing which argument to print : {1}", a, b);
		log(1, "this is level 1 of the log and i am choosing which argument to print : {1}", a, b);
		log(2, "this is level 2 of the log and i am choosing which argument to print : {1}", a, b);
		log(3, "this is level 3 of the log and i am choosing which argument to print : {1}", a, b);
		log(4, "this is level 4 of the log and i am choosing which argument to print : {1}", a, b);
		log(5, "this is level 5 of the log and i am choosing which argument to print : {1}", a, b);
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "level 5 - " << std::endl;
		int a = 69, b = 286, c = 4;
		std::cout << "----------------------------------------------------------" << std::endl;
		log(0, "this is level 0 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
		log(1, "this is level 1 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
		log(2, "this is level 2 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
		log(3, "this is level 3 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
		log(4, "this is level 4 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
		log(5, "this is level 5 of the log and i am choosing the arguments which i wish to print in the order i desire : {1} : {0} : {2}", a, b, c);
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
		std::cout << "----------------------------------------------------------" << std::endl;
		log(0, "this is level 0 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
		log(1, "this is level 1 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
		log(2, "this is level 2 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
		log(3, "this is level 3 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
		log(4, "this is level 4 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
		log(5, "this is level 5 of the log and i am printing different types of arguments char :{} int :{} float :{} double :{} string :{} bool :{}", ch, Inum, Fnum, Dnum, str, ques);
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
		std::cout << "----------------------------------------------------------" << std::endl;
		log(0, "this is level 0 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
		log(1, "this is level 1 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
		log(2, "this is level 2 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
		log(3, "this is level 3 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
		log(4, "this is level 4 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
		log(5, "this is level 5 of the log and i am printing different types of arguments int :{1} float :{2} double :{3} string :{4} bool :{5} char :{0}", ch, Inum, Fnum, Dnum, str, ques);
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	std::cout << std::endl;
	}
}