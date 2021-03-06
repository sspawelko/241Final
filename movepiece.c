#include <stdio.h>

#include "checkers.h"

// Moves the pieces accordingly
int movepiece (int board[8][8], bool localturn, int irow, int icol, int frow, int fcol){

    int jumped = 0;

    // No jumping (normal + promoted)
    if(frow == irow + 1||frow == irow - 1){
	board[frow][fcol] = board[irow][icol];
	board[irow][icol] = 0;

    // Jumping
    } else if (frow == irow  + 2 || frow == irow - 2){

	jumped = 1;
	//jumped = true;

	board[frow][fcol] = board[irow][icol];
	board[irow][icol] = 0;

	// Jumping downwards
	if(frow == irow + 2){	
	    // Jumping right
	    if(fcol == icol + 2){

		if(localturn == true && (board[irow+1][icol+1] == 2 || board[irow+1][icol+1] == 4)){
		    if(user == true){
			printf("Red piece at %c%c taken!\n", irow+'A'+1, icol+'0'+2);
		    }
		    board[irow+1][icol+1] = 0;
		} else if (localturn != true && (board[irow+1][icol+1] == 1 || board[irow+1][icol+1] == 3)){
		    if(user == true){
			printf("Black piece at %c%c taken!\n", irow+'A'+1, icol+'0'+2);
		    }
		    board[irow+1][icol+1] = 0;
		}

	    // Jumping left
	    } else if (fcol == icol - 2){
		
		if(localturn == true && (board[irow+1][icol-1] == 2 || board[irow+1][icol-1] == 4)){
		    if(user == true){
			printf("Red piece at %c%c taken!\n", irow+'A'+1, icol+'0');
		    }
		    board[irow+1][icol-1] = 0;
		} else if (localturn != true && (board[irow+1][icol-1] == 1 || board[irow+1][icol-1] == 3)){
		    if(user == true){
			printf("Black piece at %c%c taken!\n", irow+'A'+1, icol+'0');
		    }
		    board[irow+1][icol-1] = 0;
		}

	    }
    
	// Jumping upwards
	} else if (frow == irow - 2){
	    // Jumping right
	    if(fcol == icol + 2){
		
		if(localturn == true && (board[irow-1][icol+1] == 2 || board[irow-1][icol+1] == 4)){
		    if(user == true){
			printf("Red piece at %c%c taken!\n", irow+'A'-1, icol+'0'+2);
		    }
		    board[irow-1][icol+1] = 0;
		} else if (localturn != true && (board[irow-1][icol+1] == 1 || board[irow-1][icol+1] == 3)){
		    if(user == true){
			printf("Black piece at %c%c taken!\n", irow+'A'-1, icol+'0'+2);
		    }
		    board[irow-1][icol+1] = 0;
		}

	    // Jumping left
	    } else if (fcol == icol - 2){
		
		if(localturn == true && (board[irow-1][icol-1] == 2 || board[irow-1][icol-1] == 4)){
		    if(user == true){
			printf("Red piece at %c%c taken!\n", irow+'A'-1, icol+'0');
		    }
		    board[irow-1][icol-1] = 0;
		} else if (localturn != true && (board[irow-1][icol-1] == 1 || board[irow-1][icol-1] == 3)){
		    if(user == true){
			printf("Black piece at %c%c taken!\n", irow+'A'-1, icol+'0');
		    }
		    board[irow-1][icol-1] = 0;
		}

	    }
	}

    }

    //makepromotion(board);

    return jumped;
}
