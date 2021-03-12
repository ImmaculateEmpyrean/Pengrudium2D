#pragma once
#include<string>
#include<memory>

#include "app.h"

namespace penguin2D
{
	std::unique_ptr<penguin2D::app> getStartupApp();
}

int main(int argc, char** argv)
{
	auto app = penguin2D::getStartupApp();

	while (!app->quitApplication())
	{
		app->execute();
	}
}