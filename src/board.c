#include <string.h>
#include <stdio.h>
#include "board.h"

void reset_board(char board[8][8][3]) {

	// Pawns
	for(int i=0; i<8; i++) {
		strcpy(board[1][i], "PW");
		strcpy(board[6][i], "PB");
	}

	// Kings
	strcpy(board[0][4], "KW");
	strcpy(board[7][4], "KB");

	// Queens
	strcpy(board[0][3], "QW");
	strcpy(board[7][3], "QB");

	// Rooks
	strcpy(board[0][0], "RW");
	strcpy(board[0][7], "RW");
	strcpy(board[7][0], "RB");
	strcpy(board[7][7], "RB");

    // Knights
	strcpy(board[0][1], "NW");
	strcpy(board[0][6], "NW");
	strcpy(board[7][1], "NB");
	strcpy(board[7][6], "NB");

    // Bishops
	strcpy(board[0][2], "BW");
	strcpy(board[0][5], "BW");
	strcpy(board[7][2], "BB");
	strcpy(board[7][5], "BB");

	// Empty
	for(int i=2; i<6; i++) {
		for(int j=0; j<8; j++) {
			strcpy(board[i][j], "  ");
		}
	}

	
}


void print_board(char board[8][8][3]) {

	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			printf("%s  ", board[i][j]);
		}
	}

}
