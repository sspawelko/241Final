#include "checkers.h"

void printnode(node * temp){
    
    printf("\n------------------------------------\nNode\n");
    printboard(temp->localboard);
    printf("Jumped: %s\n", temp->jumped ? "true" : "false");
    printf("Localturn: %s\n", temp->localturn ? "true" : "false");
    printf("Gameover: %s\n", temp->gameover ? "true" : "false");
    printf("Boardvalue: %d\n", temp->boardvalue);
    printf("Move: %c%c -> %c%c\n", temp->movemade[0] + 'A', temp->movemade[1] + '1', temp->movemade[3]  + 'A', temp->movemade[4] + '1');
    printf("------------------------------------\n");

}
