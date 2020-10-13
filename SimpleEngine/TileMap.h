#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Character.h"
#include <vector>

class TileMap
{
public:
	TileMap() {}
	TileMap(SDL_Renderer* renderer);
	~TileMap();
	void Load(const char* filePath);
	void Draw();
	//bool hasCollided(Character &character);
private:
	int* indices = nullptr;
	bool* solids = nullptr;
	int BLOCK_SIZE = 16;
	int mapWidth;
	int mapHeight;
	int mapTotalBlocks;
	SDL_Renderer* renderer;
	SDL_Texture* world;
};