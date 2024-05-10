#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>

void display_loop(char board[8][8], WINDOW *win);
void draw_square(const int x, const int y, const int w, const int h, const int c, WINDOW *win);
void draw_board(WINDOW *win); 
void draw_pieces(char board[8][8], WINDOW *win);

#endif
