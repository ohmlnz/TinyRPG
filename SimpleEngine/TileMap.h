#pragma once
#include "SDL.h"
#include "SDL_image.h"
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
	const int tilesetWidth = 40;
	int mapTotalBlocks;
	int* indices = nullptr;
	bool* solids = nullptr;
	int BLOCK_SIZE = 16;
	int mapWidth;
	int mapHeight;
private:

	SDL_Renderer* renderer;
	SDL_Texture* world;
};