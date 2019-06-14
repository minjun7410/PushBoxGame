#include "stdafx.h"
#include "Character.h"

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

void Character::move(Block block)
{
	if (block.getCanStand) {
		this->setXCoordinate();
	}
}

Character::~Character() {
}