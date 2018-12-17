#ifndef CHECKERS_H
#define CHECKERS_H

#include <stdbool.h>

// Typedef declaration
typedef struct checkernode {
	
    int localboard[8][8];
    bool localturn;
    bool mustjump;
    bool gameover;
    int boardvalue;
    int depth;
    int movemade[5];
    int childcount;
    struct checkernode ** childlist;
    struct checkernode * parent;

} node;

// Global variables
extern int global_board[8][8];
extern bool whiteturn;
extern int DIFF;
extern bool user;
extern bool ai_shift;

// Function declaration
void initboard(int board[8][8]);
void printboard(int board[8][8]);
int checkwin(int board[8][8]);
int checkmove (int board[8][8], bool localturn, int irow, int icol, int frow, int fcol);
void makepromotion(int board[8][8]);
int movepiece (int board[8][8], bool localturn, int irow, int icol, int frow, int fcol);
int checkjump (int board[8][8], bool localturn, int row, int col, int irow, int icol);
void printmovelist(int board[8][8], int row, int col);
void printjumplist(int board[8][8], int row, int col, int irow, int icol);

int ** movelist(node * n);
void printlist (int movelist[48][5]);
node * makenode(int current_board[8][8], bool current_turn, int newmove[5]);
void printnode(node * temp);
node * initroot(int current_board[8][8], bool current_turn, bool current_mustjump, int irow, int icol, int frow, int fcol);
void setchild (node * parentnode);
void gametree (node * parentnode);
void freetree(node * tree);
int evaltree(node * parentnode);
int * bestmove (node * parentnode);

#endif
