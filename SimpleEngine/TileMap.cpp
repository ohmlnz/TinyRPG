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
	world = TextureManager::LoadTexture("assets/maps/word.png", renderer);
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
	int tilesetWidth = 40;

	for (int i = 0; i < mapTotalBlocks / 2; i++)
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


// TODO: collision should happen at the entity level
//bool TileMap::hasCollided(Character& character)
//{
//	if (character.getX() + 32 > nbColumns * BLOCK_SIZE)
//	{
//		character.setX(nbColumns * BLOCK_SIZE - 32);
//		return true;
//	}
//	else if (character.getX() < 0)
//	{
//		character.setX(0);
//		return true;
//	}
//	else if (character.getY() + 32 > nbRows * BLOCK_SIZE)
//	{
//		character.setY(nbRows * BLOCK_SIZE - 32);
//		return true;
//	}
//	else if (character.getY() < 0)
//	{
//		character.setY(0);
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}