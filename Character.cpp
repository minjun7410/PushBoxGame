#include "stdafx.h"
#include "Character.h"
#include <iostream>

Character::Character() {
};

Character::Character(int x, int y){
	this->xCoordinate = x;
	this->yCoordinate = y;
};

void Character::setXCoordinate(int x) {
	this->xCoordinate = x;
}

void Character::setYCoordinate(int y) {
	this->yCoordinate = y;
}

int Character::getXCoordinate() const{
	return this->xCoordinate;
}

int Character::getYCoordinate() const{
	return this->yCoordinate;
}

void Character::move(int destinationX,int destinationY, Block &block, Block **map)
{
	std::cout << "Movable: " << block.getMovable() << std::endl;
	std::cout << "canStand: " << block.getCanStand() << std::endl;
	if (block.getCanStand()) {
		this->xCoordinate = block.getXCoordinate();
		this->yCoordinate = block.getYCoordinate();
		return;
	}
	if (block.getMovable()) {
		translocate(destinationX, destinationY, block, map);
	}
}
void Character::translocate(int destinationX, int destinationY, Block &block, Block **map) {
	int differenceByOneBlockOnAxisToX = destinationX - this->xCoordinate;
	int differenceByOneBlockOnAxisToY = destinationY - this->yCoordinate;
	// std::cout << "myX: " << this->xCoordinate << " myY: " << this->yCoordinate << std::endl;
	// std::cout << "differenceByOneBlockOnAxisToX: " << differenceByOneBlockOnAxisToX << " differenceByOneBlockOnAxisToY: " << differenceByOneBlockOnAxisToY << std::endl;
	Block nextBlock = map[destinationX + differenceByOneBlockOnAxisToX][destinationY + differenceByOneBlockOnAxisToY];
	if (nextBlock.getCanStand()) {
		Block characterStoodBlock = map[this->xCoordinate][this->yCoordinate];
		map[nextBlock.getXCoordinate()][nextBlock.getYCoordinate()] = block;
		map[destinationX][destinationY] = Block(destinationX, destinationY, false, true, 0);
		move(destinationX, destinationY, map[destinationX][destinationY], map);
	}
	else {
		return;
	}
}

Character::~Character() {
}