#include "checkers.h"

// Check for win conditions
int checkwin(int board[8][8]) {
    int white = 0;
    int red = 0;
    
    for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++){
	    if (board[i][j] == 1||board[i][j] == 3) {
		white++;
	    } else if (board[i][j] == 2||board[i][j] == 4) {
		red++;
	    }
	}
    }

    if (white == 0){
	return 2;
    } else if (red == 0){
	return 1;
    } else {
	return 0;
    }
}
