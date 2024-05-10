#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>

void display_loop(char board[8][8][2], WINDOW *win, char current_move[2]);
void draw_square(const int x, const int y, const int l, const int c, WINDOW *win);
void draw_board(WINDOW *win); 
void draw_pieces(char board[8][8][2], WINDOW *win);
void draw_current_move(char current_move[2], WINDOW *win);

#endif
