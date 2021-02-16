#include "stdafx.h"
#include "cacheLineSize.h"

#include "core/symbols.h"
#include "instrumentation/instrumentation.h"

void printingSubset1()
{
	PROFILER_TIME_FUNCTION
	_sleep(2500);
}
void printingSubset2()
{
	PROFILER_TIME_FUNCTION
	_sleep(2500);
}
void printingFunction()
{
	PROFILER_TIME_FUNCTION
	printingSubset1();
	printingSubset2();
	_sleep(5000);
}


int main()
{
	logConsoleInfo("sandbox initiated..");
	logConsoleInfo("cache_line_size of the machine : {}",penguin2D::getCacheLineSize());

	PROFILER_NEWSESSION("test", "test.json");
	std::thread thr(printingFunction);
	_sleep(10000);
	printingFunction();
	thr.join();
	PROFILER_ENDSESSION();
}