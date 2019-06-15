#include "stdafx.h"
#include "Map.h"
#include <iostream>

/*
(isMovable, canstand, color)
0: floor = false, true;
1: wall = false, false;
2: woodBox = true, false;
3: warp = false, true;
4: background = false, false;
*/

Map::Map()
{
}

Map::Map(int sizeX, int sizeY, int** arr)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->Matrix = arr;
}

void Map::reverseMatrix()
{
	int** reversedMatrix = new int*[this->sizeY];
	for (int i = 0; i < this->sizeY; i++) {
		reversedMatrix[i] = new int[this->sizeX];
	}
	for (int i = 0; i < this->sizeY; i++) {
		for (int k = 0; k < this->sizeX; k++) {
			reversedMatrix[i][k] = this->Matrix[k][i];
		}
	}

	for (int i = 0; i < this->sizeY; i++) {
		for (int k = 0; k < 9; k++) {
			reversedMatrix[i][k] = this->Matrix[k][i];
		}
	}

	this->map = new Block*[this->sizeY];
	for (int i = 0; i < this->sizeY; i++) {
		this->map[i] = new Block[this->sizeX];
	}

	for (int i = 0; i < this->sizeY; i++) {
		for (int k = 0; k < this->sizeX; k++) {
			switch (reversedMatrix[i][k]) {
			case 0:
				this->map[i][k] = Block(i, k, false, true, 0);
				break;
			case 1:
				this->map[i][k] = Block(i, k, false, false, 0);
				break;
			case 2:
				this->map[i][k] = Block(i, k, true, false, 0);
				break;
			case 3:
				this->map[i][k] = Block(i, k, false, true, 0);
				break;
			case 4:
				this->map[i][k] = Block(i, k, false, false, 0);
				break;
			}
		}
	}

	for (int i = 0; i < this->sizeY; i++) {
		delete reversedMatrix[i];
	}
	delete[] reversedMatrix;

}

Block** Map::getMap()
{
	reverseMatrix();
	return this->map;
}

Map::~Map()
{
}
