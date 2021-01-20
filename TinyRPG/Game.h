#pragma once

#include "TileMap.h"
#include "SDL.h"
#include "Character.h"

class Game
{
public:
	~Game();
	void init(const char* title, int positionX, int positionY, int width, int height, bool fullScreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
private:
	bool isRunning;
	SDL_Event event;
	SDL_Window* window;
	SDL_Renderer* renderer;
	TileMap* map;
	Character* character;
};