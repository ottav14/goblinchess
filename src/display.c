#include <ncurses.h>
#include "display.h"

const int square_width = 3;
const int square_height = 3;

char d_board[8][8];

void display_loop(char board[8][8], WINDOW *win) {

	wbkgd(win, COLOR_PAIR(1));
	draw_board(win);
	draw_pieces(board, win);
	

	

}

void draw_square(const int x, const int y, const int w, const int h, const int c, WINDOW *win) {

	wattron(win, COLOR_PAIR(c));
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++) {
			mvwprintw(win, y+i, x+j, " ");
		}
	}
}

void draw_board(WINDOW *win) {

	// Get terminal size
	int width, height;
	getmaxyx(stdscr, height, width);


	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
		
			const int x = width / 2 - (4 - j) * square_width;
			const int y = height / 2 - (4 - i) * square_height;
			const int c = (i + j) % 2 + 2;

			draw_square(x, y, square_width, square_height, c, win);

		}
	}

}

void draw_pieces(char board[8][8], WINDOW *win) {

	// Get terminal size
	int width, height;
	getmaxyx(stdscr, height, width);

	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
		
			const int x = width / 2 - (4 - j) * square_width + square_width / 2;
			const int y = height / 2 - (4 - i) * square_height + square_height / 2;
			const int c = (i + j) % 2 + 2;

			wattron(win, COLOR_PAIR(c));
			mvwprintw(win, x, y, "%c", board[i][j]);

		}
	}



}


