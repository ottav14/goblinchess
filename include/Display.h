#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>
#include "Board.h"

void display_loop(Board b, WINDOW *win, char current_move[2]);
void draw_square(const int x, const int y, const int l, const int c, WINDOW *win);
void draw_board(WINDOW *win); 
void draw_pieces(Board, WINDOW *win);
void draw_current_move(Move current_move, WINDOW *win);

#endif
