#include "stdafx.h"

#pragma once
class Block {
private:
	bool isMovable;
	bool canStand;
	int color;
public:
	Block(bool moveable, bool standable, int c);
	bool getMovable();
	bool getCanStand();
	int getColor();
	~Block();
};
