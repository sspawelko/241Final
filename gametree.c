#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "checkers.h"

void setchild (node * parentnode){

    int ** templist = movelist(parentnode);
    parentnode->childcount = templist[0][0] - 1;
    parentnode->childlist = malloc(sizeof(node) * parentnode->childcount);

    for(int i = 0; i < parentnode->childcount; i++){
	node * child = makenode(parentnode->localboard, parentnode->localturn, templist[i+1]);
	(parentnode->childlist)[i] = child;
	child->depth = parentnode->depth + 1;
	child->parent = parentnode;
	//printnode(child);
    }

    for(int i = 0; i < 49; i++){
	free(templist[i]);
    }

    free(templist);

}

void gametree (node * parentnode){
   
    if(parentnode->depth == DIFF|| parentnode->gameover == true){
	return;
    }	

    setchild(parentnode);

    for(int i = 0; i < parentnode->childcount; i++){
	gametree(parentnode->childlist[i]);
    }
}

void freetree(node * tree) {
    
    if(tree->depth == DIFF || tree->gameover == true){
	free(tree);
	return;	
    }

    for (int i = 0; i < tree->childcount; i++) {
	freetree(tree->childlist[i]);
    }
    free(tree->childlist);
    free(tree);
}

int evaltree(node * parentnode){
    
    if(parentnode->depth == DIFF || parentnode->gameover == true){
	return parentnode -> boardvalue;
    }

    int total = 0;

    for(int i = 0; i < parentnode->childcount; i++){
	total += evaltree(parentnode->childlist[i]);
    }

    parentnode->boardvalue += total;

    return parentnode->boardvalue;
}

int * bestmove (node * parentnode){
   
    node * best = parentnode->childlist[0];
    
    for(int i = 0; i < parentnode->childcount; i++){
	if(best->boardvalue < parentnode->childlist[i]->boardvalue){
	    best = parentnode->childlist[i];
	}
    }

    int counter = 0;
    for(int i = 0; i < parentnode->childcount; i++){
	if(best->boardvalue == parentnode->childlist[i]->boardvalue){
	    counter++;
	}
    }

    srand(time(0));
    int random = rand() % counter;

    int i = 0;
    while(random >= 0){
	if(best->boardvalue == parentnode->childlist[i]->boardvalue){
	    if(random == 0){
		best = parentnode->childlist[i];
	    }
	    random--;
	}
	i++;
    }

    /*
    printf("\nTEST\n");

    for(int i = 0; i < parentnode->childcount; i++){
	printf("%c%c -> %c%c: %d\n", parentnode->childlist[i]->movemade[0] + 'A', parentnode->childlist[i]->movemade[1] + '1', parentnode->childlist[i]->movemade[3] + 'A', parentnode->childlist[i]->movemade[4] + '1', parentnode->childlist[i]->boardvalue);
    }

    printf("\nTESTDONE\n");
    */
   
    return best->movemade;
}
