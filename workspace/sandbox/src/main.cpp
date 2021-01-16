#include "stdafx.h"

#include "entt.h"

namespace penguin2D
{
	void hanna();
}

int main()
{
	penguin2D::hanna();
	std::cout << "hello from sandbox.." << std::endl;

	logConsoleInfo("Haha");
	entt::scheduler<uint32_t> mainScheduler;

	mainScheduler.attach([](auto...) {
		logConsoleInfo("this is a task attached to entt scheduler");
		});

	while (true)
		mainScheduler.update(32);
}