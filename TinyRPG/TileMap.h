#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "cute_tiled.h"
#include "AnimationManager.h"
#include <vector>

class TileMap
{
public:
	TileMap() {}
	TileMap(SDL_Renderer* renderer);
	~TileMap();
	void Load(const char* filePath);
	void Draw();
	void Animate();
	struct cute_tiled_tile_descriptor_t getTile(int id);
	const bool isTileAnimated(int id);
	const bool isTileCollidable(int id);
	const bool isAnimationCurrentlyRunning(int id, int position);
	const int tilesetWidth = 40;
	int mapTotalBlocks;
	int BLOCK_SIZE = 16;
	int mapWidth;
	int mapHeight;
private:
	SDL_Renderer* renderer;
	SDL_Texture* world;
	cute_tiled_map_t* map;
	std::vector<AnimationManager*> animatedTiles;
};