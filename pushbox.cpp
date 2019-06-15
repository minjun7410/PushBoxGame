#include "stdafx.h"
#include "Character.h"
#include "Stage.h"
#include "Map.h"
void renderObject(Stage stage, Block** map, Character user);
int main(int argc, char ** argv) {

	Stage stage = Stage();
	Character user;
	Map mapCreator;
	Block** map;

	initscr();
	start_color();
	keypad(stdscr, TRUE);
	int windowY = 20;
	int windowX = 50;
	init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);
	init_pair(3, COLOR_RED, COLOR_RED);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);

	bkgd(COLOR_PAIR(4));

	noecho();//사용자 input에 대해서 화면에 출력이 안됨
	keypad(stdscr, TRUE);//여러가지 키 사용 가능
	curs_set(0);//안보이는 커서
	resize_term(windowY, windowX);
	mvprintw(5, windowX / 3 + 3, "Push Box Game");
	mvprintw(10, windowX / 3, "Start(s)");
	mvprintw(10, windowX / 3 * 2, "Quit(q)");
	char control = getch();
	while (control != 'q') {
		if (control == 's') {
			clear();
			mvprintw(5, windowX / 3 + 3, "Push Box Game");
			mvprintw(10, windowX / 4, "(1)");
			mvprintw(10, windowX / 4 + 8, "(2)");
			mvprintw(10, windowX / 4 + 16, "(3)");
			mvprintw(10, windowX / 4 + 24, "(4)");
			control = getch();
			bool isAllDestinationWoodBox = false;
			while (true) {//
				if ((isAllDestinationWoodBox == true) || (control == 'q')) {
					clear();
					mvprintw(5, windowX / 3 + 3, "Push Box Game");
					mvprintw(10, windowX / 4, "(1)");
					mvprintw(10, windowX / 4 + 8, "(2)");
					mvprintw(10, windowX / 4 + 16, "(3)");
					mvprintw(10, windowX / 4 + 24, "(4)");
					control = getch();
				}
				if (49 <= control || control <= 52) {
					stage.loadStage(control - 48);
					user.setXCoordinate(stage.getStartingCharacterXCoordinate());
					user.setYCoordinate(stage.getStartingCharacterYCoordinate());
					mapCreator = Map(stage.getStageSizeofRow(), stage.getStageSizeofColumn(), stage.getMatrix());
					Block** map = mapCreator.getMap();

					int** red = mapCreator.getDestinationCoordinateArray();

					renderObject(stage, map, user);
					refresh();
					WINDOW * state = newwin(8, 15, 0, 30);
					mvwprintw(state, 0, 0, "State Bar");
					mvwprintw(state, 2, 0, "Stage: ");
					char buff[256];
					sprintf_s(buff, "%d", stage.getStageLevel());
					mvwprintw(state, 2, 8, buff);
					mvwprintw(state, 4, 0, "push: ");
					mvwprintw(state, 4, 7, "0");
					mvwprintw(state, 6, 0, "step: ");
					mvwprintw(state, 6, 7, "0");
					wrefresh(state);

					int destinationX;
					int destinationY;
					int movedDistnaceofX = 0;
					while (control != 'q') {
						control = getch();

						switch (control) {
						case 'w':
							destinationX = user.getXCoordinate();
							destinationY = user.getYCoordinate() - 1;
							if (stage.getMatrix()[destinationY][destinationX] == 3) {
								user.move(destinationX, destinationY, map[destinationX][destinationY], map, 3);
							}
							else {
								user.move(destinationX, destinationY, map[destinationX][destinationY], map, 0);
							}
							break;
						case 's':
							destinationX = user.getXCoordinate();
							destinationY = user.getYCoordinate() + 1;
							if (stage.getMatrix()[destinationY][destinationX] == 3) {
								user.move(destinationX, destinationY, map[destinationX][destinationY], map, 3);
							}
							else {
								user.move(destinationX, destinationY, map[destinationX][destinationY], map, 0);
							}
							break;
						case 'a':
							destinationX = user.getXCoordinate() - 1;
							destinationY = user.getYCoordinate();
							if (stage.getMatrix()[destinationY][destinationX] == 3) {
								user.move(destinationX, destinationY, map[destinationX][destinationY], map, 3);
							}
							else {
								user.move(destinationX, destinationY, map[destinationX][destinationY], map, 0);
							}
							break;
						case 'd':
							destinationX = user.getXCoordinate() + 1;
							destinationY = user.getYCoordinate();
							if (stage.getMatrix()[destinationY][destinationX] == 3) {
								user.move(destinationX, destinationY, map[destinationX][destinationY], map, 3);
							}
							else {
								user.move(destinationX, destinationY, map[destinationX][destinationY], map, 0);
							}
							break;
						}

						renderObject(stage, map, user);
						refresh();
						WINDOW * state = newwin(8, 15, 0, 30);
						mvwprintw(state, 0, 0, "State Bar");
						mvwprintw(state, 2, 0, "Stage: ");
						char buff[256];
						sprintf_s(buff, "%d", stage.getStageLevel());
						mvwprintw(state, 2, 8, buff);
						mvwprintw(state, 4, 0, "push: ");
						char buff2[256];
						sprintf_s(buff2, "%d", user.getPush());
						mvwprintw(state, 4, 7, buff2);
						mvwprintw(state, 6, 0, "step: ");
						char buff3[256];
						sprintf_s(buff3, "%d", user.getStep());
						mvwprintw(state, 6, 7, buff3);
						wrefresh(state);

						isAllDestinationWoodBox = true;
						for (int i = 0; i < mapCreator.getDestinations(); i++) {
							if (map[red[i][0]][red[i][1]].getColor() != 2) {
								isAllDestinationWoodBox = false;
								break;
							}
						}
						if (isAllDestinationWoodBox) {
							user.clearInformation();
							clear();
							break;
						}
					}
					user.clearInformation();
				}
			}

			getch();
			endwin();
			return 0;
		}
	}
}

void renderObject(Stage stage, Block** map, Character user) {
	clear();
	for (int i = 0; i < stage.getStageSizeofColumn(); i++) {
		int x = i * 2;
		for (int j = 0; j < stage.getStageSizeofRow(); j++) {
			if ((i == user.getXCoordinate()) && (j == user.getYCoordinate())) {

				attron(COLOR_PAIR(5));
				mvprintw(j, x, " ");
				mvprintw(j, x + 1, " ");
				attroff(COLOR_PAIR(5));
				continue;
			}
			int color = map[i][j].getColor();
			attron(COLOR_PAIR(color));
			mvprintw(j, x, " ");
			mvprintw(j, x + 1, " ");
			attroff(COLOR_PAIR(color));
		}
	}
}