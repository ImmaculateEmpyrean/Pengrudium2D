#pragma once
namespace penguin2D
{
	enum class eventType : unsigned int
	{
		NONE = 0,
		characterPressed = 1,
		cursorPositionChanged = 2,
		keyPressed = 3,
		mouseButtonClicked = 4,
		scrolled = 5,
		observer = 6
	};
}