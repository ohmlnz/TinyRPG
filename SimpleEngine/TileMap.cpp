#include "TileMap.h"
#include "TextureManager.h"

TileMap::TileMap(SDL_Renderer* renderer)
{
	TileMap::renderer = renderer;
	// TODO: Preload all assets in one loop
	dirt = TextureManager::LoadTexture("assets/dirt.png", renderer);
	water = TextureManager::LoadTexture("assets/water.png", renderer);
	grass = TextureManager::LoadTexture("assets/grass.png", renderer);
}

void TileMap::Load(const char* filePath)
{
	// TODO: Read JSON file
}

void TileMap::Draw()
{
	SDL_Rect srcRect, destRect;
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = BLOCK_SIZE;

	destRect.w = destRect.h = BLOCK_SIZE;

	for (int row = 0; row < nbRows; row++)
	{
		for (int column = 0; column < nbColumns; column++)
		{
			int tile = defaultMap[row][column];
			destRect.x = column * BLOCK_SIZE;
			destRect.y = row * BLOCK_SIZE;

			switch (tile)
			{
			case 1:
				SDL_RenderCopy(renderer, dirt, &srcRect, &destRect);
				break;
			case 2:
				SDL_RenderCopy(renderer, water, &srcRect, &destRect);
				break;
			case 3:
				SDL_RenderCopy(renderer, grass, &srcRect, &destRect);
				break;
			}
		}
	}
}

bool TileMap::hasCollided(Character& character)
{
	if (character.getX() + 32 > nbColumns * BLOCK_SIZE)
	{
		character.setX(nbColumns * BLOCK_SIZE - 32);
		return true;
	}
	else if (character.getX() < 0)
	{
		character.setX(0);
		return true;
	}
	else if (character.getY() + 32 > nbRows * BLOCK_SIZE)
	{
		character.setY(nbRows * BLOCK_SIZE - 32);
		return true;
	}
	else if (character.getY() < 0)
	{
		character.setY(0);
		return true;
	}
	else
	{
		return false;
	}
}