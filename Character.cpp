#include "Character.h"

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

int Character::getXCoordinate() {
	return this->xCoordinate;
}

int Character::getYCoordinate() {
	return this->yCoordinate;
}

Character::~Character() {
}