#include "stdafx.h"
int main(int argc, char ** argv) {
	
	initscr();
	start_color();
	int windowY = 20;
	int windowX = 50;
	init_color(COLOR_YELLOW, 5, 5, 0);
	init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);
	init_pair(3, COLOR_RED, COLOR_RED);
	init_pair(4, COLOR_WHITE, COLOR_WHITE);
	init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);

	bkgd(COLOR_PAIR(4));

	noecho();//사용자 input에 대해서 화면에 출력이 안됨
	keypad(stdscr, TRUE);//여러가지 키 사용 가능
	curs_set(0);//안보이는 커서

	int list[9][7] =
	{
		{1,1,1,1,4,4,4},
		{1,3,0,1,1,4,4},
		{1,3,0,0,1,4,4},
		{1,3,0,2,1,4,4},
		{1,1,2,0,1,1,1},
		{4,1,0,2,0,0,1},
		{4,1,0,0,0,0,1},
		{4,1,0,0,1,1,1},
		{4,1,1,1,1,4,4}
	};
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
	}
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

