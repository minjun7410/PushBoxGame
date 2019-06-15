#include "Block.h"

#pragma once

class Action {
public:
	Action();
	void setStep(int n);
	void setPush(int n);
	int getStep() const;
	int getPush() const;
	void increaseStep();
	void increasePush();
	virtual void move(int destinationX, int destinationY, Block block) const;
	virtual void translocate(Block block) const;
	~Action();
private:
	int nStep = 0;
	int nPush = 0;
};