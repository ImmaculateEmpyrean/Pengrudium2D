#include "stdafx.h"

#include "testEngineLogging/engineLogTest.h"

static void drawSeperator()
{
	std::cout << std::endl << "------------------------------------------------------" << std::endl;
}

int main()
{
program_start:
	int choice = 0;
	std::cout << "choose which test it is to perform " << std::endl;
	std::cout << "1. perform all tests" << std::endl;
	std::cout << "2. perform testing on engineLogger" << std::endl;
	std::cout << "3. perform testing on executableLogger" << std::endl;
	std::cout << "4. perform testing on editorLogger" << std::endl;
	std::cout << "5. perform testing on exampleLogger" << std::endl;
	std::cout << "6. perform testing with no logger attached" << std::endl;

	std::cout << "please enter choice : ";
	std::cin >> choice;
	std::cout << std::endl;

	if (choice < 1 && choice > 6)
	{
		std::cout << "please choose an option listed above to conduct testing.." << std::endl;
		goto program_start;
	}

	std::cout << "starting chosen test" << std::endl;

	switch (choice)
	{
	case 1: std::cout << "not yet available" << std::endl;
		break;
	case 2: engineLogCheck::performChecks();
		break;
	case 3: std::cout << "not yet available" << std::endl;
		break;
	case 4: std::cout << "not yet available" << std::endl;
		break;
	case 5: std::cout << "not yet available" << std::endl;
		break;
	case 6: std::cout << "not yet available" << std::endl;
		break;
	default: std::cout << "i should never get triggered" << std::endl;
		break;
	}
}