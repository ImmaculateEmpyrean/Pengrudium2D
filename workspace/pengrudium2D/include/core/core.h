#pragma once
//the penguin2D	 namespace is the default namespace for all things pengrudium2D..
//the penguin2DI namespace is the default namespace for all things internal to pengrudium2D..


namespace penguin2D
{
	namespace penguin2DI
	{
		void initializeUUIDGeneration(); //definition given in file entotyComponentSystem/entity.cpp
	}

	void initializeEngine();
}