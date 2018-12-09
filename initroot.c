#include "checkers.h"

//UNUSED CODE

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

