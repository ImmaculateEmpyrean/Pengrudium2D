#pragma once
#include<memory>
#include "entityComponentSystem/scene.h"

namespace penguin2D
{
	void scheduleOnUpdateSystem(std::shared_ptr<scene> scenePtr);
}