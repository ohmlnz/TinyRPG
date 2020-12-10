#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "TileMap.h"

class Character
{
public:
	Character() {}
	Character(SDL_Renderer* renderer);
	~Character();
	void Draw();
	void setX(TileMap* map, int newY);
	void setY(TileMap* map, int newX);
	int getX() const;
	int getY() const;
	bool hasCollided(TileMap* map, int destX, int destY);
private:
	SDL_Texture* character;
	SDL_Renderer* renderer;
	int posX = 400;
	int posY = 400;
	int width = 16;
	int height = 16;
};