// Sean Pawelko
//
// check_win.c
// Defines check_win().

#include "checkers.h"


int check_win() {
    extern int board[][];
    
    int redcount = 0;
    int blackcount = 0;
    for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++) {
	    if (board[i][j] == 1 || board[i][j] == 2) {
		redcount++;
	    }
	    if (board[i][j] == 3 || board[i][j] == 4) {
		blackcount++;
	    }
	}
    }
    
    if (blackcount == 0) {
	return 1;
    }


    if (redcount == 0) {
	return 2;
    }
    

    //What if a player has no moves left? Then they lose. Of if both players have no moves left, they draw.

    return 0;

