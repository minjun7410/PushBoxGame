#include "stdafx.h"
#include "Character.h"
#include "Block.h"
#include "Map.h"
#include "Stage.h"
#include <iostream>

int main() {

	Stage stage = Stage();
	stage.loadStage(1);
	Character user = Character(stage.getStartingCharacterXCoordinate(), stage.getStartingCharacterYCoordinate());
	/*
	Character user = Character();
	user.setXCoordinate(stage.getStartingCharacterXCoordinate());
	user.setYCoordinate(stage.getStartingCharacterYCoordinate());
	*/
	Map mapCreator = Map(stage.getStageSizeofRow(), stage.getStageSizeofColumn() , stage.getMatrix());
	Block** map = mapCreator.getMap();

	// ¸Ê ÁÂÇ¥ Ãâ·Â
	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 7; k++) {
		// std::cout << map[k][i].getMovable() << " ";
		std::cout << "(" << map[k][i].getXCoordinate() << "," << map[k][i].getYCoordinate() << ")" << " ";
		}
		std::cout << std::endl;
	}

	while (true) {
	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 7; k++) {
		if (k == user.getXCoordinate() && i == user.getYCoordinate()) {
		std::cout << "M" << " ";
		}
		else {
		std::cout << map[k][i].getCanStand() << " ";
		}
	}
	std::cout << std::endl;
	}
	std::cout << "my Character: " << user.getXCoordinate() << "," << user.getYCoordinate() << "\n";

	// Ä³¸¯ÅÍ ¿òÁ÷ÀÓ
	int x, y;
	std::cin >> x >> y;
	user.move(x, y, map[x][y], map);
	}

	/* int list[9][7] =
	{ { 1,1,1,1,4,4,4 },
	{ 1,3,0,1,1,4,4 },
	{ 1,3,0,0,1,4,4 },
	{ 1,3,0,2,1,4,4 },
	{ 1,1,2,2,1,1,1 },
	{ 4,1,0,0,0,0,1 },
	{ 4,1,0,0,0,0,1 },
	{ 4,1,0,0,1,1,1 },
	{ 4,1,1,1,1,4,4 } };

	int** dynamicList = new int*[9];
	for (int i = 0; i < 9; i++) {
		dynamicList[i] = new int[7];
	}

	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 7; k++) {
			dynamicList[i][k] = list[i][k];
		}
	}

	Map myMap = Map(9, 7, dynamicList);
	myMap.getMap();

	// reversed int array
	int** reversedList = new int*[7];
	for (int i = 0; i < 7; i++) {
		reversedList[i] = new int[9];
	}
	for (int i = 0; i < 7; i++) {
		for (int k = 0; k < 9; k++) {
			reversedList[i][k] = list[k][i];
		}
	}

	// map
	Block** map = new Block*[7];
	for (int i = 0; i < 7; i++) {
		map[i] = new Block[9];
	}

	for (int i = 0; i < 7; i++) {
		for (int k = 0; k < 9; k++) {
			switch (reversedList[i][k]) {
			case 0:
				map[i][k] = Block(i, k, false, true, 0);
				break;
			case 1:
				map[i][k] = Block(i, k, false, false, 0);
				break;
			case 2:
				map[i][k] = Block(i, k, true, false, 0);
				break;
			case 3:
				map[i][k] = Block(i, k, false, true, 0);
				break;
			case 4:
				map[i][k] = Block(i, k, false, false, 0);
				break;
			}
		}
	} */


	// ¸Ê ÁÂÇ¥ Ãâ·Â
/*	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 7; k++) {
			std::cout << map[k][i].getMovable() << " ";
			// std::cout << "(" << map[k][i].getXCoordinate() << "," << map[k][i].getYCoordinate() << ")" << " ";
		}
		std::cout << std::endl;
	} */

	// Character myCharacter = Character(3, 2);


	// std::cout << myCharacter.getXCoordinate() << "," << myCharacter.getYCoordinate() << "\n";

	// ¸Ê ÁÂÇ¥ Ãâ·Â
	
	/*while (true) {
		for (int i = 0; i < 9; i++) {
			for (int k = 0; k < 7; k++) {
				if (k == myCharacter.getXCoordinate() && i == myCharacter.getYCoordinate()) {
					std::cout << "M" << " ";
				}
				else {
					std::cout << map[k][i].getCanStand() << " ";
				}
			}
			std::cout << std::endl;
		}
		std::cout << "my Character: " << myCharacter.getXCoordinate() << "," << myCharacter.getYCoordinate() << "\n";

		// Ä³¸¯ÅÍ ¿òÁ÷ÀÓ
		int x, y;
		std::cin >> x >> y;
		myCharacter.move(x, y, map[x][y], map);
	} */

}