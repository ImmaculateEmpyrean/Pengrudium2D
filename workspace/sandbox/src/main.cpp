#include "stdafx.h"
#include "cacheLineSize.h"

#include "instrumentation/instrumentation.h"

void printingFunction()
{
	penguin2D::instrumentation::instrumentationTimer cloc(__FUNCSIG__);
	
	for (long i = 0; i < 1000; i++)
		std::cout << i << std::endl;
}

int main()
{
	logConsoleInfo("sandbox initiated..");
	logConsoleInfo("cache_line_size of the machine : {}",penguin2D::getCacheLineSize());

	auto ins = penguin2D::instrumentation::instrumentor::get();

	ins.beginSession("test", "test.json");
	printingFunction();
	ins.endSession();
}