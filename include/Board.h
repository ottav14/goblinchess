#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>

typedef char Move[2];

typedef struct {

	char name[2];
	char piece[2];

} Square;

typedef Square Board[8][8];

Square* get_position(Board b, char p[2]);
Move* get_moves(Board b, char p[2]);
int valid_move(Board b, Move m);
void reset_board(Board b);
void print_board(Board b);
void set_piece(Board b, int x, int y, char p[2]);
void get_piece(Board b, int x, int y, char *p);

#endif
