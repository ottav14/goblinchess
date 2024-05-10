#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>
#include "piece.h"

void display_loop(char board[8][8], WINDOW *win);
void draw_square(const int x, const int y, const int l, const int c, WINDOW *win);
void draw_board(WINDOW *win); 
void draw_pieces(char board[8][8], WINDOW *win);

#endif
