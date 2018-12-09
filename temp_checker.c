#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int global_board[8][8] = {0};
bool whiteturn = true;
//bool jumped = false;

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
	    printf("%d ", board[i][j]);
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
		white++;
	    } else if (board[i][j] == 2||board[i][j] == 4){
		red++;
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
		if(board[irow+1][icol+1] == 0){
		    //printf("Invalid jump\n");
		    return 1;
		}
	    } else if (fcol == icol - 2){
		if(board[irow+1][icol-1] == 0){
		    //printf("Invalid jump\n");
		    return 1;
		}
	    } else {
		//printf("Invalid movement\n");
		return 1;
	    }
	} else if(localturn != true && frow == irow - 2){
	    if(fcol == icol + 2){
		if(board[irow-1][icol+1] == 0){
		    //printf("Invalid jump\n");
		    return 1;
		}
	    } else if (fcol == icol - 2){
		if(board[irow-1][icol-1] == 0){
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
		if(board[irow+1][icol+1] == 0){
		    //printf("Invalid jump\n");
		    return 1;	
		}
	    // Jumping left
	    } else if (fcol == icol - 2){
		if(board[irow+1][icol-1] == 0){
		    //printf("Invalid jump\n");
		    return 1;	
		}
	    } else {
		//printf("Invalid movement\n");
		return 1;
	    }	
    
	// Jumping upwards
	} else if (frow == irow - 2){
	    // Jumping right
	    if(fcol == icol + 2){
		if(board[irow-1][icol+1] == 0){
		    //printf("Invalid jump\n");
		    return 1;	
		}
	    // Jumping left
	    } else if (fcol == icol - 2){
		if(board[irow-1][icol-1] == 0){
		    //printf("Invalid jump\n");
		    return 1;	
		}
	    } else {
		//printf("Invalid movement\n");
		return 1;
	    }
	}
    }
           
    return 0;
}

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
		    printf("Red piece at %c%c taken!\n", irow+'A'+1, icol+'0'+2);
		    board[irow+1][icol+1] = 0;
		} else if (localturn != true && (board[irow+1][icol+1] == 1 || board[irow+1][icol+1] == 3)){
		    printf("White piece at %c%c taken!\n", irow+'A'+1, icol+'0'+2);
		    board[irow+1][icol+1] = 0;
		}

	    // Jumping left
	    } else if (fcol == icol - 2){
		
		if(localturn == true && (board[irow+1][icol-1] == 2 || board[irow+1][icol-1] == 4)){
		    printf("Red piece at %c%c taken!\n", irow+'A'+1, icol+'0');
		    board[irow+1][icol-1] = 0;
		} else if (localturn != true && (board[irow+1][icol-1] == 1 || board[irow+1][icol-1] == 3)){
		    printf("White piece at %c%c taken!\n", irow+'A'+1, icol+'0');
		    board[irow+1][icol-1] = 0;
		}

	    }
    
	// Jumping upwards
	} else if (frow == irow - 2){
	    // Jumping right
	    if(fcol == icol + 2){
		
		if(localturn == true && (board[irow-1][icol+1] == 2 || board[irow-1][icol+1] == 4)){
		    printf("Red piece at %c%c taken!\n", irow+'A'-1, icol+'0'+2);
		    board[irow-1][icol+1] = 0;
		} else if (localturn != true && (board[irow-1][icol+1] == 1 || board[irow-1][icol+1] == 3)){
		    printf("White piece at %c%c taken!\n", irow+'A'-1, icol+'0'+2);
		    board[irow-1][icol+1] = 0;
		}

	    // Jumping left
	    } else if (fcol == icol - 2){
		
		if(localturn == true && (board[irow-1][icol-1] == 2 || board[irow-1][icol-1] == 4)){
		    printf("Red piece at %c%c taken!\n", irow+'A'-1, icol+'0');
		    board[irow-1][icol-1] = 0;
		} else if (localturn != true && (board[irow-1][icol-1] == 1 || board[irow-1][icol-1] == 3)){
		    printf("White piece at %c%c taken!\n", irow+'A'-1, icol+'0');
		    board[irow-1][icol-1] = 0;
		}

	    }
	}

    }

    makepromotion(board);

    return jumped;
}


