#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "cute_tiled.h"
#include <string>
#include <vector>

struct tileData {
	int duration;
	int tileid;
};

class AnimationManager
{
public:
	// TODO: remove default constructor
	AnimationManager() {};
	AnimationManager(int& newId, int& newPosition, SDL_Renderer* renderer, SDL_Texture* world, cute_tiled_tile_descriptor_t& tile);
	~AnimationManager();
	void walkingAnimation(const std::string& direction, SDL_Rect& srcRect);
	void animateStatic(SDL_Renderer* renderer, SDL_Texture* world);
	const bool isAnimationRunning();
	int getId();
	int getPosition();
	int frame = 1;
	int maxFrame = 0;
private:
	int id;
	int position;
	int animationFrames;
	bool running = false;
	std::vector<struct tileData> animation;
};