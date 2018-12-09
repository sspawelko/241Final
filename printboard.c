#include "checkers.h"

// Print current board
void printboard(int board[8][8]) {
    printf("   1 2 3 4 5 6 7 8\n");

    for (int i = 0; i < 8; i++) {
	putchar('A'+i);
	printf("| ");

	for (int j = 0; j < 8; j++) {
	    printf("%d ", board[i][j]);
	}

	printf("\n");
    }
}
