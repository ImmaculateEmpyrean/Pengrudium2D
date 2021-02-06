#include "stdafx.h"
#include "cacheLineSize.h"

#include "core/symbols.h"
#include "instrumentation/instrumentation.h"

void printingFunction()
{
	PROFILER_TIME_FUNCTION();

	for (long i = 0; i < 1000; i++)
		std::cout << i << std::endl;
}

int main()
{
	logConsoleInfo("sandbox initiated..");
	logConsoleInfo("cache_line_size of the machine : {}",penguin2D::getCacheLineSize());

	PROFILER_NEWSESSION("test", "test.json");
	printingFunction();
	PROFILER_ENDSESSION();
}