#include "display.h"
#include "board.h"

#define squareLength 2

char board[8][8];


int main() {

	reset_board(board);

	init_ncurses();


    return 0;
}

