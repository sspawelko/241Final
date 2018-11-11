// Sean Pawelko
//
// checkers.h
// 
// Variables:
// [8][8] board: An array of ints representing the baord. 0 = empty, 1 = red unpromoted, 2 = red promoted, 3 = black unpromoted, 4 = black promoted.
// 
// Functions:
// void init_board(): sets up the board for the game.
// int evaluate(int player): evaluates the baord for a player. 0 = red, 1 = black.
// void move_piece(): moves a piece from (l1, l2) to (l3, l4).
// void remove_piece(): removes the piece at (l1, l2).
// void check_promotion(): checks if pieces must be promoted. Promtes if necessary.
// int check win(): checks if a player has won. 0 if the game is not won, 1 for the red player's win, 2 for the black player's win.
//
// int [][][] legal_moves(int player, int l1, int l2): returns an int [][][] of legal moves for the player. 0 = red, 1 = black.
//
// int [] get_move_red(): reads in the red player's move. Returns an int [4]. Move the piece from (0, 1) to (2, 3).
//
// int [] get_move_black(): reads in the black player's move. Returns an int [4]. Move the piece from (0, 1) to (2, 3).
//
// void print_board(): prints the board.
//
// void play(): play the game.

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef CTYPE_H
#define CTYPE_H
#include <ctype.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef CHECKERS_H
#define CHECKERS_H
int board[8][8];

void init_board();
int evaluate_b(int player);
void move_piece(int l1, int l2, int l3, int l4);
void remove_piece(int l1, int l2);
int check_win();
int [][][] legal_moves(int player);
int [] get_move();
void print_board();
void play();
#endif



// TODO
//
// Change check_win() to check instead for legal moves. If a player has no legal moves left, they lose.
//
// Implement legal_moves().
//
// Create a play() function. Enforce turns.
//
// Test everything.
