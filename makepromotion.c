#include "checkers.h"

// Evaluates the board to make promotions
void makepromotion(int board[8][8]){
    for(int i = 0; i < 8; i++){
	if(board[0][i] == 2){
	    printf("Red piece at A%c promoted!\n", i+'1');
	    board[0][i] = 4;
	} else if (board[7][i] == 1){
	    printf("White piece at F%c promoted!\n", i+'1');
	    board[7][i] = 3;
	}
    }
}
