#include "checkers.h"

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

