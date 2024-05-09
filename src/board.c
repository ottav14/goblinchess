#include "board.h"

void reset_board(char board [8][8]) {

	// Pawns
	for(int i=0; i<8; i++) {
		board[1][i] = 'p';
		board[6][i] = 'p';
	}

	// Kings
	board[0][4] = 'k';
	board[7][4] = 'k';

	// Queens
	board[0][3] = 'q';
	board[7][3] = 'q';

	// Rooks
	board[0][0] = 'r';
	board[0][7] = 'r';
	board[7][0] = 'r';
	board[7][7] = 'r';

    // Knights
	board[0][1] = 'n';
	board[0][6] = 'n';
	board[7][1] = 'n';
	board[7][6] = 'n';

    // Bishops
	board[0][2] = 'b';
	board[0][5] = 'b';
	board[7][2] = 'b';
	board[7][5] = 'b';
	
}
