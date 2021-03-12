#include "stdafx.h"

#include "core/entryPoint.h"

#include "entityComponentSystem/scene.h"
#include "entityComponentSystem/entity.h"
#include "entityComponentSystem/component.h"

#include "entityComponentSystem/systems/scriptProcessingSystem.h"

#include "eventSubscriptionSystem/eventBroadcastStation.h"

#include "core/core.h"

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