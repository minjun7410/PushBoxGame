#include "Block.h"

Block::Block(bool movable, bool canStand, int c) {
	this->isMovable = movable;
	this->canStand = canStand;
	this->color = c;
}

bool Block::getMovable() {
	return this->isMovable;
}

bool Block::getCanStand() {
	return this->canStand;
}

int Block::getColor() {
	return this->color;
}

Block::~Block() {
}