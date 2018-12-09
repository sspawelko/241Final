#include "checkers.h"

// Initialize checker board
void initboard(int board[8][8]) {
    for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 4; j++) {
	    if (i%2 == 0){
		board[i][2*j+1] = 1;
	    } else {
		board[i][2*j] = 1;
	    }
	}	    
    }

    for (int i = 5; i < 8; i++) {
	for (int j = 0; j < 4; j++) {
	    if (i%2 == 0){
		board[i][2*j+1] = 2;
	    } else {
		board[i][2*j] = 2;
	    }
	}	    
    }
}
