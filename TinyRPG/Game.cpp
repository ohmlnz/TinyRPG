#include "Game.h"
#include "TileMap.h"
#include "Character.h"
#include "AssetsManager.h"
#include <iostream>
#include "SDL_ttf.h"

Game::~Game()
{
	delete map;
	delete character;
}

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
			map = new TileMap(renderer);
			character = new Character(renderer);
		}

		// Initialize TTF library
		TTF_Init();

		isRunning = true;
	}
	else {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		isRunning = false;
	}
}

void Game::handleEvents()
{
	const int SPEED = 7;
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
				case SDL_SCANCODE_UP:
					currentY = character->getY();
					character->setY(map, currentY - SPEED);
					character->changeDirection("up");
					break;
				case SDL_SCANCODE_LEFT:
					currentX = character->getX();
					character->setX(map, currentX - SPEED);
					character->changeDirection("left");
					break;
				case SDL_SCANCODE_DOWN:
					currentY = character->getY();
					character->setY(map, currentY + SPEED);
					character->changeDirection("down");
					break;
				case SDL_SCANCODE_RIGHT:
					currentX = character->getX();
					character->setX(map, currentX + SPEED);
					character->changeDirection("right");
					break;
				default:
					break;
			}
			break;
		default:
			character->changeDirection("idle");
			break;
	}
}

void Game::update()
{
	// handles updates
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->Draw();
	map->Animate();
	character->Draw();
	AssetsManager::DisplayText("TinyRPG - version 0.0.1", 15, renderer);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	TTF_Quit();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::running()
{
	return isRunning;
}