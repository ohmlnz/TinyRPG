#include "Game.h"
#include "TileMap.h"
#include "Character.h"

TileMap map;
Character character;

void Game::init(const char* title, int positionX, int positionY, int width, int height, bool fullScreen)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		Uint32 flags = fullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
		window = SDL_CreateWindow(title, positionX, positionY, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			map = TileMap(renderer);
			character = Character(renderer);
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}
}

// TODO: fix jerkiness in movement
// TODO: create keyboard component
void Game::handleEvents()
{
	const int SPEED = 5;
	int currentX, currentY;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.scancode)
			{
				case SDL_SCANCODE_W:
				case SDL_SCANCODE_UP:
					currentY = character.getY();
					character.setY(currentY - SPEED);
					break;
				case SDL_SCANCODE_A:
				case SDL_SCANCODE_LEFT:
					currentX = character.getX();
					character.setX(currentX - SPEED);
					break;
				case SDL_SCANCODE_S:
				case SDL_SCANCODE_DOWN:
					currentY = character.getY();
					character.setY(currentY + SPEED);
					break;
				case SDL_SCANCODE_D:
				case SDL_SCANCODE_RIGHT:
					currentX = character.getX();
					character.setX(currentX + SPEED);
					break;
				default:
					break;
			}
			break;
	}
}

void Game::update()
{
	map.hasCollided(character);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map.Draw();
	character.Draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}