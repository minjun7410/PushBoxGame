#include "stdafx.h"
#include "Action.h"

Action::Action() {

}void Action::setStep(int n) {
	this->nStep = n;
}
void Action::setPush(int n) {
	this->nPush = n;;
}
int Action::getStep() const
{
	return this->nStep;
}
int Action::getPush() const
{
	return this->nPush;
}
void Action::increaseStep() {
	this->nStep++;
}
void Action::increasePush() {
	this->nPush++;
}
void Action::move(int destinationX, int destinationY, Block block) const {

}
void Action::translocate(Block block) const {

}
Action::~Action() {

}