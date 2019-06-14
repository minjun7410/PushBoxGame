#pragma once

class Map {
private:
	int sizeX;
	int sizeY;
	int** map = new int*[sizeX];
};