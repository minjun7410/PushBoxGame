#include "stdafx.h"
#include "Stage.h"

static const int stageOne[9][7] =
{
{ 1,1,1,1,4,4,4 },
{ 1,3,0,1,1,4,4 },
{ 1,3,0,0,1,4,4 },
{ 1,3,0,2,1,4,4 },
{ 1,1,2,0,1,1,1 },
{ 4,1,0,2,0,0,1 },
{ 4,1,0,0,0,0,1 },
{ 4,1,0,0,1,1,1 },
{ 4,1,1,1,1,4,4 }
};
static const int stageTwo[7][7] =
{
{ 1,1,1,1,1,1,1 },
{ 1,0,3,0,3,0,1 },
{ 1,3,2,2,2,3,1 },
{ 1,0,2,0,2,0,1 },
{ 1,3,2,2,2,3,1 },
{ 1,0,3,0,3,0,1 },
{ 1,1,1,1,1,1,1 }
};
static const int stageThree[5][8] =
{
{ 1,1,1,1,1,1,1,1 },
{ 1,3,0,0,1,0,0,1 },
{ 1,0,0,2,2,2,0,1 },
{ 1,3,3,0,0,0,0,1 },
{ 1,1,1,1,1,1,1,1 }
};
static const int stageFour[8][8] =
{
{ 0,1,1,1,1,1,0,0 },
{ 0,1,0,0,1,1,1,0 },
{ 0,1,0,2,0,0,1,0 },
{ 1,1,1,0,1,0,1,1 },
{ 1,3,1,0,1,0,0,1 },
{ 1,3,2,0,0,1,0,1 },
{ 1,3,0,0,0,2,0,1 },
{ 1,1,1,1,1,1,1,1 }
};

Stage::Stage() {
}
void Stage::loadStage(int level) {
	switch (level) {
	case 1:
		this->nLevel = 1;
		this->stageSizeofRow = 9;
		this->stageSizeofColumn = 7;
		this->startingCharacterXCoordinate = 2;
		this->startingCharacterYCoordinate = 2;

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
		this->nLevel = 2;
		this->stageSizeofRow = 7;
		this->stageSizeofColumn = 7;
		this->startingCharacterXCoordinate = 3;
		this->startingCharacterYCoordinate = 3;

		for (int i = 0; i < stageSizeofRow; i++) {
			this->Matrix[i] = new int[stageSizeofColumn];
		}
		for (int i = 0; i < stageSizeofRow; i++) {
			for (int k = 0; k < stageSizeofColumn; k++) {
				this->Matrix[i][k] = stageTwo[i][k];
			}
		}
		break;
	case 3:
		this->nLevel = 3;
		this->stageSizeofRow = 5;
		this->stageSizeofColumn = 8;
		this->startingCharacterXCoordinate = 2;
		this->startingCharacterYCoordinate = 1;

		for (int i = 0; i < stageSizeofRow; i++) {
			this->Matrix[i] = new int[stageSizeofColumn];
		}
		for (int i = 0; i < stageSizeofRow; i++) {
			for (int k = 0; k < stageSizeofColumn; k++) {
				this->Matrix[i][k] = stageThree[i][k];
			}
		}
		break;
	case 4:
		this->nLevel = 4;
		this->stageSizeofRow = 8;
		this->stageSizeofColumn = 8;
		this->startingCharacterXCoordinate = 2;
		this->startingCharacterYCoordinate = 2;

		for (int i = 0; i < stageSizeofRow; i++) {
			this->Matrix[i] = new int[stageSizeofColumn];
		}
		for (int i = 0; i < stageSizeofRow; i++) {
			for (int k = 0; k < stageSizeofColumn; k++) {
				this->Matrix[i][k] = stageFour[i][k];
			}
		}
		break;
	}
}
int Stage::getStageLevel() const {
	return this->nLevel;
}
int Stage::getStageSizeofRow() const
{
	return this->stageSizeofRow;
}
int Stage::getStageSizeofColumn() const
{
	return this->stageSizeofColumn;
}
int Stage::getStartingCharacterXCoordinate() const
{
	return this->startingCharacterXCoordinate;
}
int Stage::getStartingCharacterYCoordinate() const
{
	return this->startingCharacterYCoordinate;
}
int** Stage::getMatrix() const {
	return this->Matrix;
}
Stage::~Stage() {

}
