#include <ncurses.h>
#include <stdio.h>
#include "Display.h"
#include "Board.h"

const int square_length = 3;

void display_loop(Board b, WINDOW *win, char current_move[2]) {

	wbkgd(win, COLOR_PAIR(1));
	draw_board(win);
	draw_pieces(b, win);
	draw_current_move(current_move, win);

}

void draw_square(const int x, const int y, const int l, const int c, WINDOW *win) {

	wattron(win, COLOR_PAIR(c));
	for(int i=0; i<l; i++) {
		for(int j=0; j<l; j++) {
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
		
			const int x = width / 2 - (4 - j) * square_length;
			const int y = height / 2 - (4 - i) * square_length;
			const int c = 2*((i + j) % 2 + 1);

			draw_square(x, y, square_length, c, win);

		}
	}

}

void draw_pieces(Board b, WINDOW *win) {

	// Get terminal size
	int width, height;
	getmaxyx(stdscr, height, width);

	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
		
			char p[2];
			get_piece(b, j, i, p);
	
			const int x = width / 2 + (j - 4) * square_length + square_length / 2; 
			const int y = height / 2 + (i - 4) * square_length + square_length / 2; 
			const int c = 2*((i + j) % 2 + 1) + (p[1] == 'B');


			// Draw piece at (x, y)
			wattron(win, COLOR_PAIR(c));
			mvwprintw(win, y, x, "%c", p[0]);
			

		}
	}


}

void draw_current_move(char current_move[2], WINDOW *win) {

	mvwprintw(win, 10, 10, "Current move: %c%c", current_move[0], current_move[1]);	

}

