#include "stdafx.h"
#include "Block.h"

Block::Block() {

}

Block::Block(int x, int y, bool movable, bool canStand, int c) {
	this->xCoordinate = x;
	this->yCoordinate = y;
	this->isMovable = movable;
	this->canStand = canStand;
	this->color = c;
}

int Block::getXCoordinate() const {
	return this->xCoordinate;
}

int Block::getYCoordinate() const {
	return this->yCoordinate;
}

bool Block::getMovable() const {
	return this->isMovable;
}

bool Block::getCanStand() const {
	return this->canStand;
}

int Block::getColor() const {
	return this->color;
}

Block::~Block() {
}