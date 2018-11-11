// Sean Pawelko
//
// get_move.c
// Defines get_move_black().

#include "checkers.h"


int [] get_move() {
    int moves[4];
    
    for (int i = 0; i < 4; i++) {
	moves[i] = -1;
    }
    
    int position = 0;
    char character = getchar();
    while (!isspace(character) && character != EOF) {
	if (character > 47 && character < 57 && position < 5) {
	    moves[position] = character-48;
	    position++;
	}
    }

    if (moves[4] == -1) {
	printf("Invalid input to get_moves().\n");
    }

    // Check the legality of the move.

    return moves;
}

