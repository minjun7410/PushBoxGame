#include "stdafx.h"
#include "Stage.h"

static const int stageOne[9][7] =
{
{ 1,1,1,1,4,4,4 },
{ 1,3,0,1,1,4,4 },
{ 1,3,0,0,1,4,4 },
{ 1,3,0,2,1,4,4 },
{ 1,1,2,2,1,1,1 },
{ 4,1,0,0,0,0,1 },
{ 4,1,0,0,0,0,1 },
{ 4,1,0,0,1,1,1 },
{ 4,1,1,1,1,4,4 }
};
static const int stageTwo[7][7] = 
{//시작위치 x4y4
	{1,1,1,1,1,1,1},
	{1,0,3,0,3,0,1},
	{1,3,2,2,2,3,1},
	{1,0,2,0,2,0,1},
	{1,3,2,2,2,3,1},
	{1,0,3,0,3,0,1},
	{1,1,1,1,1,1,1}
};
static const int stageThree[5][8] =
{//x3y2
	{1,1,1,1,1,1,1,1},
	{1,3,0,0,1,0,0,1},
	{1,0,0,2,2,2,0,1},
	{1,3,3,0,0,0,0,1},
	{1,1,1,1,1,1,1,1}
};
static const int stageFour[8][8] = 
{//x3y3
	{0,1,1,1,1,1,0,0},
	{0,1,0,0,1,1,1,0},
	{0,1,0,2,0,0,1,0},
	{1,1,1,0,1,0,1,1},
	{1,3,1,0,1,0,0,1},
	{1,3,2,0,0,1,0,1},
	{1,3,0,0,0,2,0,1},
	{1,1,1,1,1,1,1,1}
};
Stage::Stage() {
	this->stageLevel = 0;
	this->stageSizeofRow = 0;
	this->stageSizeofColumn = 0;
	this->Matrix;
}
void Stage::loadStage(int level) {
	switch (level) {
	case 1:
		this->stageLevel = 1;
		this->stageSizeofRow = 9;
		this->stageSizeofColumn = 7;
		this->Matrix = new int*[stageSizeofRow];
		for (int i = 0; i < stageSizeofRow; i++) {
			this->Matrix[i] = new int[stageSizeofColumn];
		}
		for (int i = 0; i < stageSizeofRow; i++) {
			for (int k = 0; k < stageSizeofColumn; k++) {
				this->Matrix[i][k] = stageOne[i][k];
			}
		}
		break;
	case 2:
		this->stageLevel = 2;
		this->stageSizeofRow = 0;
		this->stageSizeofColumn = 0;
		break;
	case 3:
		this->stageLevel = 3;
		this->stageSizeofRow = 0;
		this->stageSizeofColumn = 0;
		break;
	case 4:
		this->stageLevel = 4;
		this->stageSizeofRow = 0;
		this->stageSizeofColumn = 0;
		break;
	}
}
int Stage::getStageLevel() const {
	return this->stageLevel;
}
int Stage::getStageSizeofRow() const
{
	return this->stageSizeofRow;
}
int Stage::getStageSizeofColumn() const
{
	return this->stageSizeofColumn;
}
int** Stage::getMatrix() const {
	return this->Matrix;
}
Stage::~Stage() {

}
