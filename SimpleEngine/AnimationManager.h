#pragma once
#include "SDL.h"
#include <string>

class AnimationManager
{
public:
	AnimationManager() {}
	void walkingAnimation(const std::string& direction, SDL_Rect& srcRect);
	int frame = 1;
private:
};