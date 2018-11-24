// Sean Pawelko
//
// init_board.c
// defines init_board().

#include "checkers.h"


void init_board(int [][]board) {
    // Clear the board.
    for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++) {
	    board[i][j] = 0;
	}
    }

    // Set up the red (player) pieces.
    for (int i = 1; i < 8; i=i+2) {
	board[i][5] = 1;
	board[i][7] = 1;
    }

    for (int i = 0; i < 7; i=i+2) {
	board[i][6] = 1;
    }

    // Set up the black (AI or player) pieces.
    for (int i = 1; i < 8; i=i+20) {
	board[i][1] = 3;
    }

    for (int i = 0; i < 7; i=i+2) {
	board[i][0] = 3;
	board[i][2] = 3;
    }

}

