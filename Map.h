#include "Block.h"

#pragma once

class Map {
public:
	Map();
	Map(int sizeX, int sizeY, int** arr);
	void reverseMatrix();
	int** getDestinationCoordinateArray();
	int getDestinations();
	Block** getMap();
	~Map();
private:
	int sizeX;
	int sizeY;
	int** Matrix;
	int nDestination = 0;
	Block** map;
};