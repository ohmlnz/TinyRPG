#include "AnimationManager.h"
#include <iostream>

void AnimationManager::walkingAnimation(const std::string& direction, SDL_Rect& srcRect)
{
	if (frame >= 4)
	{
		frame = 0;
	}

	// TODO: should not be limited to a 3-frame animation
	// There should probably be an array of x values and 
	// an array of y values, containing matching set of indexes
	// indicating an animation frame

	if (direction == "up")
	{

		if (frame == 0)
		{
			srcRect.x = 50;
			srcRect.y = 2;
		}
		else if (frame == 1)
		{
			srcRect.x = 26;
			srcRect.y = 0;
		}
		else
		{
			srcRect.x = 2;
			srcRect.y = 2;
		}
	}
	else if (direction == "down")
	{
		if (frame == 0)
		{
			srcRect.x = 50;
			srcRect.y = 66;
		}
		else if (frame == 1)
		{
			srcRect.x = 26;
			srcRect.y = 64;
		}
		else
		{
			srcRect.x = 2;
			srcRect.y = 66;
		}
	}
	else if (direction == "left")
	{
		if (frame == 0)
		{
			srcRect.x = 49;
			srcRect.y = 98;
		}
		else if (frame == 1)
		{
			srcRect.x = 26;
			srcRect.y = 97;
		}
		else
		{
			srcRect.x = 0;
			srcRect.y = 98;
		}
	}
	else
	{
		if (frame == 0)
		{
			srcRect.x = 53;
			srcRect.y = 34;
		}
		else if (frame == 1)
		{
			srcRect.x = 27;
			srcRect.y = 33;
		}
		else
		{
			srcRect.x = 4;
			srcRect.y = 34;
		}
	}

	frame++;
}