/*
void movepiece (int board[8][8], int irow, int icol, int frow, int fcol){

    if(whiteturn == true){
	
	// No jumping (normal + promoted)
	if(frow == irow + 1||frow == irow - 1){
	    board[frow][fcol] = board[irow][icol];
	    board[irow][icol] = 0;

	// Jumping
	} else if (frow == irow + 2){
	    board[frow][fcol] = board[irow][icol];
	    board[irow][icol] = 0;

	    if(fcol == icol + 2){
		if(board[irow+1][icol+1] == 2){
		    printf("Red piece at %c%c taken!\n", irow+'A'+1, icol+'0'+2);
		    board[irow+1][icol+1] = 0;
		}
	    } else if (fcol == icol - 2){
		if(board[irow+1][icol-1] == 2){
		    printf("Red piece at %c%c taken!\n", irow+'A'+1, icol+'0');
		    board[irow+1][icol-1] = 0;
		}
	    }
	}


    } else if (whiteturn != true){

	// No jumping (normal + promoted)
	if(frow == irow + 1||frow == irow - 1){
	    board[frow][fcol] = board[irow][icol];
	    board[irow][icol] = 0;
	
	// Jumping
	} else if (frow == irow - 2){
	    board[frow][fcol] = board[irow][icol];
	    board[irow][icol] = 0;

	    if(fcol == icol + 2){
		if(board[irow-1][icol+1] == 1){
		    printf("White piece at %c%c taken!\n", irow+'A'-1, icol+'0'+2);
		    board[irow-1][icol+1] = 0;
		}
	    } else if (fcol == icol - 2){
		if(board[irow-1][icol-1] == 1){
		    printf("White piece at %c%c taken!\n", irow+'A'-1, icol+'0');
		    board[irow-1][icol-1] = 0;
		}
	    }
	}

    }

    makepromotion(board);
}*/

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

    //	Promoted pieces
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

// Prints out all possible move locations
void printmovelist(int board[8][8], int row, int col ){

    printf("Movelist for %c%c: ", row+'A', col+'0'+1);

    for(int i = -2; i < 3; i++){
	for (int j = -2; j < 3; j++){
	    if(!(i == 0 && j == 0)){
		
		if(checkmove(board, whiteturn, row, col, row + i, col + j) == 0){
		    printf("%c%c ", row + i + 'A', col + j + '0' + 1);
		}
	    }
	}
    }

    printf("\n");

}




void printlist (int movelist[48][5]);

int ** movelist (int board[8][8], bool localturn){
    
    int * values = calloc(49 * 5, sizeof(int));
    int ** list = malloc(sizeof(int*) * 49);

    for (int i = 0; i < 49; i++){
	list[i] = values + (i * 5);
    }

    int counter = 1;

    for(int i = 0; i < 8; i++){
	for(int j = 0; j < 8; j++){

	    if(localturn && (global_board[i][j] == 1 || global_board[i][j] == 3)){

		for(int k = -2; k < 3; k++){
		    for (int l = -2; l < 3; l++){
			
			if(checkmove(board, localturn, i, j, i + k, j + l) == 0){
			    
			    /*
			    char movestr[4];
			    movestr[0] = i;
			    movestr[1] = j;
			    movestr[2] = i + k;
			    movestr[3] = j + l;
			    */

			    list[counter][0] = i;
			    list[counter][1] = j;
			    list[counter][3] = i + k;
			    list[counter][4] = j + l;

			    counter++;
			}

		    }
		}

	    }else if (!localturn && (global_board[i][j] == 2 || global_board[i][j] == 4)){
		
		for(int k = -2; k < 3; k++){

		    for (int l = -2; l < 3; l++){
			
			if(checkmove(board, localturn, i, j, i + k, j + l) == 0){
			    
			    list[counter][0] = i;
			    list[counter][1] = j;
			    list[counter][2] = i + k;
			    list[counter][3] = j + l;

			    counter++;
			}

		    }
		}	 

	}
    }
    }
    list[0][0] = counter;

    //printlist(movelist);

    return list;
}

// temporary
void printlist (int movelist[48][5]){
    
    int i = 0;

    while (movelist[i][0] != -1){
	printf("| %c%d -> %c%d |\n", movelist[i][0] + 'A', movelist[i][1] + 1, movelist[i][3] + 'A', movelist[i][4] + 1);
	i++;
    }
}


typedef struct checkernode {

    int localboard[8][8];
    bool localturn;

    int jumped;

    bool gameover;

    int boardvalue;

    int movemade[5];

    int childcount;
    struct checkernode ** childlist;

} node;

/*
void initroot(node * root){

    int value = 0;
    for(int i = 0; i < 8; i++){
	for(int j = 0; j < 8; j++){
	    root->localboard[i][j] = global_board[i][j];
	    if(global_board[i][j] == 2 || global_board[i][j] == 4){
		value--;
	    } if(global_board[i][j] == 1 || global_board[i][j] == 3){
		value++;
	    }
	}
    }
    
    root->boardvalue = value;
    root->localturn = whiteturn;
    
    int movecount = givemove(global_board, localturn);
    node ** list = malloc(sizeof(node) * movecount);
    root->childlist = list;
}*/

