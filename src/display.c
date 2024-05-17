#include <ncurses.h>
#include <stdio.h>
#include "Display.h"
#include "Board.h"

const int squareLength = 3;

void displayLoop(Board b, WINDOW *win, char currentMove[2]) {

	wbkgd(win, COLOR_PAIR(1));
	drawBoard(win);
	drawPieces(b, win);
	drawCurrentMove(currentMove, win);

}

void drawSquare(const int x, const int y, const int l, const int c, WINDOW *win) {

	wattron(win, COLOR_PAIR(c));
	for(int i=0; i<l; i++) {
		for(int j=0; j<l; j++) {
			mvwprintw(win, y+i, x+j, " ");
		}
	}
}

void drawBoard(WINDOW *win) {

	// Get terminal size
	int width, height;
	getmaxyx(stdscr, height, width);


	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
		
			const int x = width / 2 - (4 - j) * squareLength;
			const int y = height / 2 - (4 - i) * squareLength;
			const int c = 2*((i + j) % 2 + 1);

			drawSquare(x, y, squareLength, c, win);

		}
	}

}

void drawPieces(Board b, WINDOW *win) {

	// Get terminal size
	int width, height;
	getmaxyx(stdscr, height, width);

	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
		
	
			const int x = width / 2 + (j - 4) * squareLength + squareLength / 2; 
			const int y = height / 2 + (i - 4) * squareLength + squareLength / 2; 
			const int c = 2*((i + j) % 2 + 1) + (b[i][j][1] == 'B');


			// Draw piece at (x, y)
			wattron(win, COLOR_PAIR(c));
			mvwprintw(win, y, x, "%c", b[i][j][0]);

		}
	}


}

void drawCurrentMove(char currentMove[2], WINDOW *win) {

	mvwprintw(win, 10, 10, "Current move: %c%c%c", currentMove[0], currentMove[1], currentMove[2]);	

}

