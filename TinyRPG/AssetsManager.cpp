#include "AssetsManager.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

SDL_Texture* AssetsManager::LoadTexture(const char* filePath, SDL_Renderer* renderer)
{
	SDL_Texture* texture;
	SDL_Surface* tempSurface = IMG_Load(filePath);

	texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return texture;
}

void AssetsManager::DisplayText(const char* text, int size, SDL_Renderer* renderer)
{
	TTF_Font* font = TTF_OpenFont("assets/fonts/arial.ttf", size);
	SDL_Color color = { 0, 0, 0 };
	SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = { 0, 0, texW, texH };

	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	SDL_RenderPresent(renderer);
	TTF_CloseFont(font);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}