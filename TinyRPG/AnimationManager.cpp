#include "AnimationManager.h"
#include "TileMap.h"
#include <iostream>

AnimationManager::AnimationManager(int& newId, int& newPosition, SDL_Renderer* renderer, SDL_Texture* world, cute_tiled_tile_descriptor_t& newTile)
{
	id = newId;
	running = true;
	position = newPosition;
	animationFrames = sizeof newTile.animation[0] / sizeof newTile.animation;

	for (int i = 0; i <= animationFrames; i++)
	{
		tileData tile;
		tile.duration = newTile.animation[i].duration;
		tile.tileid = newTile.animation[i].tileid;
		animation.push_back(tile);
	}

}

AnimationManager::~AnimationManager()
{
	running = false;
	// TODO: take care of cleanup
}

void AnimationManager::walkingAnimation(const std::string& direction, SDL_Rect& srcRect)
{
	if (frame >= 4)
	{
		frame = 0;
	}

	// TODO: should not be limited to a 3-frame animation
	// There should probably be an array of x values and 
	// an array of y values, containing matching set of indexes
	// indicating an animation frame

	if (direction == "up")
	{

		if (frame == 0)
		{
			srcRect.x = 50;
			srcRect.y = 2;
		}
		else if (frame == 1)
		{
			srcRect.x = 26;
			srcRect.y = 0;
		}
		else
		{
			srcRect.x = 2;
			srcRect.y = 2;
		}
	}
	else if (direction == "down")
	{
		if (frame == 0)
		{
			srcRect.x = 50;
			srcRect.y = 66;
		}
		else if (frame == 1)
		{
			srcRect.x = 26;
			srcRect.y = 64;
		}
		else
		{
			srcRect.x = 2;
			srcRect.y = 66;
		}
	}
	else if (direction == "left")
	{
		if (frame == 0)
		{
			srcRect.x = 49;
			srcRect.y = 98;
		}
		else if (frame == 1)
		{
			srcRect.x = 26;
			srcRect.y = 97;
		}
		else
		{
			srcRect.x = 0;
			srcRect.y = 98;
		}
	}
	else if (direction == "right")
	{
		if (frame == 0)
		{
			srcRect.x = 53;
			srcRect.y = 34;
		}
		else if (frame == 1)
		{
			srcRect.x = 27;
			srcRect.y = 33;
		}
		else
		{
			srcRect.x = 4;
			srcRect.y = 34;
		}
	}

	frame++;
}

void AnimationManager::animateStatic(SDL_Renderer* renderer, SDL_Texture* world)
{
	int tileId = animation[frame].tileid;
	int srcX = tileId % 40;
	int srcY = tileId / 40;

	int destX = position % (800 / 16);
	int destY = position / (800 / 16);

	SDL_Rect srcRect = { srcX * 16, srcY * 16, 16, 16 };
	SDL_Rect destRect = { destX * 16, destY * 16, 16, 16 };

	SDL_RenderCopy(renderer, world, &srcRect, &destRect);

	if (maxFrame >= animation[frame].duration) {
		maxFrame = 0;

		if (frame >= animationFrames)
		{
			frame = 0;
		}
		else
		{
			frame++;
		}
	}
	maxFrame += 80;
}

int AnimationManager::getId()
{
	return id;
}

int AnimationManager::getPosition()
{
	return position;
}

const bool AnimationManager::isAnimationRunning()
{
	return running;
}