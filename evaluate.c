// Sean Pawelko
//
// evaluate.c
// Defines evaluate().

#include "checkers.h"


int evaluate(int player) {
    extern int board[][];
    
    int score = 0;
    // For the red player.
    if (player == 0) {
	for (int i = 0; i < 8; i++) {
	    for (int j = 0; j < 8; j++) {
		if (board[i][j] == 1) {
		    score = score + 3;
		}
		if (board[i][j] == 2) {
		    score = score + 5;
		}
		if (board[i][j] == 3) {
		    score = score - 3;
		}
		if (board[i][j] == 4) {
		    score = score - 5;
		}
	    }
	}

	return score;
    }

    if (player == 1) {
	for (int i = 0; i < 8; i++) {
	    for (int j = 0; j < 8; j++) {
		if (board[i][j] == 1) {
		    score = score - 3;
		}
		if (board[i][j] == 2) {
		    score = score - 5;
		}
		if (board[i][j] == 3) {
		    score = score + 3;
		}
		if (board[i][j] == 4) {
		    score = score + 5;
		}
	    }
	}

	return score;
    }

printf("Something went wrong!\n");
return -1;
}
