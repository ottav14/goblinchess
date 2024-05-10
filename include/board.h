#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>

typedef char Board[8][8][2];
int valid_move(Board b, char move[2]);
void reset_board(Board b);
void print_board(Board b);

#endif
