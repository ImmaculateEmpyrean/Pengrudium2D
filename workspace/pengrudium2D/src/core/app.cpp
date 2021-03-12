#include "stdafx.h"
#include "core/app.h"

using namespace std;

namespace penguin2D
{
	void app::move(app&& rhs)
	{
		winPtr = std::move(rhs.winPtr);
		rhs.winPtr = nullptr;
	}

	void app::execute()
	{
		logConsoleTrace("running");
	}
}