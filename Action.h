#include "Block.h"

#pragma once

class Action {
public:
	Action();
	int getStep() const;
	int getPush() const;
	virtual void move(int destinationX, int destinationY, Block block) const;
	virtual void translocate(Block block) const;
	~Action();
private:
	int nStep;
	int nPush;
	int nLevel;
};