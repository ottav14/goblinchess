#include <ncurses.h>
#include <stdio.h>
#include "display.h"
#include "board.h"

#define squareLength 2

void init_ncurses(char board[8][8][3]) {

    // Initialize NCurses
    initscr();
    cbreak(); // Disable line buffering
    noecho(); // Don't echo input characters
	curs_set(0); //Hide cursor
    keypad(stdscr, TRUE); // Enable keypad mode
	start_color();

	// Define color pairs
	// Board black: green
	// Board white: yellow
	//        #      FG           BG
	init_pair(1, COLOR_WHITE, COLOR_BLUE);  // Background
	init_pair(2, COLOR_WHITE, COLOR_GREEN); // White on Black
	init_pair(3, COLOR_BLACK, COLOR_GREEN); // Black on Black
	init_pair(4, COLOR_WHITE, COLOR_YELLOW); // White on White
	init_pair(5, COLOR_BLACK, COLOR_YELLOW); // Black on White

	// Get terminal size
	int width, height;
	getmaxyx(stdscr, height, width);

	// Initialize board
	reset_board(board);


	display_loop(board, stdscr);

	refresh();

}

int main() {

	char board[8][8][3];

	init_ncurses(board);

	int ch;
	while ((ch = getch()) != 'q') {
		display_loop(board, stdscr);
	}

    // Clean up
    endwin();

    return 0;

}

