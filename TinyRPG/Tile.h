#pragma once
#include <string>

struct coordinates
{
	int destX;
	int destY;
	int srcX;
	int srcY;
};

class Tile
{ 
public:
	Tile(int initId, int initDestX, int initDestY, int initSrcX, int initSrcY, bool initStatus = false);
	~Tile();
	const bool getTileStatus();
	const int getTileId();
	const struct coordinates getCoordinates();
private:
	friend class TileMap;

	int id;
	int destX;
	int destY;
	int srcX;
	int srcY;
	bool status = false;
	void changeStatus(bool changedStatus);
};