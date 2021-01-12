#include "stdafx.h"

int main()
{
	std::cout << "testing if the log library works as intended.." << std::endl;
	std::cout << "level 1 - " << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	logConsole(0, "this is level 0 of the log");
	logConsole(1, "this is level 1 of the log");
	logConsole(2, "this is level 2 of the log");
	logConsole(3, "this is level 3 of the log");
	logConsole(4, "this is level 4 of the log");
	logConsole(5, "this is level 5 of the log");
	std::cout << "----------------------------------------------------------" << std::endl;

	Sleep(100);

	std::cout << "level 2 - " << std::endl;
	int a = 69;
	std::cout << "----------------------------------------------------------" << std::endl;
	logConsole(0, "this is level 0 of the log and i am printing a variable : {}",a);
	logConsole(1, "this is level 1 of the log and i am printing a variable : {}", a);
	logConsole(2, "this is level 2 of the log and i am printing a variable : {}", a);
	logConsole(3, "this is level 3 of the log and i am printing a variable : {}", a);
	logConsole(4, "this is level 4 of the log and i am printing a variable : {}", a);
	logConsole(5, "this is level 5 of the log and i am printing a variable : {}", a);
	std::cout << "----------------------------------------------------------" << std::endl;
}