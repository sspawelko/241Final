#include "checkers.h"

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

