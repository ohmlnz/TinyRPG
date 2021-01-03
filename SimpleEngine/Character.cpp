#include "Character.h"
#include "TextureManager.h"
#include "TileMap.h"
#include "AnimationManager.h"
#include <iostream>
#include <cmath>

Character::Character(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	character = TextureManager::LoadTexture("assets/character.png", renderer);
}

Character::~Character() {}

void Character::Draw()
{
	SDL_Rect srcRect, destRect;

	animationHandler.walkingAnimation(direction, srcRect);

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
	int playerPosX = std::round(double(destX) / double(map->BLOCK_SIZE));
	int playerPosY = std::round(double(destY) / double(map->BLOCK_SIZE));

	int tileLocation = (playerPosY * (map->mapWidth / map->BLOCK_SIZE)) + playerPosX;

	if (map->solids[tileLocation] == 1)
	{
		return true;
	}

	return false;
}

void Character::changeDirection(const std::string& newDirection)
{
	if (newDirection == "idle")
	{
		animationHandler.frame = 1;
		return;
	}

	direction = newDirection;
}
