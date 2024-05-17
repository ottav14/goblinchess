#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include "Display.h"
#include "Board.h"

#define squareLength 2

char currentMove[3];
int currentMoveSize = 0;

Board mainBoard;

void resetCurrentMove() {
	for(int i=0; i<3; i++) {
		currentMove[i] = ' ';
	}
}

void updateCurrentMove(char input) {
	
	currentMoveSize += 1;

	if(currentMoveSize > 3) {
		resetCurrentMove();
		currentMoveSize = 0;
	}
	else {
		currentMove[currentMoveSize-1] = input;
	}

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
	//
	// Board black: green
	// Board white: yellow
	// 
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
	resetBoard(mainBoard);


	displayLoop(mainBoard, stdscr, currentMove);

	refresh();

}


int main() {


	init_ncurses();
	
	Square* s;
	coordToSquare(3, 5, s);
	mvprintw(0, 0, "%c %c\n", **s, *(*s + 1));
	


	int ch;
	while((ch = getch()) != 'q') {
		updateCurrentMove(ch);
		displayLoop(mainBoard, stdscr, currentMove);
		refresh();
	}

    // Clean up
    endwin();

    return 0;

}

