#include "Block.h"

#pragma once

class Map {
public:
	Map();
	Map(int sizeX, int sizeY, int** arr);
	void reverseMatrix();
	Block** getMap();
	~Map();
private:
	int sizeX;
	int sizeY;
	int** Matrix;
	Block** map;
};