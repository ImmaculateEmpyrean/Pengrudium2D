#include "stdafx.h"
#include "cacheLineSize.h"

int main()
{
	logConsoleInfo("sandbox initiated..");
	logConsoleInfo("cache_line_size of the machine : {}",penguin2D::getCacheLineSize());
}