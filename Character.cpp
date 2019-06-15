#include "stdafx.h"
#include "Character.h"

Character::Character() {
};

Character::Character(int x, int y) {
	this->xCoordinate = x;
	this->yCoordinate = y;
};

void Character::setXCoordinate(int x) {
	this->xCoordinate = x;
}

void Character::setYCoordinate(int y) {
	this->yCoordinate = y;
}

int Character::getXCoordinate() const {
	return this->xCoordinate;
}

int Character::getYCoordinate() const {
	return this->yCoordinate;
}

void Character::move(int destinationX, int destinationY, Block &block, Block **map, int willStepBlockColor)
{
	if (block.getCanStand()) {
		this->xCoordinate = block.getXCoordinate();
		this->yCoordinate = block.getYCoordinate();
		this->increaseStep();
		return;
	}
	if (block.getMovable()) {
		translocate(destinationX, destinationY, block, map, willStepBlockColor);
	}
}
void Character::translocate(int destinationX, int destinationY, Block &block, Block **map, int willStepBlockColor) {
	int differenceByOneBlockOnAxisToX = destinationX - this->xCoordinate;
	int differenceByOneBlockOnAxisToY = destinationY - this->yCoordinate;
	Block nextBlock = map[destinationX + differenceByOneBlockOnAxisToX][destinationY + differenceByOneBlockOnAxisToY];
	if (nextBlock.getCanStand()) {
		Block characterStoodBlock = map[this->xCoordinate][this->yCoordinate];
		map[nextBlock.getXCoordinate()][nextBlock.getYCoordinate()] = block;
		map[destinationX][destinationY] = Block(destinationX, destinationY, false, true, willStepBlockColor);
		move(destinationX, destinationY, map[destinationX][destinationY], map, willStepBlockColor);
		this->increasePush();
	}
	else {
		return;
	}
}

void Character::clearInformation() {
	this->setStep(0);
	this->setPush(0);
}

Character::~Character() {}