#include "TileMap.h"
#include "AssetsManager.h"
#define CUTE_TILED_IMPLEMENTATION
#include "cute_tiled.h"
#include <iostream>
#define MYNULL NULL

TileMap::TileMap(SDL_Renderer* renderer)
{
	TileMap::renderer = renderer;
	world = AssetsManager::LoadTexture("assets/maps/world.png", renderer);
	Load("assets/maps/world.json");
}

TileMap::~TileMap()
{
	cute_tiled_free_map(map);
}

void TileMap::Load(const char* filePath)
{
	cute_tiled_map_t* loadedMap = cute_tiled_load_map_from_file(filePath, NULL);
	mapWidth = (loadedMap->width) * BLOCK_SIZE;
	mapHeight = (loadedMap->height) * BLOCK_SIZE;
	mapTotalBlocks = (mapWidth / BLOCK_SIZE) * (mapHeight / BLOCK_SIZE);
	map = loadedMap;
	return;
}

void TileMap::Draw()
{
	cute_tiled_layer_t* layer = map->layers;

	while (layer)
	{
		int* data = layer->data;
		int data_count = layer->data_count;
		for (int i = 0; i < mapTotalBlocks; i++)
		{
			if (data[i] > 0)
			{
				if (isTileAnimated(data[i]))
				{
					if (!isAnimationCurrentlyRunning(data[i], i))
					{
						cute_tiled_tile_descriptor_t tile = getTile(data[i]);
						AnimationManager* animatedTile = new AnimationManager(data[i], i, renderer, world, tile);
						animatedTiles.push_back(animatedTile);
					}
				}
				else
				{
					int srcX = (data[i] - 1) % tilesetWidth;
					int srcY = (data[i] - 1) / tilesetWidth; 

					int destX = i % (mapWidth / BLOCK_SIZE);
					int destY = i / (mapWidth / BLOCK_SIZE);

					// Draw tiles to the screen
					SDL_Rect srcRect = { srcX * BLOCK_SIZE, srcY * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE };
					SDL_Rect destRect = { destX * BLOCK_SIZE, destY * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE };

					SDL_RenderCopy(renderer, world, &srcRect, &destRect);
				}


			}
		}
		layer = layer->next;
	}
}

void TileMap::Animate()
{
	for (auto &tile : animatedTiles)
	{
		if (tile->isAnimationRunning())
		{
			tile->animateStatic(renderer, world);
		}
	}
}

const bool TileMap::isTileCollidable(int id)
{
	cute_tiled_layer_t* layer = map->layers;
	int tileId;

	while (layer)
	{
		// target top layer
		if (layer->next == nullptr)
		{
			tileId = layer->data[id];
		}
		layer = layer->next;
	}

	cute_tiled_tile_descriptor_t* tiles = map->tilesets->tiles;
	while (tiles)
	{
		if (tiles->tile_index == (tileId - 1))
		{
			return true;
		}

		tiles = tiles->next;
	}
	return false;
}

const bool TileMap::isAnimationCurrentlyRunning(int id, int position)
{
	for (auto &tile : animatedTiles)
	{
		if (tile->getId() == id && tile->getPosition() == position)
		{
			return true;
		}
	}

	return false;
}

const bool TileMap::isTileAnimated(int id)
{
	cute_tiled_tile_descriptor_t* tiles = map->tilesets->tiles;
	while (tiles)
	{
		if (tiles->tile_index == (id - 1) && tiles->animation != NULL)
		{
			return true;
		}

		tiles = tiles->next;
	}
	return false;
}

struct cute_tiled_tile_descriptor_t TileMap::getTile(int id)
{
	cute_tiled_tile_descriptor_t* tiles = map->tilesets->tiles;
	while (tiles)
	{
		if (tiles->tile_index == (id - 1))
		{
			return *tiles;
		}

		tiles = tiles->next;
	}
}
