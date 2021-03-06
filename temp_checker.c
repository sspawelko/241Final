#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

int global_board[8][8] = {{0}};
bool whiteturn = true;
int DIFF = 1;

bool user = false;
bool ai_shift = true;

void printlist (int movelist[48][5]);
int checkjump (int board[8][8], bool localturn, int row, int col, int irow, int icol);


// Initialize checker board
void initboard(int board[8][8]){
    for (int i = 0; i < 3; i++){
	for (int j = 0; j < 4; j++){
	    if(i%2 == 0){
		board[i][2*j+1] = 1;
	    } else {
		board[i][2*j] = 1;
	    }

	}	    
    }

    for (int i = 5; i < 8; i++){
	for (int j = 0; j < 4; j++){
	    if(i%2 == 0){
		board[i][2*j+1] = 2;
	    } else {
		board[i][2*j] = 2;
	    }

	}	    
    }

}

// Print current board
void printboard(int board[8][8]){
    printf("   1 2 3 4 5 6 7 8\n");
    for(int i = 0; i < 8; i++){
	putchar('A'+i);
	printf("| ");
	for(int j = 0; j < 8; j++){
	  if (board[i][j] == 1) {
	    printf("b ");
	  } else if (board[i][j] == 3) {
	    printf("B ");
	  } else if (board[i][j] == 2) {
	    printf("r ");
	  } else if (board[i][j] == 4) {
	    printf("R ");
	  } else if (board[i][j] == 0) {
	    printf("- ");
	  } else {
	    printf("%d ", board[i][j]);
	  }
	}
	printf("\n");
    }
}

// Check for win conditions
int checkwin(int board[8][8]){
    int white = 0;
    int red = 0;
    
    for(int i = 0; i < 8; i++){

	for(int j = 0; j < 8; j++){
	    if(board[i][j] == 1||board[i][j] == 3){
		red++;
	    } else if (board[i][j] == 2||board[i][j] == 4){
		white++;
	    }
	}
    }

    if(white == 0){
	return 2;
    } else if (red == 0){
	return 1;
    } else {
	return 0;
    }
}

