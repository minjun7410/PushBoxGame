#include "Character.h"
#include "stdafx.h"
Block* toBlock(int**);
int main(int argc, char ** argv) {
	//int 형 리스트를 Block형 리스트로 바꾸기
	int list[9][7] =
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
	Block* list_block[sizeof(list)][sizeof(list[0])];
	for (int i = 0; i < (sizeof(list) / sizeof(*list)); i++) {
		for (int j = 0; j < (sizeof(list[0]) / sizeof(*list[0])); j++) {
			if (list[i][j] == 0) {
				list_block[i][j] = new Block(true, true, 0);
			}
			else if (list[i][j] == 1) {
				list_block[i][j] = new Block(false, false, 1);
			}
			else if (list[i][j] == 2) {
				list_block[i][j] = new Block(true, false, 2);
			}
			else if (list[i][j] == 3) {
				list_block[i][j] = new Block(false, true, 3);
			}
			else if (list[i][j] == 4) {
				list_block[i][j] = new Block(false, false, 4);
			}
		}
	}
	Character myCharacter = Character(1, 2);

	initscr();
	start_color();
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
	mvprintw(5, windowX / 3 + 3,"Push Box Game");
	mvprintw(10, windowX / 3, "Start(s)");
	mvprintw(10, windowX / 3 * 2, "Quit(q)");
	char control;
	while (control = getch()) {
		if (control == 'q') break;
		else if (control == 's') {
			clear();
			mvprintw(5, windowX / 3 + 3, "Push Box Game");
			mvprintw(10, windowX / 4, "(1)");
			mvprintw(10, windowX / 4 + 8, "(2)");
			mvprintw(10, windowX / 4 + 16, "(3)");
			mvprintw(10, windowX / 4 + 24, "(4)");
			while (control = getch()) {
				if (control == '1') {
					for (int i = 0; i < (sizeof(list_block) / sizeof(*list_block)); i++) {
						for (int j = 0; j < (sizeof(list_block[0]) / sizeof(*list_block[0])); j++) {
							int color = list_block[i][j].getColor();
							attron(COLOR_PAIR(list_block[i][j].getColor()));
				}
			}
		}
	}

	

	
	
	/*
			  //map
	for (int i = 0; i < (sizeof(list) / sizeof(*list)); i++) {
		x = 0;
		for (int j = 0; j < (sizeof(list[i]) / sizeof(*list[i])); j++) {
			attron(COLOR_PAIR(list[i][j]));
			mvprintw(y, x, " ");
			mvprintw(y, (++x), " ");
			attroff(COLOR_PAIR(list[i][j]));
			x++;
		}
		y++;
	}
	
	int cursor_x = 3 * 2;
	int cursor_y = 3;
	attron(COLOR_PAIR(5));
	mvprintw(cursor_y, cursor_x, " ");
	mvprintw(cursor_y, cursor_x + 1, " ");
	attroff(COLOR_PAIR(5));
	char control = getch();
	//방향키
	while (control != 'q'){
		int x = 0;//맵의 x
		int y = 0;//맵의 y
		//map
		for (int i = 0; i < (sizeof(list) / sizeof(*list)); i++) {
			x = 0;
			for (int j = 0; j < (sizeof(list[i]) / sizeof(*list[i])); j++) {
				attron(COLOR_PAIR(list[i][j]));
				mvprintw(y, x, " ");
				mvprintw(y, (++x), " ");
				attroff(COLOR_PAIR(list[i][j]));
				x++;
			}
			y++;
		}
		//A
		if((control == 'a')&&(cursor_x != 0)) {
			cursor_x -= 2;
		}//D
		else if ((control == 'd') && (cursor_x != sizeof(list[0]) / sizeof(*list[0]) * 2 - 2)) {
			cursor_x += 2;
		}//S
		else if ((control == 's') && (cursor_y != sizeof(list) / sizeof(*list) - 1)) {
			cursor_y += 1;
		}//W
		else if ((control == 'w') && (cursor_y != 0)) {
			cursor_y -= 1;
		}
		//표식
		attron(COLOR_PAIR(5));
		mvprintw(cursor_y, cursor_x, " ");
		mvprintw(cursor_y, cursor_x + 1, " ");
		attroff(COLOR_PAIR(5));
		control = getch();
	}*/
	getch();
	endwin();
	return 0;
}
/*
int main()
{
	char start = 's';
	int tries = 0;
	int y = 20;
	int x = 50;
	//setting
	initscr();
	start_color();
	noecho();
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_BLACK, COLOR_WHITE );
	init_pair(2, COLOR_BLACK, COLOR_RED);
	init_pair(3, COLOR_BLACK, COLOR_BLUE);
	//first window
	while (start != 'q') {
		resize_term(y,x);
		attron(COLOR_PAIR(2));
		border('*', '*', '*', '*', '*', '*', '*', '*');
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(2, 19, "Push Box Game");
		attroff(COLOR_PAIR(1));
		attron(COLOR_PAIR(1));
		mvprintw(7, 10, "Start(s)");
		mvprintw(7, 32, "Quit(q)");
		attroff(COLOR_PAIR(1));
		refresh();
		start = getch();
		//start window
		while (start == 's') {
			clear();
			WINDOW * win = newwin(20, 50, 0, 0);

			int Min_x, Min_y, Max_x, Max_y;
			getbegyx(win, Min_y, Min_x);
			getmaxyx(win, Max_y, Max_x);
			refresh();
			char c = '-';
			char d = '|';
			char e = '*';
			wborder(win, int(d), int(d),int(c),int(c),int(e),int(e),int(e),int(e));
			mvwprintw(win, 1,2, "LEVEL");
			wrefresh(win);
			attron(COLOR_PAIR(1));
			mvprintw(Max_y / 2 -1, 6, "(1)" );
			mvprintw(Max_y / 2 -1, 11, "(2)");
			mvprintw(Max_y / 2 -1, 16, "(3)");
			mvprintw(Max_y / 2 -1, 21, "(4)");
			mvprintw(Max_y / 2 -1, 26, "(5)");
			mvprintw(Max_y / 2 -1, 31, "(6)");
			mvprintw(Max_y / 2 -1, 36, "(7)");
			mvprintw(Max_y / 2 -1, 41, "(8)");
			attroff(COLOR_PAIR(1));
			refresh();
			
			while (true) {
				int click = getch();
				if(c == KEY_UP){}
			}
		}
	}
	endwin();
    return 0;
}
*/
Block* toBlock(int** list) {
	Block* list_block[sizeof(list)][sizeof(list[0])];
	for (int i = 0; i < (sizeof(list) / sizeof(*list)); i++) {
		for (int j = 0; j < (sizeof(list[0]) / sizeof(*list[0])); j++) {
			if (list[i][j] == 0) {
				list_block[i][j] = new Block(true, true, 0);
			}
			else if (list[i][j] == 1) {
				list_block[i][j] = new Block(false, false, 1);
			}
			else if (list[i][j] == 2) {
				list_block[i][j] = new Block(true, false, 2);
			}
			else if (list[i][j] == 3) {
				list_block[i][j] = new Block(false, true, 3);
			}
			else if (list[i][j] == 4) {
				list_block[i][j] = new Block(false, false, 4);
			}
		}

	}
	return **list_block;
}