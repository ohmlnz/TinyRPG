#include "Tile.h"

Tile::Tile(int initId, int initDestX, int initDestY, int initSrcX, int initSrcY, bool initStatus)
{
	id = initId;
	destX = initDestX;
	destY = initDestY;
	srcX = initSrcX;
	srcY = initSrcY;
	status = initStatus;
}

Tile::~Tile() {}

const bool Tile::getTileStatus()
{
	return status;
}

const int Tile::getTileId()
{
	return id;
}

const coordinates Tile::getCoordinates()
{
	coordinates initCoordinates;
	initCoordinates.destX = destX;
	initCoordinates.destY = destY;
	initCoordinates.srcX = srcX;
	initCoordinates.srcY = srcY;
	return coordinates();
}

void Tile::changeStatus(bool newStatus)
{
	status = newStatus;
}
