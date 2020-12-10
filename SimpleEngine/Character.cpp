#include "Character.h"
#include "TextureManager.h"
#include "TileMap.h"
#include <iostream>

Character::Character(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	character = TextureManager::LoadTexture("assets/player.png", renderer);
}

Character::~Character() {}

void Character::Draw()
{
	SDL_Rect srcRect, destRect;
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = 16;

	destRect.w = destRect.h = 16;
	destRect.x = posX;
	destRect.y = posY;

	SDL_RenderCopy(renderer, character, &srcRect, &destRect);
}

void Character::setX(TileMap* map, int newX)
{
	if (hasCollided(map, newX, getY()))
	{
		return;
	}

	posX = newX;
}

void Character::setY(TileMap* map, int newY)
{
	if (hasCollided(map, getX(), newY))
	{
		return;
	}

	posY = newY;
}

int Character::getX() const
{
	return posX;
}

int Character::getY() const
{
	return posY;
}

bool Character::hasCollided(TileMap* map, int destX, int destY)
{
	// TODO: figure out why collision on farther right element is not working
	int playerPosX = (destX / map->BLOCK_SIZE) + 1;
	int playerPosY = (destY / map->BLOCK_SIZE) + 1;

	int tileLocation = (playerPosY * (map->mapWidth / map->BLOCK_SIZE)) + playerPosX;
	std::cout << tileLocation << std::endl;
	if (map->solids[tileLocation] == 1)
	{
		return true;
	}

	return false;
}
