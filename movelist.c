#include <stdio.h>
#include <stdlib.h>

#include "checkers.h"

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


// this
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

// must jump support
int ** movelist(node * n){

    int counter = 1;
    //int * values;
    int ** list;

    if(n->mustjump == false){
    
	//values = calloc(49 * 5, sizeof(int));
	list = malloc(sizeof(int*) * 49);

	for (int i = 0; i < 49; i++){
	    //list[i] = values + (i * 5);
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
	
	//values = calloc(49 * 5, sizeof(int));
	list = malloc(sizeof(int*) * 49);

	for (int i = 0; i < 49; i++){
	    //list[i] = values + (i * 5);
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

/*
void printlist (int movelist[48][5]){
    
    int i = 0;

    while (movelist[i][0] != -1){
	printf("| %c%d -> %c%d |\n", movelist[i][0] + 'A', movelist[i][1] + 1, movelist[i][3] + 'A', movelist[i][4] + 1);
	i++;
    }
}*/
