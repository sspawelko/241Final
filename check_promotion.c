// Sean Pawelko
//
// check_promotion.c
// Defines check_promotion().

#include "checkers.h"


void check_promotion(int board[][]) {
    // If red pieces are in the row y = 0, they must be promoted.
    for (int i = 0; i < 8; i++) {
	if (board[i][0] == 1) {
	    board[i][0] = 2;
	}
    }

    // If black pieces are in the row y = 7, they must be promoted.
    for (int i = 0; i < 8; i++) {
	if (board[i][7] == 3) {
	    board[i][7] = 4;
	}
    }
}
