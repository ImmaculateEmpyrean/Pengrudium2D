#include "stdafx.h"
#include "executableLogTest.h"

#undef PEngine_DEBUG
#undef PExecutable_DEBUG
#undef PEditor_DEBUG
#undef PExample_DEBUG
#undef PTest_DEBUG

#define PExecutable_DEBUG

#include "../LogTest.h"


namespace executableLogCheck
{
	void performChecks()
	{
		logCheck::check();
	}
}