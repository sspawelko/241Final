// Sean Pawelko
//
// move_piece.c
// Defines move_piece().

#include "checkers.h"


void move_piece(int l1, int l2, int l3, int l4, int board[][]) {
    board[l3][l4] = board[l1][l2];
    board[l1][l2] = 0;
    
    // If we have jumped a piece, we must remove it.
    if ((l4-l2) == 2 || (l4-l2) == -2) {
	remove_piece(((l4+l2)/2), ((l3+l1)/2));
    }
}
