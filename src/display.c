#include <ncurses.h>
#include "display.h"

void display_loop() {

	wbkgd(stdscr, COLOR_PAIR(1));
	draw_board();
	refresh();

}

void init_ncurses() {

    // Initialize NCurses
    initscr();
    cbreak(); // Disable line buffering
    noecho(); // Don't echo input characters
    keypad(stdscr, TRUE); // Enable keypad mode
	start_color();

	// Define color pairs
	init_pair(1, COLOR_WHITE, COLOR_BLUE); 
	init_pair(2, COLOR_WHITE, COLOR_BLACK); 
	init_pair(3, COLOR_WHITE, COLOR_WHITE); 

	display_loop();

	int ch;
	while ((ch = getch()) != 'q') {
		display_loop();
	}

	// Cleanup and exit
	endwin();
}

void draw_square(const int x, const int y, const int w, const int h, const int c) {

	for(int i=0; i<h; i++) {
		move(y + i, x);
		attron(COLOR_PAIR(c));
		for(int j=0; j<w; j++) {
			printw(" ");
		}
	}
}

void draw_board() {

	const int square_width = 4;
	const int square_height = 3;

	// Get terminal size
	int width, height;
	getmaxyx(stdscr, height, width);

	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
		
			const int x = width / 2 - (3 - j) * square_width;
			const int y = height / 2 - (3 - i) * square_height;
			const int c = (i + j) % 2 + 2;

			draw_square(x, y, square_width, square_height, c);

		}
	}

}


