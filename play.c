// Sean Pawelko
//
// play.c
// The main function. Play checkers.

#include "checkers.h"

void play() {
    extern int board[][];

    // So first, initiate the board.
    initiate_board();

    // While the game is not won, play.
    int turn = 0;
    int iswon = check_win();
    while (iswon == 0) {
	// Generate a legal move list for the both players.
	// somehow...
	
	// Enforce turns somehow.	
	// Get a move either from the AI or from a player.
	if (turn = 0) {
	    int moves[] = get_moves_red();
	}
	if (turn = 1) {
	    int moves[] = get_moves_black();
	}

	// Move the piece.
	move_piece(moves[0], moves[1], moves[2], moves[3]);

	// Check if any pieces must be promoted.
	check_promotion();

	// Print the board.
	print_board();

	// Switch turns.
	if (turn == 0) {
	    turn = 1;
	}
	if (turn = 1) {
	    turn = 0;
	}
	
	// Check if the game has been won.
	iswon = check_win();
    }

    // If we've stopped playing, that means someone has won.
    if (iswon == 1) {
	printf("Red wins!\n");
    }
    if (iswon == 2) {
	printf("Black wins!\n");
    }





