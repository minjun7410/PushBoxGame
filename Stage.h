#pragma once

class Stage {
public:
	Stage();
	void loadStage(int level);
	int** getMatrix() const;
	int getStageLevel() const;
	int getStageSizeofRow() const;
	int getStageSizeofColumn() const;
	~Stage();
private:
	int stageLevel;
	int stageSizeofRow;
	int stageSizeofColumn;
	int** Matrix;
};