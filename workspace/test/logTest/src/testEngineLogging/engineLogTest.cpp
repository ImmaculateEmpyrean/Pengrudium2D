#include "stdafx.h"
#include "engineLogTest.h"

#undef PEngine_DEBUG
#undef PExecutable_DEBUG
#undef PEditor_DEBUG
#undef PExample_DEBUG
#undef PTest_DEBUG

#define PEngine_DEBUG

#include "../LogTest.h"


namespace engineLogCheck
{
	void performChecks()
	{
		logCheck::check();
	}
}