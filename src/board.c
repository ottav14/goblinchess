#include <string.h>
#include <stdio.h>
#include "board.h"

void reset_board(Board b) {

	// Pawns
	for(int i=0; i<8; i++) {
		b[1][i][0] = 'P';
		b[6][i][0] = 'P';
	}

	// Kings
	b[0][4][0] = 'K';
	b[7][4][0] = 'K';

	// Queens
	b[0][3][0] = 'Q';
	b[7][3][0] = 'Q';

	// Rooks
	b[0][0][0] = 'R';
	b[0][7][0] = 'R';
	b[7][0][0] = 'R';
	b[7][7][0] = 'R';

    // Knights
	b[0][1][0] = 'N';
	b[0][6][0] = 'N';
	b[7][1][0] = 'N';
	b[7][6][0] = 'N';

    // Bishops
	b[0][2][0] = 'B';
	b[0][5][0] = 'B';
	b[7][2][0] = 'B';
	b[7][5][0] = 'B';

	// Empty
	for(int i=2; i<6; i++) {
		for(int j=0; j<8; j++) {
			b[i][j][0] = ' ';
		}
	}

	// Colors
	for(int i=0; i<2; i++) {
		for(int j=0; j<8; j++) {
			b[i][j][1] = 'B';
			b[7-i][j][1] = 'W';
		}	
	}

	
}


void print_board(Board b) {

	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			printf("%s  ", b[i][j]);
		}
	}

}
