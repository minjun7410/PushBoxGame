#include "stdafx.h"
#include "Action.h"

Action::Action() {

}
int Action::getStep() const
{
	return this->nStep;
}
int Action::getPush() const
{
	return this->nPush;
}
void Action::move(int destinationX, int destinationY, Block block) const{

}
void Action::translocate(Block block) const {

}
Action::~Action() {

}


