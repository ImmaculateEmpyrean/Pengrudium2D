#pragma once
#include<iostream>
#include<string>
#include<vector>

#include "entt.h"

namespace penguin2D
{
	class jobScheduler
	{
	public:
		static void initialize();

		template<typename jobClass,typename... args>
		static void queueJob(args...);
	};
}