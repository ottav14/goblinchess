#include "board.h"

void reset_board(char board [8][8]) {

	// Pawns
	for(int i=0; i<8; i++) {
		board[1][i] = 'P';
		board[6][i] = 'P';
	}

	// Kings
	board[0][4] = 'K';
	board[7][4] = 'K';

	// Queens
	board[0][3] = 'Q';
	board[7][3] = 'Q';

	// Rooks
	board[0][0] = 'R';
	board[0][7] = 'R';
	board[7][0] = 'R';
	board[7][7] = 'R';

    // Knights
	board[0][1] = 'N';
	board[0][6] = 'N';
	board[7][1] = 'N';
	board[7][6] = 'N';

    // Bishops
	board[0][2] = 'B';
	board[0][5] = 'B';
	board[7][2] = 'B';
	board[7][5] = 'B';

	// Empty
	for(int i=2; i<5; i++) {
		for(int j=0; j<7; j++) {
			board[i][j] = ' ';
		}
	}
	
}
