#include "TileMap.h"
#include "TextureManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

TileMap::TileMap(SDL_Renderer* renderer)
{
	TileMap::renderer = renderer;
	world = TextureManager::LoadTexture("assets/maps/world.png", renderer);
	Load("assets/maps/world.txt");
}

TileMap::~TileMap()
{
	delete[] indices;
	delete[] solids;
}

void TileMap::Load(const char* filePath)
{
	std::ifstream inputFile;
	
	inputFile.open(filePath);

	if (!inputFile)
	{
		std::cout << filePath << " does not exist" << std::endl;
	}

	inputFile >> mapWidth >> mapHeight;
	
	mapTotalBlocks = (mapWidth / BLOCK_SIZE) * (mapHeight / BLOCK_SIZE);
	
	indices = new int[mapTotalBlocks];
	solids = new bool[mapTotalBlocks];

	for (int i = 0; i < mapTotalBlocks; i++)
	{
		inputFile >> indices[i];
		inputFile >> solids[i];
	}

	inputFile.close();
	return;
}

void TileMap::Draw()
{
	for (int i = 0; i < mapTotalBlocks; i++)
	{
		if (indices[i] != -1)
		{
			int srcX = indices[i] % tilesetWidth;
			int srcY = indices[i] / tilesetWidth;

			int destX = i % (mapWidth / BLOCK_SIZE);
			int destY = i / (mapWidth / BLOCK_SIZE);

			SDL_Rect srcRect = { srcX * BLOCK_SIZE, srcY * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE };
			SDL_Rect destRect = { destX * BLOCK_SIZE, destY * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE };

			SDL_RenderCopy(renderer, world, &srcRect, &destRect);
		}
	}
}