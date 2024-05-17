#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>

typedef char Piece[2];
typedef char Move[3];
typedef char Square[2];

typedef Piece Board[8][8];

void resetBoard(Board b);
void printBoard(Board b);
void coordToSquare(int x, int y, Square* s);
void setPiece(Board b, int x, int y, char p, char q);
Piece* getPiece(Board b, int x, int y);
Move* getMoves(Board b, int x, int y);

#endif
