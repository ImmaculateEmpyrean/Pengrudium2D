#include "stdafx.h"
#include "editorLogTest.h"

#undef PEngine_DEBUG
#undef PExecutable_DEBUG
#undef PEditor_DEBUG
#undef PExample_DEBUG
#undef PTest_DEBUG

#define PEditor_DEBUG

#include "../LogTest.h"


namespace editorLogCheck
{
	void performChecks()
	{
		logCheck::check();
	}
}