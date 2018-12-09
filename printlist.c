#include "checkers.h"

// temporary
void printlist (int movelist[48][5]){
    
    int i = 0;

    while (movelist[i][0] != -1){
	printf("| %c%d -> %c%d |\n", movelist[i][0] + 'A', movelist[i][1] + 1, movelist[i][3] + 'A', movelist[i][4] + 1);
	i++;
    }
}
