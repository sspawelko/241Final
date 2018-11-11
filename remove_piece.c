// Sean Pawelko
//
// remove_piece.c
// Defines remove_piece().

#include "checkers.h"

void remove_piece(int l1, int l2) {
    extern in board[][];

    board[l1][l2] = 0;
}
