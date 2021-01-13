#include "stdafx.h"
#include "testEngineLogging/engineLogTest.h"
#include "testEditorLogging/editorLogTest.h"
#include "testExampleLogging/exampleLogTest.h"
#include "testExecutableLogging/executableLogTest.h"
#include "testTestLogging/testLogTest.h"
#include "testNoSymbolsDefined/noSymbolsLogTest.h"

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
	std::cout << "6. perform testing on testLogger" << std::endl;
	std::cout << "7. perform testing with no logger attached" << std::endl;

	std::cout << "please enter choice : ";
	std::cin >> choice;
	std::cout << std::endl;

	if (choice < 1 && choice > 7)
	{
		std::cout << "please choose an option listed above to conduct testing.." << std::endl;
		goto program_start;
	}

	std::cout << "starting chosen test" << std::endl;

	switch (choice)
	{
	case 1: engineLogCheck::	performChecks();
			executableLogCheck::performChecks();
			editorLogCheck::	performChecks();
			exampleLogCheck::	performChecks();
			testLogCheck::		performChecks();
			noSymbolsLogCheck::	performChecks();
		break;
	case 2: engineLogCheck::	performChecks();
		break;
	case 3: executableLogCheck::performChecks();
		break;
	case 4: editorLogCheck::	performChecks();
		break;
	case 5: exampleLogCheck::	performChecks();
		break;
	case 6:	testLogCheck::		performChecks();
		break;
	case 7: noSymbolsLogCheck::	performChecks();
		break;
	default: std::cout << "i should never get triggered" << std::endl;
		break;
	}
}