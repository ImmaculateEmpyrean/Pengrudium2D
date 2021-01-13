#include "stdafx.h"
#include "testLogTest.h"

#undef PEngine_DEBUG
#undef PExecutable_DEBUG
#undef PEditor_DEBUG
#undef PExample_DEBUG
#undef PTest_DEBUG

#define PTest_DEBUG

#include "../LogTest.h"


namespace testLogCheck
{
	void performChecks()
	{
		logCheck::check();
	}
}