#include "stdafx.h"
#include "Map.h"

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
	reverseMatrix();
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
		for (int k = 0; k < this->sizeX; k++) {
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
				this->map[i][k] = Block(i, k, false, false, 1);
				break;
			case 2:
				this->map[i][k] = Block(i, k, true, false, 2);
				break;
			case 3:
				this->map[i][k] = Block(i, k, false, true, 3);
				this->nDestination++;
				break;
			case 4:
				this->map[i][k] = Block(i, k, false, false, 4);
				break;
			}
		}
	}

	for (int i = 0; i < this->sizeY; i++) {
		delete reversedMatrix[i];
	}
	delete[] reversedMatrix;

}

int Map::getDestinations() {
	return this->nDestination;
}

int** Map::getDestinationCoordinateArray() {
	int** arr = new int*[nDestination];
	for (int i = 0; i < nDestination; i++) {
		arr[i] = new int[2];
	}

	int count = 0;
	for (int i = 0; i < this->sizeY; i++) {
		for (int k = 0; k < this->sizeX; k++) {
			if (this->map[i][k].getColor() == 3) {
				arr[count][0] = i;
				arr[count][1] = k;
				count++;
			}
		}
	}
	return arr;
}

Block** Map::getMap()
{
	return this->map;
}

Map::~Map()
{
}