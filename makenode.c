#include <stdio.h>
#include <stdlib.h>

#include "checkers.h"

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
