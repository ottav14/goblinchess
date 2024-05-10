#include <ncurses.h>
#include <stdio.h>
#include "display.h"
#include "board.h"

#define squareLength 2

char current_move[2];
int current_move_size = 0;

Board main_board;

void update_current_move(char input) {
	
	current_move_size += 1;
	if(current_move_size > 2) {
		current_move[1] = ' ';
		current_move_size = 1;
	}
	else if(current_move_size == 2) {
		current_move[1] = current_move[0];
	}
	current_move[0] = input;

}


void init_ncurses() {

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
	reset_board(main_board);


	display_loop(main_board, stdscr, current_move);

	refresh();

}


int main() {


	init_ncurses();

	int ch;
	while ((ch = getch()) != 'q') {
		update_current_move(ch);
		display_loop(main_board, stdscr, current_move);
	}

    // Clean up
    endwin();

    return 0;

}

