#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game
{
public:
	void init(const char* title, int positionX, int positionY, int width, int height, bool fullScreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; }
private:
	bool isRunning;
	SDL_Event event;
	SDL_Window* window;
	SDL_Renderer* renderer;
};