// Check validity of moves
int checkmove (int board[8][8], bool localturn, int irow, int icol, int frow, int fcol){

    // Check if values may go over the board
    if(irow < 0 || irow >= 8){
	return 1;
    } else if(icol < 0 || icol >= 8){
	return 1;
    } else if(frow < 0 || frow >= 8){
	return 1;
    } else if(fcol < 0 || fcol >= 8){
	return 1;
    }

    // Check if correct initial pieces were given based on the current turn
    if(localturn == true && board[irow][icol] != 1 && board[irow][icol] != 3){
	return 1;
    } else if (localturn != true && board[irow][icol] != 2 && board[irow][icol] != 4){
	return 1;
    }

    // Destination is not a empty space
    if(board[frow][fcol] != 0){
	return 1;
    }
    
    // Check if normal pieces are moving in the correct y range
    if (board[irow][icol] == 1 || board[irow][icol] == 2){
	if (localturn == true && (frow <= irow || frow > irow + 2)){
	    return 1;
	} else if (localturn != true && (frow >= irow|| frow < irow - 2)){
	    return 1;
	}
    // Check if promoted pieces are moving in the correct y range
    } else if (board[irow][icol] == 3 || board[irow][icol] == 4){
	if (frow < irow - 2 || frow > irow + 2 || frow == irow){
	    return 1;
	}
    }

    // Check if the pieces are moving in the correct x range
    if(fcol > icol + 2 || fcol < icol - 2 || fcol == icol){
	return 1;
    }


    // Checking for single space movements
    if(frow == irow + 1 || frow == irow -1){
	if(! (fcol == icol + 1 || fcol == icol -1) ){
	    return 1;
	}
    }
    
    //HERE
    // Check if jumping is valid for normal pieces
    if (board[irow][icol] == 1 || board[irow][icol] == 2){
	if(localturn == true && frow == irow + 2){
	    if(fcol == icol + 2){
<<<<<<< HEAD
		if(board[irow+1][icol+1] != 2 && board[irow+1][icol+1] != 4){
		    //printf("Invalid jump\n");
		    return 1;
		}
	    } else if (fcol == icol - 2){
		if(board[irow+1][icol-1] != 2 && board[irow+1][icol-1] != 4){
		    //printf("Invalid jump\n");
=======
		if(board[irow+1][icol+1] == 0 || board[irow+1][icol+1] == board[irow][icol] || board[irow+1][icol+1] == board[irow][icol]+2){
		    return 1;
		}
	    } else if (fcol == icol - 2){
		if(board[irow+1][icol-1] == 0 || board[irow+1][icol-1] == board[irow][icol] || board[irow+1][icol-1] == board[irow][icol]+2){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		    return 1;
		}
	    } else {
		return 1;
	    }
	} else if(localturn != true && frow == irow - 2){
	    if(fcol == icol + 2){
<<<<<<< HEAD
		if(board[irow-1][icol+1] != 1 && board[irow-1][icol+1] != 3){
		    //printf("Invalid jump\n");
		    return 1;
		}
	    } else if (fcol == icol - 2){
		if(board[irow-1][icol-1] != 1 && board[irow-1][icol-1] != 4){
		    //printf("Invalid jump\n");
=======
		if(board[irow-1][icol+1] == 0 || board[irow-1][icol+1] == board[irow][icol] || board[irow-1][icol+1] == board[irow][icol]+2){
		    return 1;
		}
	    } else if (fcol == icol - 2){
		if(board[irow-1][icol-1] == 0 || board[irow-1][icol-1] == board[irow][icol] || board[irow-1][icol-1] == board[irow][icol]+2){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		    return 1;
		}
	    } else {
		return 1;
	    }
	}
    // Check if jumping is valid for promoted pieces
    } else if (board[irow][icol] == 3 || board[irow][icol] == 4){
	// Jumping downwards
	if(frow == irow + 2){	
	    // Jumping right
	    if(fcol == icol + 2){
<<<<<<< HEAD
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
=======
		if(board[irow+1][icol+1] == 0 || board[irow+1][icol+1] == board[irow][icol] || board[irow+1][icol+1] == board[irow][icol]-2){
		    return 1;	
		}
	    // Jumping left
	    } else if (fcol == icol - 2){
		if(board[irow+1][icol-1] == 0 || board[irow+1][icol-1] == board[irow][icol] || board[irow+1][icol-1] == board[irow][icol]-2){
		    return 1;	
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		}
	    } else {
		return 1;
	    }	
    
	// Jumping upwards
	} else if (frow == irow - 2){
	    // Jumping right
	    if(fcol == icol + 2){
<<<<<<< HEAD
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
=======
		if(board[irow-1][icol+1] == 0 || board[irow-1][icol+1] == board[irow][icol] || board[irow-1][icol+1] == board[irow][icol]-2){
		    return 1;	
		}
	    // Jumping left
	    } else if (fcol == icol - 2){
		if(board[irow-1][icol-1] == 0 || board[irow-1][icol-1] == board[irow][icol] || board[irow-1][icol-1] == board[irow][icol]-2){
		    return 1;	
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		}
	    } else {
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

// Evaluates the board to make promotions
void makepromotion(int board[8][8]){
    for(int i = 0; i < 8; i++){
	if(board[0][i] == 2){
<<<<<<< HEAD
	    if(user == true){
		printf("Red piece at A%c promoted!\n", i+'1');
	    }
	    board[0][i] = 4;
	} else if (board[7][i] == 1){
	    if(user == true){
		printf("Black piece at F%c promoted!\n", i+'1');
	    }
=======
	    board[0][i] = 4;
	} else if (board[7][i] == 1){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
	    board[7][i] = 3;
	}
    }
}

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

	board[frow][fcol] = board[irow][icol];
	board[irow][icol] = 0;

	// Jumping downwards
	if(frow == irow + 2){	
	    // Jumping right
	    if(fcol == icol + 2){

		if(localturn == true && (board[irow+1][icol+1] == 2 || board[irow+1][icol+1] == 4)){
<<<<<<< HEAD
		    if(user == true){
			printf("Red piece at %c%c taken!\n", irow+'A'+1, icol+'0'+2);
		    }
		    board[irow+1][icol+1] = 0;
		} else if (localturn != true && (board[irow+1][icol+1] == 1 || board[irow+1][icol+1] == 3)){
		    if(user == true){
			printf("Black piece at %c%c taken!\n", irow+'A'+1, icol+'0'+2);
		    }
=======
		    board[irow+1][icol+1] = 0;
		} else if (localturn != true && (board[irow+1][icol+1] == 1 || board[irow+1][icol+1] == 3)){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		    board[irow+1][icol+1] = 0;
		}

	    // Jumping left
	    } else if (fcol == icol - 2){
		
		if(localturn == true && (board[irow+1][icol-1] == 2 || board[irow+1][icol-1] == 4)){
<<<<<<< HEAD
		    if(user == true){
			printf("Red piece at %c%c taken!\n", irow+'A'+1, icol+'0');
		    }
		    board[irow+1][icol-1] = 0;
		} else if (localturn != true && (board[irow+1][icol-1] == 1 || board[irow+1][icol-1] == 3)){
		    if(user == true){
			printf("Black piece at %c%c taken!\n", irow+'A'+1, icol+'0');
		    }
=======
		    board[irow+1][icol-1] = 0;
		} else if (localturn != true && (board[irow+1][icol-1] == 1 || board[irow+1][icol-1] == 3)){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		    board[irow+1][icol-1] = 0;
		}

	    }
    
	// Jumping upwards
	} else if (frow == irow - 2){
	    // Jumping right
	    if(fcol == icol + 2){
		
		if(localturn == true && (board[irow-1][icol+1] == 2 || board[irow-1][icol+1] == 4)){
<<<<<<< HEAD
		    if(user == true){
			printf("Red piece at %c%c taken!\n", irow+'A'-1, icol+'0'+2);
		    }
		    board[irow-1][icol+1] = 0;
		} else if (localturn != true && (board[irow-1][icol+1] == 1 || board[irow-1][icol+1] == 3)){
		    if(user == true){
			printf("Black piece at %c%c taken!\n", irow+'A'-1, icol+'0'+2);
		    }
=======
		    board[irow-1][icol+1] = 0;
		} else if (localturn != true && (board[irow-1][icol+1] == 1 || board[irow-1][icol+1] == 3)){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		    board[irow-1][icol+1] = 0;
		}

	    // Jumping left
	    } else if (fcol == icol - 2){
		
		if(localturn == true && (board[irow-1][icol-1] == 2 || board[irow-1][icol-1] == 4)){
<<<<<<< HEAD
		    if(user == true){
			printf("Red piece at %c%c taken!\n", irow+'A'-1, icol+'0');
		    }
		    board[irow-1][icol-1] = 0;
		} else if (localturn != true && (board[irow-1][icol-1] == 1 || board[irow-1][icol-1] == 3)){
		    if(user == true){
			printf("Black piece at %c%c taken!\n", irow+'A'-1, icol+'0');
		    }
=======
		    board[irow-1][icol-1] = 0;
		} else if (localturn != true && (board[irow-1][icol-1] == 1 || board[irow-1][icol-1] == 3)){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		    board[irow-1][icol-1] = 0;
		}

	    }
	}

    }

    //makepromotion(board);

    return jumped;
}

// HERE
// Checks if more jumps are necessary
int checkjump (int board[8][8], bool localturn, int row, int col, int irow, int icol){
   
    // Normal pieces
    if(board[row][col] == 1 || board[row][col] == 2){ 

	if(localturn == true){
	    if((row + 1) < 7 && (col + 1) < 7){
<<<<<<< HEAD
		if(board[row+1][col+1] == 2 || board[row+1][col+1] == 4){
=======
		if(board[row+1][col+1] != 0 && board[row+1][col+1] != board[row][col] && board[row+1][col+1] != board[row][col] +2){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		    if(board[row+2][col+2] == 0){
			return 1;
		    }
		}
	    } 
	    
	    if ((row + 1) < 7 && (col - 1) > 0){
<<<<<<< HEAD
		if(board[row+1][col-1] == 2 || board[row+1][col-1] == 4){
=======
		if(board[row+1][col-1] != 0 && board[row+1][col-1] != board[row][col] && board[row+1][col-1] != board[row][col] +2){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		    if(board[row+2][col-2] == 0){
			return 1;
		    }
		}
	    }
	}  else if (localturn != true){
	    if((row-1) > 0 && (col + 1) < 7){
<<<<<<< HEAD
		if(board[row-1][col+1] == 1 || board[row-1][col+1] == 3){
=======
		if(board[row-1][col+1] != 0 && board[row-1][col+1] != board[row][col] && board[row-1][col+1] != board[row][col] +2){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		    if(board[row-2][col+2] == 0){
			return 1;
		    }
		}
	    } 
	    
	    if ((row-1) > 0 && (col - 1) > 0){
<<<<<<< HEAD
		if(board[row-1][col-1] == 1 || board[row-1][col-1] == 3){
=======
		if(board[row-1][col-1] != 0 && board[row-1][col-1] != board[row][col] && board[row-1][col-1] != board[row][col] +2){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		    if(board[row-2][col-2] == 0){
			return 1;
		    }
		}
	    }
	}

    //	Promoted pieces
    } else if (board[row][col] == 3){ 
	
	if((row + 1) < 7 && (col + 1) < 7){
	    if(board[row+1][col+1] == 2 || board[row+1][col+1] == 4){
		if(board[row+2][col+2] == 0 && !(row+2 == irow && col+2 == icol)){
		    return 1;
		}
	    }

	} 
	
	if ((row + 1) < 7 && (col - 1) > 0){

	    if(board[row+1][col-1] == 2 || board[row+1][col-1] == 4){
		if(board[row+2][col-2] == 0 && !(row+2 == irow && col-2 == icol)){
		    return 1;
		}
	    }

<<<<<<< HEAD
	} 
	
	if((row-1) > 0 && (col + 1) < 7){

	    if(board[row-1][col+1] == 2 || board[row-1][col+1] == 4){
		if(board[row-2][col+2] == 0 && !(row-2 == irow && col+2 == icol)){
		    return 1;
		}
	    }
	} 
	
	if ((row - 1) > 0 && (col - 1) > 0){

	    if(board[row-1][col-1] == 2 || board[row-1][col-1] == 4){
		if(board[row-2][col-2] == 0 && !(row-2 == irow && col-2 == icol)){
		    return 1;
		}
	    }

	}
    
    } else if (board[row][col] == 4){ 
	
	if((row + 1) < 7 && (col + 1) < 7){
	    if(board[row+1][col+1] == 1 || board[row+1][col+1] == 3){
=======
	    if(board[row+1][col+1] != 0 && board[row+1][col+1] != board[row][col] && board[row+1][col+1] != board[row][col] -2) {
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		if(board[row+2][col+2] == 0 && !(row+2 == irow && col+2 == icol)){
		    return 1;
		}
	    }

	} 
	
	if ((row + 1) < 7 && (col - 1) > 0){

<<<<<<< HEAD
	    if(board[row+1][col-1] == 1 || board[row+1][col-1] == 3){
=======
	    if(board[row+1][col-1] != 0 && board[row+1][col-1] != board[row][col] && board[row+1][col-1] != board[row][col] -2){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		if(board[row+2][col-2] == 0 && !(row+2 == irow && col-2 == icol)){
		    return 1;
		}
	    }

	} 
	
	if((row-1) > 0 && (col + 1) < 7){

<<<<<<< HEAD
	    if(board[row-1][col+1] == 1 || board[row-1][col+1] == 3){
=======
	    if(board[row-1][col+1] != 0 && board[row-1][col+1] != board[row][col] && board[row-1][col+1] != board[row][col] -2){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		if(board[row-2][col+2] == 0 && !(row-2 == irow && col+2 == icol)){
		    return 1;
		}
	    }
	} 
	
	if ((row - 1) > 0 && (col - 1) > 0){

<<<<<<< HEAD
	    if(board[row-1][col-1] == 1 || board[row-1][col-1] == 3){
=======
	    if(board[row-1][col-1] != 0 && board[row-1][col-1] != board[row][col] && board[row-1][col-1] != board[row][col] -2){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
		if(board[row-2][col-2] == 0 && !(row-2 == irow && col-2 == icol)){
		    return 1;
		}
	    }

	}
    
    }

    return 0;
}

// Prints out all possible move locations
void printmovelist(int board[8][8], int row, int col){

    int counter = 0;

    for(int i = -2; i < 3; i++){
	for (int j = -2; j < 3; j++){
	    if(!(i == 0 && j == 0)){

		if(checkmove(board, whiteturn, row, col, row + i, col + j) == 0){
		    
		    if(counter == 0){
			printf("Moves for %c%c: ", row+'A', col+'0'+1);
		    }
		    counter++;

		    printf("%c%c ", row + i + 'A', col + j + '0' + 1);
		}
	    }
	}
    }

    if(counter != 0){
	printf("\n");
    }
}


// Print the list of jumps
void printjumplist(int board[8][8], int row, int col, int irow, int icol){

    printf("Moves for %c%c: ", row+'A', col+'0'+1);

    for(int i = -2; i < 3; i += 4){
	for (int j = -2; j < 3; j += 4){
	
		if(!((row + i) == irow && (col + j) == icol)){
		    if(checkmove(board, whiteturn, row, col, row + i, col + j) == 0){
			printf("%c%c ", row + i + 'A', col + j + '0' + 1);
		    }
		}

	}
    }

    printf("\n");

}

typedef struct checkernode {

    int localboard[8][8];
    bool localturn;

    bool mustjump;

    bool gameover;

    int boardvalue;

    int depth;

    int movemade[5];

    int childcount;
    
    struct checkernode ** childlist;
    struct checkernode * parent;

} node;

// must jump support
int ** movelist(node * n){

    int counter = 1;
    int ** list;

    if(n->mustjump == false){
    
	list = malloc(sizeof(int*) * 49);

	for (int i = 0; i < 49; i++){
	    list[i] = malloc(49 * 5 * sizeof(int));
	}

	for(int i = 0; i < 8; i++){
	    for(int j = 0; j < 8; j++){

		if(n->localturn && (n->localboard[i][j] == 1 || n->localboard[i][j] == 3)){

		    for(int k = -2; k < 3; k++){
			for (int l = -2; l < 3; l++){
			
			    if(checkmove(n->localboard, n->localturn, i, j, i + k, j + l) == 0){

				list[counter][0] = i;
				list[counter][1] = j;
				list[counter][3] = i + k;
				list[counter][4] = j + l;

				counter++;
			    }

			}
		    }

		} else if (!n->localturn && (n->localboard[i][j] == 2 || n->localboard[i][j] == 4)){
		
		    for(int k = -2; k < 3; k++){

			for (int l = -2; l < 3; l++){
			
			    if(checkmove(n->localboard, n->localturn, i, j, i + k, j + l) == 0){
			    
				list[counter][0] = i;
				list[counter][1] = j;
				list[counter][3] = i + k;
				list[counter][4] = j + l;

				counter++;
			    }

			}
		    }	 

		}
	    }
	}

    } else {
	
	list = malloc(sizeof(int*) * 49);

	for (int i = 0; i < 49; i++){
	    list[i] = malloc(49 * 5 * sizeof(int));
	}
	
	int row = n->movemade[3];
	int col = n->movemade[4];
	int irow = n->movemade[0];
	int icol = n->movemade[1];

	for(int k = -2; k < 3; k += 4){	    
	    for(int l = -2; l < 3; l += 4){

		    if(!((row + k) == irow && (col + l) == icol)){

			if(checkmove(n->localboard, n->localturn, row, col, row + k, col + l) == 0){

			    list[counter][0] = row;
			    list[counter][1] = col;
			    list[counter][3] = row + k;
			    list[counter][4] = col + l;

			    counter++;
			} 

		    }
	    }
	}

    }

    list[0][0] = counter;
    return list;
}

// Create a node.
node * makenode(int current_board[8][8], bool current_turn, int newmove[5]){

    int value = 0;

    node * temp = malloc(sizeof(node));

    for(int i = 0; i < 8; i++){
	for(int j = 0; j < 8; j++){
	    temp->localboard[i][j] = current_board[i][j];
	    
	    if(current_board[i][j] == 2 || current_board[i][j] == 4){
		if(ai_shift == true){
		    value--;

		    if(current_board[i][j] == 4){
			value -= 10;
		    }

		} else {
		    value++;

		    if(current_board[i][j] == 4){
			value += 10;
		    }
		}
	    } if(current_board[i][j] == 1 || current_board[i][j] == 3){
		if(ai_shift == true){
		    value++;

		    if(current_board[i][j] == 3){
			value += 10;
		    }
		} else {
		    value--;

		    if(current_board[i][j] == 3){
			value -= 10;
		    }
		}
	    }

	}
    }

    int justjumped = movepiece(temp->localboard, current_turn, newmove[0], newmove[1], newmove[3], newmove[4]);

    if(justjumped == 1 && checkjump(temp->localboard, current_turn,newmove[3],newmove[4],newmove[0],newmove[1]) == 1)	{
	temp->mustjump = true;
	temp->localturn = current_turn;
    } else {
	temp->mustjump = false;
	temp->localturn = !current_turn;
    }

    for (int i = 0; i < 5; i++){
	temp->movemade[i] = newmove[i];
    }

    if(checkwin(temp->localboard) == 2){
	if(ai_shift == true){
	    value -= 10000;
	} else {
	    value += 10000;
	}
	temp->gameover = true;
    } else if(checkwin(temp->localboard) == 1){
	if(ai_shift == true){
	    value += 10000;
	} else {
	    value -= 10000;
	}
	temp->gameover = true;
    } else {
	temp->gameover = false;
    }

    temp->boardvalue = value;

    return temp;
}

void printnode(node * temp){
    
    printf("\n------------------------------------\nNode\n");
    printboard(temp->localboard);
    printf("Must jump: %s\n", temp->mustjump ? "true" : "false");
    printf("Localturn: %s\n", temp->localturn ? "true" : "false");
    printf("Gameover: %s\n", temp->gameover ? "true" : "false");
    printf("Boardvalue: %d\n", temp->boardvalue);
    printf("Depth: %d\n", temp->depth);
    printf("Childcount %d\n", temp->childcount);
    printf("Move: %c%c -> %c%c\n", temp->movemade[0] + 'A', temp->movemade[1] + '1', temp->movemade[3]  + 'A', temp->movemade[4] + '1');
    printf("------------------------------------\n");

}

node * initroot(int current_board[8][8], bool current_turn, bool current_mustjump, int irow, int icol, int frow, int fcol){

    int value = 0;

    node * temp = malloc(sizeof(node));

    for(int i = 0; i < 8; i++){
	for(int j = 0; j < 8; j++){
	    temp->localboard[i][j] = current_board[i][j];
	    
	    if(current_board[i][j] == 2 || current_board[i][j] == 4){
		if(ai_shift == true){
		    value--;

		    if(current_board[i][j] == 4){
			value -= 10;
		    }

		} else {
		    value++;

		    if(current_board[i][j] == 4){
			value += 10;
		    }
		}
	    } if(current_board[i][j] == 1 || current_board[i][j] == 3){
		if(ai_shift == true){
		    value++;

		    if(current_board[i][j] == 3){
			value += 10;
		    }
		} else {
		    value--;

		    if(current_board[i][j] == 3){
			value -= 10;
		    }
		}
	    }

	}
    }

    temp->movemade[0] = irow;
    temp->movemade[1] = icol;
    temp->movemade[3] = frow;
    temp->movemade[4] = fcol;

    temp->mustjump = current_mustjump;
    temp->localturn = current_turn;
    temp->depth = 0;

    if(checkwin(current_board) == 2){
	if(ai_shift == true){
	    value -= 10000;
	} else {
	    value += 10000;
	}
	temp->gameover = true;
    } else if(checkwin(current_board) == 1){
	if(ai_shift == true){
	    value += 10000;
	} else {
	    value -= 10000;
	}
	temp->gameover = true;
    } else {
	temp->gameover = false;
    }

    temp->boardvalue = value;

    return temp;
}

void setchild (node * parentnode){

    int ** templist = movelist(parentnode);
    parentnode->childcount = templist[0][0] - 1;
    parentnode->childlist = malloc(sizeof(node) * parentnode->childcount);

    for(int i = 0; i < parentnode->childcount; i++){
	node * child = makenode(parentnode->localboard, parentnode->localturn, templist[i+1]);
	(parentnode->childlist)[i] = child;
	child->depth = parentnode->depth + 1;
	child->parent = parentnode;
    }

    for(int i = 0; i < 49; i++){
	free(templist[i]);
    }

    free(templist);

}

void gametree (node * parentnode){
   
    if(parentnode->depth == DIFF|| parentnode->gameover == true){
	return;
    }	

    setchild(parentnode);

    for(int i = 0; i < parentnode->childcount; i++){
	gametree(parentnode->childlist[i]);
    }
}

void freetree(node * tree) {
    
    if(tree->depth == DIFF || tree->gameover == true){
	free(tree);
	return;	
    }

    for (int i = 0; i < tree->childcount; i++) {
	freetree(tree->childlist[i]);
    }
    free(tree->childlist);
    free(tree);
}

int evaltree(node * parentnode){
    
    if(parentnode->depth == DIFF || parentnode->gameover == true){
	return parentnode -> boardvalue;
    }

    int total = 0;

    for(int i = 0; i < parentnode->childcount; i++){
	total += evaltree(parentnode->childlist[i]);
    }

    parentnode->boardvalue += total;

    return parentnode->boardvalue;
}

int * bestmove (node * parentnode){
   
    node * best = parentnode->childlist[0];
    
    for(int i = 0; i < parentnode->childcount; i++){
	if(best->boardvalue < parentnode->childlist[i]->boardvalue){
	    best = parentnode->childlist[i];
	}
    }

    int counter = 0;
    for(int i = 0; i < parentnode->childcount; i++){
	if(best->boardvalue == parentnode->childlist[i]->boardvalue){
	    counter++;
	}
    }

    srand(time(0));
    int random = rand() % counter;

    int i = 0;
    while(random >= 0){
	if(best->boardvalue == parentnode->childlist[i]->boardvalue){
	    if(random == 0){
		best = parentnode->childlist[i];
	    }
	    random--;
	}
	i++;
    }
   
    return best->movemade;
}

// 1 = white piece, 2 = red piece
int main (int argc, char **argv) {
    
    FILE * log;
    log = fopen("gamelog","w");

    int timer = 0; 
    int AIflag = 0;

    while (argc > 1 && argv[1][0] == '-') {
	switch (argv[1][1])
	{
	    case '0':
		AIflag = 0;
		break;
	    case '1':
		AIflag = 1;
		break;
	    case '2':
		AIflag = 2;
		break;
	    case '?':
		printf("This program allows you to play checkers!\n\nYou can choose one of the following three game modes using flags:\n     -0: No AI players. Play against another human.\n     -1: 1 AI player: play against our checkers AI!\n     -2: 2 AI players. Pit two of our AIs against each other.\n\nSupports five difficulty levels (1-5).\n");
		exit(1);
		break;
	    default:
		printf("You have entered an unsupported flag.\n");
		printf("usage\n");
		exit(1);
		break;
	}

	++argv;
	--argc;
    }
    
    if(AIflag != 0){
	fprintf(stderr, "Please enter a difficulty level between 1 and 5: ");

	int d = getchar();

	int temp = getchar();
	while(temp != '\n'){
	    temp = getchar();
	}

<<<<<<< HEAD
	if(d >= '1' && d <= '9'){
=======
	if(d >= '1' && d <= '5'){
>>>>>>> 55c0cd08ae9da76a8d9fcd3e60bd0978660a7261
	    DIFF = d - '0';
	} else {
	    fprintf(stderr, "You have entered an unsupported difficulty level.\n");
	    exit(1);
	}
    }

    initboard(global_board);

    bool global_mustjump = false;
    
    int irow = 0;
    int icol = 0;
    int frow = 0;
    int fcol = 0;
    
    int jumped = 0;

    while(checkwin(global_board) == 0 && timer <= 1000){

	if(whiteturn){
	    printf("\n<%d: Black turn>\n", timer);
	} else {
	    printf("\n<%d: Red turn>\n", timer);
	}

	printboard(global_board);
	printf("\n");

	if(!global_mustjump){
	    for (int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
		    if(whiteturn && (global_board[i][j] == 1 || global_board[i][j] == 3)){
			//printmovelist(global_board, i, j);	
		    }else if (!whiteturn && (global_board[i][j] == 2 || global_board[i][j] == 4)){
			//printmovelist(global_board, i, j);
		    }
		}
	    }
	} else {
	    //printjumplist(global_board, frow, fcol, irow, icol);
	}
	printf("\n> ");

	
	int input[5] = {0};

	if(AIflag == 0){

	    for(int i = 0; i < 5; i++){
		input[i] = getchar();
	    }

	    int c = getchar();
	    
	    while(c != '\n'){
		c = getchar();
	    }

	} else if (AIflag == 1){
	    if(whiteturn){
		
		for(int i = 0; i < 5; i++){
		input[i] = getchar();
		}

		int c = getchar();
	    
		while(c != '\n'){
		    c = getchar();
		}

	    } else {
		
		node * root;
		root = initroot(global_board, whiteturn, global_mustjump, irow, icol, frow, fcol);

		gametree(root);
		
		if(root->childcount == 0){
		    freetree(root);
		    fprintf(stderr, "No possible moves\n");
		    break;
		}

		evaltree(root);
	
		int * best = bestmove(root);

		input[0] = best[0] + 'A';
		input[1] = best[1] + '1';
		input[2] = ' ';
		input[3] = best[3] + 'A';
		input[4] = best[4] + '1';
		
		freetree(root);
    
	    }

	} else if (AIflag == 2){
	    
	    node * root;
	    root = initroot(global_board, whiteturn, global_mustjump, irow, icol, frow, fcol);

	    gametree(root);

	    if(root->childcount == 0){
		freetree(root);
		fprintf(stderr, "No possible moves\n");
		break;
	    }

	    evaltree(root);
	
	    int * best = bestmove(root);

	    input[0] = best[0] + 'A';
	    input[1] = best[1] + '1';
	    input[2] = ' ';
	    input[3] = best[3] + 'A';
	    input[4] = best[4] + '1';
	    
	    freetree(root);
		
	}

	if(input[0] == 's' && input[1] == 'a' && input[2] == 'v' && input[3] == 'e' && isdigit(input[4])){
	    
	    FILE * save;
    
	    char * location = malloc(sizeof(char) * 3);
	    location[0] = '.';
	    location[1] = 'c';
	    location[2] = input[4];

	    save = fopen(location, "w");

	    for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){	    
		    fprintf(save,"%d", global_board[i][j]);
		}
	    }

	    fprintf(save, "%d", whiteturn ? 0 : 1);
	    fprintf(save, "%d%d%d%d", irow, icol, frow, fcol);
	    fprintf(save, "%d", global_mustjump ? 0 : 1);
	    fprintf(save, "%d", timer);
	    fprintf(save, "-");
	    fprintf(save, "%d", AIflag);
	    fprintf(save, "%d", jumped);

	    fclose(save);
	    free(location);
	    printf("Saved state %d\n", input[4] - '0');

	} else if(input[0] == 'l' && input[1] == 'o' && input[2] == 'a' && input[3] == 'd' && isdigit(input[4])){
	    
	    FILE * load;

	    char * location = malloc(sizeof(char) * 3);
	    location[0] = '.';
	    location[1] = 'c';
	    location[2] = input[4];

	    load = fopen(location, "r");
		
	    if(load == NULL){
		fprintf(stderr, "Invalid FILE\n");
	    } else {

		int c;
		for(int i = 0; i < 8; i++){
		    for(int j = 0; j < 8; j++){
			c = fgetc(load);
			global_board[i][j] = c - '0';
		    }
		}

		c = fgetc(load);
		if(c == '0'){
		    whiteturn = true;
		} else {
		    whiteturn = false;
		}

		c = fgetc(load);
		irow = c -'0';
		c = fgetc(load);
		icol = c -'0';
		c = fgetc(load);
		frow = c -'0';
		c = fgetc(load);
		fcol = c -'0';

		c = fgetc(load);
		if(c == '0'){
		    global_mustjump = true;
		} else {
		    global_mustjump = false;
		}

		int total = 0;
		while((c = fgetc(load)) != '-'){
		    total *= 10; 
		    total += c - '0';
		}
		timer = total;
		c = fgetc(load);
		AIflag = c -'0';
		c = fgetc(load);
		jumped = c -'0';
        
		printf("Loaded state %d\n", input[4] - '0');

		fclose(load);
	    }

		free(location);
		
	} else if(input[0] < 'A' || input[0] > 'H' || input[1] < '1' || input[1] > '8' || input[2] != ' ' || input[3] < 'A' || input[3] > 'H' || input[4] < '1' || input[4] > '8'){
	    printf("Invalid input: %d %d -> %d %d \n", input[0], input[1], input[3], input[4]);
	} else {

	    irow = input[0]-'A';
	    icol = input[1]-'0'-1;
	    frow = input[3]-'A';	
	    fcol = input[4]-'0'-1;

	    printf("\nMoved: %c%c -> %c%c\n",irow+'A', icol+'0'+1, frow+'A', fcol+'0'+1);

	    if(checkmove(global_board, whiteturn, irow, icol, frow, fcol) == 0){
		
		fprintf(log, "%c%c %c%c\n", irow+'A',icol+'0'+1,frow+'A',fcol+'0'+1);

		user = true;
		jumped = movepiece(global_board,whiteturn,irow,icol,frow,fcol);
		user = false;

		if(jumped == 1 && checkjump(global_board,whiteturn,frow,fcol,irow,icol) == 1){
		    global_mustjump = true;
		    printf("You must keep jumping!\n");
		} else {
		    global_mustjump = false;
		    whiteturn = !whiteturn;
		    ai_shift = !ai_shift;
		}
		
		user = true;
		makepromotion(global_board);
		user = false;

	    } else {
		printf("Invalid movement\n");
	    }

	    if(global_mustjump != true){
		timer++;
	    }

	}
	
    }

    fclose(log);

    printf("\n<Final Board>\n");
    printboard(global_board);

    if(checkwin(global_board) == 2){
	printf("Black win!\n");
	return 0;
    } else if(checkwin(global_board) == 1){
	printf("Red win!\n");
	return 0;
    } else {
	int white = 0;
	int red = 0;

	for(int i = 0; i < 8; i++){
	    for(int j = 0; j < 8; j++){
		if (global_board[i][j] == 1 || global_board[i][j] == 3){
		    white++;
		} else if(global_board[i][j] == 2 || global_board[i][j] == 4){
		    red++;
		}

	    }
	}

	if(white > red){
	    printf("Black win!\n");
	    return 0;
	} else if(red > white){
	    printf("Red win!\n");
	    return 0;
	} else {
	    printf("Stalemate!\n");
	    return 0;
	}
    }
}
