#include <stdio.h>

#include "checkers.h"

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

// Evaluates the board to make promotions
void makepromotion(int board[8][8]){
    for(int i = 0; i < 8; i++){
	if(board[0][i] == 2){
	    if(user == true){
		printf("Red piece at A%c promoted!\n", i+'1');
	    }
	    board[0][i] = 4;
	} else if (board[7][i] == 1){
	    if(user == true){
		printf("Black piece at F%c promoted!\n", i+'1');
	    }
	    board[7][i] = 3;
	}
    }
}



