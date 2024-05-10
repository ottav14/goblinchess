#include <ncurses.h>
#include <stdio.h>
#include "display.h"
#include "board.h"

#define squareLength 2

char board[8][8];

void init_ncurses() {

    // Initialize NCurses
    initscr();
    cbreak(); // Disable line buffering
    noecho(); // Don't echo input characters
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
	char board[8][8];
	reset_board(board);

	display_loop(board, stdscr);

	refresh();

}

int main() {


	init_ncurses();

	int ch;
	while ((ch = getch()) != 'q') {
		display_loop(board, stdscr);
	}

    // Clean up
    endwin();

    return 0;

}

