#include <ncurses.h>
#include "display.h"

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
	init_pair(1, COLOR_WHITE, COLOR_BLUE); 
	init_pair(2, COLOR_WHITE, COLOR_BLACK); 
	init_pair(3, COLOR_WHITE, COLOR_WHITE); 

	// Get terminal size
	int width, height;
	getmaxyx(stdscr, height, width);

	char board[8][8];

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

