#include "stdafx.h"
#include "noSymbolsLogTest.h"

#undef PEngine_DEBUG
#undef PExecutable_DEBUG
#undef PEditor_DEBUG
#undef PExample_DEBUG
#undef PTest_DEBUG

#include "../LogTest.h"


namespace noSymbolsLogCheck
{
	void performChecks()
	{
		logCheck::check();
	}
}