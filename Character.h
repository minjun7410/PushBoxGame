#include "Move.h"

#pragma once

class Character : public Move{
private:
	int xCoordinate;
	int yCoordinate;
public:
	Character(int x, int y);
	void setXCoordinate(int x);
	void setYCoordinate(int y);
	int getXCoordinate();
	int getYCoordinate();
	~Character();
};