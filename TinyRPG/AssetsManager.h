#pragma once
#include "Game.h"

class AssetsManager
{
public:
	static SDL_Texture* LoadTexture(const char* filePath, SDL_Renderer* renderer);
	static void DisplayText(const char* text, int size, SDL_Renderer* renderer);
};