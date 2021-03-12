#include "stdafx.h"
#include "core/app.h"

using namespace std;

namespace penguin2D
{
	void app::move(app&& rhs)
	{
		m_name	= std::move(rhs.m_name);
		m_width	= std::move(rhs.m_width);
		m_height= std::move(rhs.m_height);
	}

	void app::execute()
	{
		logConsoleTrace("running");
	}
}