#include "Block.h"

#pragma once

class Action {
public:
	Action();
	virtual void move(Block block) const;
	~Action();

};