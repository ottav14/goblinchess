#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Board.h"


// Returns pointer to all squares with p on them

Piece* getPiece(Board b, int x, int y) {
	return &b[y][x];
}

void setPiece(Board b, int x, int y, char p, char q) {

	b[y][x][0] = p;
	b[y][x][1] = q;	

}

void coordToSquare(int x, int y, Square* s) {
	char letters[8] = {'a', 'b', 'c',
					   'd', 'e', 'f',
					   'g', 'h'};
	
	// Convert x to letter
	**s = letters[x];

	// Convert y to char	
	char charY[1];
	sprintf(charY, "%d", y);
	*(*s + 1) = *charY;

}
	 

void resetBoard(Board b) {


	// Pawns
	for(int i=0; i<8; i++) {

		// Black
		setPiece(b, i, 1, 'P', 'B');

		// White
		setPiece(b, i, 6, 'P', 'W');

	}

	// Kings
	setPiece(b, 4, 0, 'K', 'B');
	setPiece(b, 4, 7, 'K', 'W');

	// Queens
	setPiece(b, 3, 0, 'Q', 'B');
	setPiece(b, 3, 7, 'Q', 'W');

	// Rooks
	setPiece(b, 0, 0, 'R', 'B');
	setPiece(b, 7, 0, 'R', 'B');
	setPiece(b, 0, 7, 'R', 'W');
	setPiece(b, 7, 7, 'R', 'W');

	// Bishops
	setPiece(b, 2, 0, 'B', 'B');
	setPiece(b, 5, 0, 'B', 'B');
	setPiece(b, 2, 7, 'B', 'W');
	setPiece(b, 5, 7, 'B', 'W');

	// Knights
	setPiece(b, 1, 0, 'N', 'B');
	setPiece(b, 6, 0, 'N', 'B');
	setPiece(b, 1, 7, 'N', 'W');
	setPiece(b, 6, 7, 'N', 'W');


	// Empty
	for(int i=2; i<6; i++) {
		for(int j=0; j<8; j++) {
			setPiece(b, j, i, ' ', ' ');
		}
	}


	
}

Move* getMoves(Board b, int x, int y) {

	Move* moves;
	Piece* piece = getPiece(b, x, y); 
	char type = **piece;
	
	switch(type) {

		case 'P':
			break;

	}	

	return moves;

}

void print_board(Board b) {

	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			printf("%s  ", b[i][j]);
		}
	}

}
