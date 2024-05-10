#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Board.h"


// Returns pointer to all squares with p on them
Square* get_position(Board b, char p[2]) {

	Square* squares;
	int square_count = 0;

	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
		
			char q[2];
			get_piece(b, j, i, q);
			
			if(p[0] == q[0] && p[1] == q[1]) {
				square_count += 1;
				squares = realloc(squares, square_count * sizeof(Square));
				squares[square_count-1] = b[i][j];
			}
			 			

		}
	}

	return squares;


}

void get_piece(Board b, int x, int y, char *p) {

	Square s = b[y][x];
	memcpy(p, s.piece, 2*sizeof(char));
}

void set_piece(Board b, int x, int y, char p[2]) {

	Square s = b[y][x];
	memcpy(s.piece, p, 2*sizeof(char));

}

Move* get_moves(Board b, char p[2]) {


	char type = p[0];

	switch(type) {
		case 'P':
			break;
	}
	

	Move* m;

	return m;

}

int valid_move(Board b, Move m) {

	char type = m[0];
	

	return 0;

}

void reset_board(Board b) {





	// Pawns
	for(int i=0; i<8; i++) {


		char p[2] = {'P', 'B'};
		set_piece(b, i, 6, p);

//		b[6][i].piece = {'P', 'B'}; 
	}
/*

	// Kings
	b[0][4][0]
	b[7][4][0]

	// Queens
	b[0][3][0]
	b[7][3][0]

	// Rooks
	b[0][0][0]
	b[0][7][0]
	b[7][0][0]
	b[7][7][0]

    // Knights
	b[0][1][0]
	b[0][6][0]
	b[7][1][0]
	b[7][6][0]

    // Bishops
	b[0][2][0]
	b[0][5][0]
	b[7][2][0]
	b[7][5][0]

	// Empty
	for(int i=2; i<6; i++) {
		for(int j=0; j<8; j++) {
			b[i][j][0] = ' ';
		}
	}

*/

	
}


void print_board(Board b) {

	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			printf("%s  ", b[i][j]);
		}
	}

}
