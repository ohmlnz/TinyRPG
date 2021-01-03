#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "TileMap.h"
#include "AnimationManager.h"
#include <string>

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
	void changeDirection(const std::string& newDirection);
private:
	SDL_Texture* character;
	SDL_Renderer* renderer;
	AnimationManager animationHandler;
	int posX = 0;
	int posY = 0;
	int width = 16;
	int height = 16;
	std::string direction;
};