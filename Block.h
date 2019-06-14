#include "stdafx.h"

#pragma once
class Block {
private:
	int xCoordinate;
	int yCoordinate;
	bool isMovable;
	bool canStand;
	int color;
public:
	Block();
	Block(int x, int y, bool movable, bool canStand, int c);
	int getXCoordinate() const;
	int getYCoordinate() const;
	bool getMovable() const;
	bool getCanStand() const;
	int getColor() const;
	~Block();
};
