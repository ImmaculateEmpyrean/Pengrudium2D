#include "stdafx.h"
#include "core/entryPoint.h"

using namespace penguin2D;

class editorApp : public app
{
public:
	editorApp()
		: app("penguin2D editor", 1280, 720)
	{}
};

std::unique_ptr<app> penguin2D::getStartupApp()
{
	return std::make_unique<editorApp>();
}