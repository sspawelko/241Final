#include "checkers.h"

// Checks if more jumps are necessary
int checkjump (int board[8][8], bool localturn, int row, int col, int irow, int icol){
   
    // Normal pieces
    if(board[row][col] == 1 || board[row][col] == 2){ 

	if(localturn == true){
	    if((row + 1) < 7 && (col + 1) < 7){
		if(board[row+1][col+1] != 0){
		    if(board[row+2][col+2] == 0){
			return 1;
		    }
		}
	    } 
	    
	    if ((row + 1) < 7 && (col - 1) > 0){
		if(board[row+1][col-1] != 0){
		    if(board[row+2][col-2] == 0){
			return 1;
		    }
		}
	    }
	}  else if (localturn != true){
	    if((row-1) > 0 && (col + 1) < 7){
		if(board[row-1][col+1] != 0){
		    if(board[row-2][col+2] == 0){
			return 1;
		    }
		}
	    } 
	    
	    if ((row-1) > 0 && (col - 1) > 0){
		if(board[row-1][col-1] != 0){
		    if(board[row-2][col-2] == 0){
			return 1;
		    }
		}
	    }
	}

    // Promoted pieces
    } else if (board[row][col] == 3 || board[row][col] == 4){ 
	
	if((row + 1) < 7 && (col + 1) < 7){

	    if(board[row+1][col+1] != 0){
		if(board[row+2][col+2] == 0 && !(row+2 == irow && col+2 == icol)){
		    return 1;
		}
	    }

	} 
	
	if ((row + 1) < 7 && (col - 1) > 0){

	    if(board[row+1][col-1] != 0){
		if(board[row+2][col-2] == 0 && !(row+2 == irow && col-2 == icol)){
		    return 1;
		}
	    }

	} 
	
	if((row-1) > 0 && (col + 1) < 7){

	    if(board[row-1][col+1] != 0){
		if(board[row-2][col+2] == 0 && !(row-2 == irow && col+2 == icol)){
		    return 1;
		}
	    }

	} 
	
	if ((row - 1) > 0 && (col - 1) > 0){

	    if(board[row-1][col-1] != 0){
		if(board[row-2][col-2] == 0 && !(row-2 == irow && col-2 == icol)){
		    return 1;
		}
	    }

	}
    
    }

    return 0;
}



//OLD CODE


/*
int checkjump (int board[8][8], int row, int col){
   
    if(board[row][col] == 1 || board[row][col] == 2){ 

	if(whiteturn == true){
	    if((row + 1) < 7 && (col + 1) < 7){
		if(board[row+1][col+1] == 2){
		    if(board[row+2][col+2] == 0){
			return 1;
		    }
		}
	    } 
	    
	    if ((row + 1) < 7 && (col - 1) > 0){
		if(board[row+1][col-1] == 2){
		    if(board[row+2][col-2] == 0){
			return 1;
		    }
		}
	    }
	}  else if (whiteturn != true){
	    if((row-1) > 0 && (col + 1) < 7){
		if(board[row-1][col+1] == 1){
		    if(board[row-2][col+2] == 0){
			return 1;
		    }
		}
	    } 
	    
	    if ((row-1) > 0 && (col - 1) > 0){
		if(board[row-1][col-1] == 1){
		    if(board[row-2][col-2] == 0){
			return 1;
		    }
		}
	    }
	}

    } else if (board[row][col] == 3 || board[row][col] == 4){ 
	
	if((row + 1) < 7 && (col + 1) < 7){

	    if(whiteturn == true && (board[row+1][col+1] == 2 || board[row+1][col+1] == 4)){
		if(board[row+2][col+2] == 0){
		    return 1;
		}
	    } else if(whiteturn != true && (board[row+1][col+1] == 1 || board[row+1][col+1] == 3)){
		if(board[row+2][col+2] == 0){
		    return 1;
		}
	    }

	} 
	
	if ((row + 1) < 7 && (col - 1) > 0){

	    if(whiteturn == true && (board[row+1][col-1] == 2 || board[row+1][col-1] == 4)){
		if(board[row+2][col-2] == 0){
		    return 1;
		}
	    } else if(whiteturn != true && (board[row+1][col-1] == 1 || board[row+1][col-1] == 3)){
		if(board[row+2][col-2] == 0){
		    return 1;
		}
	    }

	} 
	
	if((row-1) > 0 && (col + 1) < 7){

	    if(whiteturn == true && (board[row-1][col+1] == 2 || board[row-1][col+1] == 4)){
		if(board[row-2][col+2] == 0){
		    return 1;
		}
	    } else if(whiteturn != true && (board[row-1][col+1] == 1 || board[row-1][col+1] == 3)){
		if(board[row-2][col+2] == 0){
		    return 1;
		}
	    }

	} 
	
	if ((row - 1) > 0 && (col - 1) > 0){

	    if(whiteturn == true && (board[row-1][col-1] == 2 || board[row-1][col-1] == 4)){
		if(board[row-2][col-2] == 0){
		    return 1;
		}
	    } else if(whiteturn != true && (board[row-1][col-1] == 1 || board[row-1][col-1] == 3)){
		if(board[row-2][col-2] == 0){
		    return 1;
		}
	    }

	}
    
    }

    return 0;
}*/

