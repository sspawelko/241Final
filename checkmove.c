#include <stdio.h>

#include "checkers.h"

// Check validity of moves
int checkmove (int board[8][8], bool localturn, int irow, int icol, int frow, int fcol){

    // Check if values may go over the board
    if(irow < 0 || irow >= 8){
	//printf("Invalid values\n");
	return 1;
    } else if(icol < 0 || icol >= 8){
	//printf("Invalid values\n");
	return 1;
    } else if(frow < 0 || frow >= 8){
	//printf("Invalid values\n");
	return 1;
    } else if(fcol < 0 || fcol >= 8){
	//printf("Invalid values\n");
	return 1;
    }

    // Check if correct initial pieces were given based on the current turn
    if(localturn == true && board[irow][icol] != 1 && board[irow][icol] != 3){
	//printf("Invalid piece\n");
	return 1;
    } else if (localturn != true && board[irow][icol] != 2 && board[irow][icol] != 4){
	//printf("Invalid piece\n");
	return 1;
    }

    // Destination is not a empty space
    if(board[frow][fcol] != 0){
	//printf("Invalid destination\n");
	return 1;
    }
    
    // Check if normal pieces are moving in the correct y range
    if (board[irow][icol] == 1 || board[irow][icol] == 2){
	if (localturn == true && (frow <= irow || frow > irow + 2)){
	    //printf("Invalid whitepiece movement\n");
	    return 1;
	} else if (localturn != true && (frow >= irow|| frow < irow - 2)){
	    //printf("Invalid redpiece movement\n");
	    return 1;
	}
    // Check if promoted pieces are moving in the correct y range
    } else if (board[irow][icol] == 3 || board[irow][icol] == 4){
	if (frow < irow - 2 || frow > irow + 2 || frow == irow){
	    //printf("Invalid diagonal movement\n");
	    return 1;
	}
    }

    // Check if the pieces are moving in the correct x range
    if(fcol > icol + 2 || fcol < icol - 2 || fcol == icol){
	//printf("Invalid diagonal movement\n");
	return 1;
    }


    // Checking for single space movements
    if(frow == irow + 1 || frow == irow -1){
	if(! (fcol == icol + 1 || fcol == icol -1) ){
	    //printf("Invalid movement\n");
	    return 1;
	}
    }

    // Check if jumping is valid for normal pieces
    if (board[irow][icol] == 1 || board[irow][icol] == 2){
	if(localturn == true && frow == irow + 2){
	    if(fcol == icol + 2){
		if(board[irow+1][icol+1] != 2 && board[irow+1][icol+1] != 4){
		    //printf("Invalid jump\n");
		    return 1;
		}
	    } else if (fcol == icol - 2){
		if(board[irow+1][icol-1] != 2 && board[irow+1][icol-1] != 4){
		    //printf("Invalid jump\n");
		    return 1;
		}
	    } else {
		//printf("Invalid movement\n");
		return 1;
	    }
	} else if(localturn != true && frow == irow - 2){
	    if(fcol == icol + 2){
		if(board[irow-1][icol+1] != 1 && board[irow-1][icol+1] != 3){
		    //printf("Invalid jump\n");
		    return 1;
		}
	    } else if (fcol == icol - 2){
		if(board[irow-1][icol-1] != 1 && board[irow-1][icol-1] != 4){
		    //printf("Invalid jump\n");
		    return 1;
		}
	    } else {
		//printf("Invalid movement\n");
		return 1;
	    }
	}
    // Check if jumping is valid for promoted pieces
    } else if (board[irow][icol] == 3 || board[irow][icol] == 4){
	// Jumping downwards
	if(frow == irow + 2){	
	    // Jumping right
	    if(fcol == icol + 2){
		if(localturn == true){
		    if(board[irow+1][icol+1] != 2 && board[irow+1][icol+1] != 4){
			//printf("Invalid jump\n");
			return 1;	
		    }
		} else {
		    if(board[irow+1][icol+1] != 1 && board[irow+1][icol+1] != 3){
			//printf("Invalid jump\n");
			return 1;	
		    }
		}
	    // Jumping left
	    } else if (fcol == icol - 2){
		if(localturn == true){
		    if(board[irow+1][icol-1] != 2 && board[irow+1][icol-1] != 4){
			//printf("Invalid jump\n");
			return 1;	
		    }
		} else {
		    if(board[irow+1][icol-1] != 1 && board[irow+1][icol-1] != 3){
			//printf("Invalid jump\n");
			return 1;	
		    }
		}
	    } else {
		//printf("Invalid movement\n");
		return 1;
	    }	
    
	// Jumping upwards
	} else if (frow == irow - 2){
	    // Jumping right
	    if(fcol == icol + 2){
		if(localturn == true){
		    if(board[irow-1][icol+1] != 2 && board[irow-1][icol+1] != 4){
			//printf("Invalid jump\n");
			return 1;	
		    }
		} else {
		    if(board[irow-1][icol+1] != 1 && board[irow-1][icol+1] != 3){
			//printf("Invalid jump\n");
			return 1;	
		    }
		}
	    // Jumping left
	    } else if (fcol == icol - 2){
		if(localturn == true){
		    if(board[irow-1][icol-1] != 2 && board[irow-1][icol-1] != 4){
			//printf("Invalid jump\n");
			return 1;	
		    }
		} else {
		    if(board[irow-1][icol-1] != 1 && board[irow-1][icol-1] != 3){
			//printf("Invalid jump\n");
			return 1;	
		    }
		}
	    } else {
		//printf("Invalid movement\n");
		return 1;
	    }
	}
    }

    bool tocheck = false;
    for(int i = 0; i < 8; i++){
	for(int j = 0; j < 8; j++){
	    if(localturn && (board[i][j] == 1 || board[i][j] == 3)){
		if(checkjump(board, localturn, i, j, i, j) == 1){
		    //printf("\nJump available at: %c%c", i+'A', j+'0'+1);
		    tocheck = true;
		    break;
		}
	    } else if(!localturn && (board[i][j] == 2 || board[i][j] == 4)){
		if(checkjump(board, localturn, i, j, i, j) == 1){
		    //printf("\nJump available at: %c%c", i+'A', j+'0'+1);
		    tocheck = true;
		    break;
		}
	    }
	}
    }

    if(tocheck){
	if(checkjump(board, localturn, irow, icol, irow, icol) != 1){   
	    return 1;
	}
	if(!(frow == irow + 2 || frow == irow - 2)){
	    return 1;
	}
    }

    return 0;
}
