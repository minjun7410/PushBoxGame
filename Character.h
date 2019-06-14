#include "Action.h"

#pragma once

class Character : public Action{
private:
	int xCoordinate;
	int yCoordinate;
public:
	Character(int x, int y);
	void setXCoordinate(int x);
	void setYCoordinate(int y);
	int getXCoordinate() const;
	int getYCoordinate() const;
	void move(Block block);
	~Character();
};