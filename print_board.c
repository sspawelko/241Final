// Sean Pawelko
//
// print_board.c
// Defines print_board();

#include "checkers.h"


void print_board() {
    extern int board[][];

    for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++) {
	    if (board[i][j] == 0) {
		printf("0 ");
	    }
	    if (board[i][j] == 1) {
		printf("r ");
	    }
	    if (board[i][j] == 2) {
		printf("R ");
	    }
	    if (board[i][j] == 3) {
		printf("b");
	    }
	    if (board[i][j] == 4) {
		printf("B");
	    }
	}
	printf("\n");
    }
}
