#include "Character.h"
#include "TextureManager.h"

Character::Character(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	character = TextureManager::LoadTexture("assets/character.png", renderer);
}

void Character::Draw()
{
	SDL_Rect srcRect, destRect;
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = 32;

	destRect.w = destRect.h = 32;
	destRect.x = posX;
	destRect.y = posY;

	SDL_RenderCopy(renderer, character, &srcRect, &destRect);
}

void Character::setX(int newX)
{
	posX = newX;
}

void Character::setY(int newY)
{
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