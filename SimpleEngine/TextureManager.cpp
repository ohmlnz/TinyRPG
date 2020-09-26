#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filePath, SDL_Renderer* renderer)
{
	SDL_Texture* texture;
	SDL_Surface* tempSurface = IMG_Load(filePath);

	texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return texture;
}