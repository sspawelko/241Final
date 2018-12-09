#include "checkers.h"




// Prints out all possible move locations
void printmovelist(int board[8][8], int row, int col, bool localturn){
    //extern int whiteturn;

    printf("Movelist for %c%c: ", row+'A', col+'0'+1);

    for(int i = -2; i < 3; i++){
	for (int j = -2; j < 3; j++){
	    if(!(i == 0 && j == 0)){
		
		if(checkmove(board, localturn, row, col, row + i, col + j) == 0){
		    printf("%c%c ", row + i + 'A', col + j + '0' + 1);
		}
	    }
	}
    }

    printf("\n");

}
