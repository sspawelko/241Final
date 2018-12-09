#include "checkers.h"

//bool whiteturn;

// 1 = white piece, 2 = red piece
int main (){
     bool turn = false;

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
		if(turn && (global_board[i][j] == 1 || global_board[i][j] == 3)){
		    printmovelist(global_board, i, j, turn);	
		}else if (!turn && (global_board[i][j] == 2 || global_board[i][j] == 4)){
		    printmovelist(global_board, i, j, turn);
		}
	    }
	}

	node * root;
	
	int ** templist = movelist(global_board, turn);

	for(int i = 1; i <= templist[0][0] -1; i++){
	    root = makenode(global_board, turn, templist[i]);
	    printnode(root);
	    free(root);
	}

	printboard(global_board);

	if(turn){
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

	    if(checkmove(global_board, turn, irow, icol, frow, fcol) == 0){
		jumped = movepiece(global_board,turn,irow,icol,frow,fcol);

		// Must Jump!
		if(jumped == 1 && checkjump(global_board,turn,frow,fcol,irow,icol) == 1){
		    printf("You must make a jump!\n");
		} else {
		    turn = !turn;
		}
	    } else {
		printf("Invalid movement\n");
	    }

	}
    }

    node * root = makenode(global_board, turn, false);
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
