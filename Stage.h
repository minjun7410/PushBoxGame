
class Stage {
public:
	Stage();
	void loadStage(int level);
	int getStageLevel() const;
	int getStageSizeofRow() const;
	int getStageSizeofColumn() const;
	int getStartingCharacterXCoordinate() const;
	int getStartingCharacterYCoordinate() const;
	int** getMatrix() const;
	~Stage();
private:
	int nLevel;
	int stageSizeofRow;
	int stageSizeofColumn;
	int startingCharacterXCoordinate;
	int startingCharacterYCoordinate;
	int** Matrix;
};