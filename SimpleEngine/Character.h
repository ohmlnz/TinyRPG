#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Character
{
public:
	Character() {}
	Character(SDL_Renderer* renderer);
	void Draw();
	void setX(int newY);
	void setY(int newx);
	int getX() const;
	int getY() const;
private:
	SDL_Texture* character;
	SDL_Renderer* renderer;
	int posX = 400;
	int posY = 400;
	int width = 32;
	int height = 32;
};