#include "stdafx.h"
#include "core/entryPoint.h"

using namespace penguin2D;

class sandBoxApp : public app
{
public:
	sandBoxApp()
		: app("sandbox app",1280,720)
	{}
};

std::unique_ptr<app> penguin2D::getStartupApp()
{
	return std::make_unique<sandBoxApp>();
}