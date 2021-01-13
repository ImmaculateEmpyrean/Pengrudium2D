#include "stdafx.h"
#include "exampleLogTest.h"

#undef PEngine_DEBUG
#undef PExecutable_DEBUG
#undef PEditor_DEBUG
#undef PExample_DEBUG
#undef PTest_DEBUG

#define PExample_DEBUG

#include "../LogTest.h"


namespace exampleLogCheck
{
	void performChecks()
	{
		logCheck::check();
	}
}