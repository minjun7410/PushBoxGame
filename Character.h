#include "Block.h"
#include "Action.h"

class Character : public Action{
private:
	int xCoordinate;
	int yCoordinate;
public:
	Character();
	Character(int x, int y);
	void setXCoordinate(int x);
	void setYCoordinate(int y);
	int getXCoordinate() const;
	int getYCoordinate() const;
	void move(int destinationX, int destinationY, Block &block, Block **map);
	void translocate(int destinationX, int destinationY, Block &block, Block **map);
	~Character();
};