// No make childlist need movemade support
node * makenode(int current_board[8][8], bool current_turn, int newmove[5]){

    int value = 0;

    node * temp = malloc(sizeof(node));
    for(int i = 0; i < 8; i++){
	for(int j = 0; j < 8; j++){
	    temp->localboard[i][j] = current_board[i][j];
	    
	    if(global_board[i][j] == 2 || global_board[i][j] == 4){
		value--;
	    } if(global_board[i][j] == 1 || global_board[i][j] == 3){
		value++;
	    }

	}
    }
    
    //THROWS SEGFAULT HERE
    int justjumped = movepiece(temp->localboard, current_turn, newmove[0], newmove[1], newmove[3], newmove[4]);

    if(justjumped == 1 && checkjump(current_board,current_turn,newmove[3],newmove[4],newmove[0],newmove[1]) == 1){
	temp->jumped = justjumped;
	temp->localturn = current_turn;
    } else {
	temp->jumped = justjumped;
	temp->localturn = !current_turn;
    }

    for (int i = 0; i < 5; i++){
	temp->movemade[i] = newmove[i];
    }

    if(checkwin(current_board) == 2){
	value -= 100;
	temp->gameover = true;
    } else if(checkwin(current_board) == 1){
	value += 100;
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
    printf("Jumped: %s\n", temp->jumped ? "true" : "false");
    printf("Localturn: %s\n", temp->localturn ? "true" : "false");
    printf("Gameover: %s\n", temp->gameover ? "true" : "false");
    printf("Boardvalue: %d\n", temp->boardvalue);
    printf("Move: %c%c -> %c%c\n", temp->movemade[0] + 'A', temp->movemade[1] + '1', temp->movemade[3]  + 'A', temp->movemade[4] + '1');
    printf("------------------------------------\n");

}

void setchild (node * parentnode){


}


// 1 = white piece, 2 = red piece
int main (){

    //int global_board[8][8] = {0};
    initboard(global_board);
    
    while(checkwin(global_board) == 0){

	int jumped;

	printboard(global_board);

	

	//jumped = false;
	jumped = 0;
	printf("\n");

	//int movecount = givemove(global_board, whiteturn, movelist); 

	//printf("\n%d moves\n", movecount);
		
	for (int i = 0; i < 8; i++){
	    for(int j = 0; j < 8; j++){
		if(whiteturn && (global_board[i][j] == 1 || global_board[i][j] == 3)){
		    printmovelist(global_board, i, j);	
		}else if (!whiteturn && (global_board[i][j] == 2 || global_board[i][j] == 4)){
		    printmovelist(global_board, i, j);
		}
	    }
	}

	node * root;
	
	int ** templist = movelist(global_board, whiteturn);

	for(int i = 1; i <= templist[0][0] -1; i++){
	    root = makenode(global_board, whiteturn, templist[i]);
	    printnode(root);
	    free(root);
	}

	printboard(global_board);

	if(whiteturn){
	    printf("White move: ");
	} else {
	    printf("Red move: ");
	}

	int input[5] = {0};
	for(int i = 0; i < 5; i++){
	    input[i] = getchar();
	}

	int c = getchar();
	while(c != '\n'){
	    c = getchar();
	}
	
	if(input[0] < 'A' || input[0] > 'H' || input[1] < '1' || input[1] > '8' || input[2] != ' ' || input[3] < 'A' || input[3] > 'H' || input[4] < '1' || input[4] > '8'){
	    printf("Invalid input\n");
	} else {

	    int irow = input[0]-'A';
	    int icol = input[1]-'0'-1;
	    int frow = input[3]-'A';	
	    int fcol = input[4]-'0'-1;

	    printf("Move: %c%c -> %c%c\n",irow+'A', icol+'0'+1, frow+'A', fcol+'0'+1);

	    if(checkmove(global_board, whiteturn, irow, icol, frow, fcol) == 0){
		jumped = movepiece(global_board,whiteturn,irow,icol,frow,fcol);

		// Must Jump!
		if(jumped == 1 && checkjump(global_board,whiteturn,frow,fcol,irow,icol) == 1){
		    printf("You must make a jump!\n");
		} else {
		    whiteturn = !whiteturn;
		}
	    } else {
		printf("Invalid movement\n");
	    }

	}
    }

    node * root = makenode(global_board, whiteturn, false);
    printnode(root);
    free(root);


    printboard(global_board);

    if(checkwin(global_board) == 2){
	printf("White win!\n");
	return 0;
    } else if(checkwin(global_board) == 1){
	printf("Red win!\n");
	return 0;
    }


}
