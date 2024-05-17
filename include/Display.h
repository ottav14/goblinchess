#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>
#include "Board.h"

void displayLoop(Board b, WINDOW *win, char current_move[2]);
void drawSquare(const int x, const int y, const int l, const int c, WINDOW *win);
void drawBoard(WINDOW *win); 
void drawPieces(Board, WINDOW *win);
void drawCurrentMove(char current_move[2], WINDOW *win);

#endif
