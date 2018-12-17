#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "checkers.h"

int global_board[8][8] = {{0}};
bool whiteturn = true;
int DIFF = 1;

bool user = false;
bool ai_shift = true;

// 1 = white piece, 2 = red piece
int main (int argc, char **argv) {
    
    FILE * log;
    log = fopen("gamelog","w");

    int timer = 0; 
    int AIflag = 0;

    while (argc > 1 && argv[1][0] == '-') {
	switch (argv[1][1])
	{
	    case '0':
		AIflag = 0;
		break;
	    case '1':
		AIflag = 1;
		break;
	    case '2':
		AIflag = 2;
		break;
	    case '?':
		printf("With this program, you can play checkers!\n\nYou can choose from 3 game modes with flags:\n     -0: No AI players, human vs human.\n     -1: 1 AI player, human vs AI.\n     -2: 2 AI players, AI vs AI.\n\nSupports difficulty levels 1-7.\n");
		exit(1);
		break;
	    default:
		printf("You have entered an unsupported flag.\n");
		printf("usage\n");
		exit(1);
		break;
	}

	++argv;
	--argc;
    }
    
    if(AIflag != 0){
	fprintf(stderr, "Please enter a difficulty level between 1 and 4: ");

	int d = getchar();

	int temp = getchar();
	while(temp != '\n'){
	    temp = getchar();
	}

	if(d >= '1' && d <= '9'){
	    DIFF = d - '0';
	} else {
	    fprintf(stderr, "You have entered an unsupported difficulty level.\n");
	    exit(1);
	}
    }

    initboard(global_board);

    bool global_mustjump = false;
    
    int irow = 0;
    int icol = 0;
    int frow = 0;
    int fcol = 0;
    
    int jumped = 0;

    while(checkwin(global_board) == 0 && timer <= 100){

	//printboard(global_board);
	//printf("\n");

	if(whiteturn){
	    printf("\n<%d: Black turn>\n", timer);
	} else {
	    printf("\n<%d: Red turn>\n", timer);
	}

	printboard(global_board);
	printf("\n");

	if(!global_mustjump){
	    for (int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
		    if(whiteturn && (global_board[i][j] == 1 || global_board[i][j] == 3)){
			//printmovelist(global_board, i, j);	
		    }else if (!whiteturn && (global_board[i][j] == 2 || global_board[i][j] == 4)){
			//printmovelist(global_board, i, j);
		    }
		}
	    }
	} else {
	    //printjumplist(global_board, frow, fcol, irow, icol);
	}
	printf("\n> ");

	
	int input[5] = {0};

	if(AIflag == 0){

	    for(int i = 0; i < 5; i++){
		input[i] = getchar();
	    }

	    int c = getchar();
	    
	    while(c != '\n'){
		c = getchar();
	    }

	} else if (AIflag == 1){
	    if(whiteturn){
		
		for(int i = 0; i < 5; i++){
		input[i] = getchar();
		}

		int c = getchar();
	    
		while(c != '\n'){
		    c = getchar();
		}

	    } else {
		
		node * root;
		root = initroot(global_board, whiteturn, global_mustjump, irow, icol, frow, fcol);

		gametree(root);
		
		if(root->childcount == 0){
		    freetree(root);
		    fprintf(stderr, "No possible moves\n");
		    break;
		}

		evaltree(root);
	
		//int * best = malloc(sizeof(int) * 5);
		int * best = bestmove(root);

		input[0] = best[0] + 'A';
		input[1] = best[1] + '1';
		input[2] = ' ';
		input[3] = best[3] + 'A';
		input[4] = best[4] + '1';
		
		freetree(root);
    
	    }

	} else if (AIflag == 2){
	    
	    node * root;
	    root = initroot(global_board, whiteturn, global_mustjump, irow, icol, frow, fcol);

	    gametree(root);

	    if(root->childcount == 0){
		freetree(root);
		fprintf(stderr, "No possible moves\n");
		break;
	    }

	    evaltree(root);
	
	    //int * best = malloc(sizeof(int) * 5);
	    int * best = bestmove(root);

	    input[0] = best[0] + 'A';
	    input[1] = best[1] + '1';
	    input[2] = ' ';
	    input[3] = best[3] + 'A';
	    input[4] = best[4] + '1';
	    
	    //printnode(root);
	    
	    //free(best);
	    freetree(root);

	    //free(best);
		
	}

	if(input[0] == 's' && input[1] == 'a' && input[2] == 'v' && input[3] == 'e' && isdigit(input[4])){
	    
	    FILE * save;
    
	    char * location = malloc(sizeof(char) * 3);
	    location[0] = '.';
	    location[1] = 'c';
	    location[2] = input[4];

	    save = fopen(location, "w");

	    for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){	    
		    fprintf(save,"%d", global_board[i][j]);
		}
	    }

	    fprintf(save, "%d", whiteturn ? 0 : 1);
	    fprintf(save, "%d%d%d%d", irow, icol, frow, fcol);
	    fprintf(save, "%d", global_mustjump ? 0 : 1);
	    fprintf(save, "%d", timer);
	    fprintf(save, "-");
	    fprintf(save, "%d", AIflag);
	    fprintf(save, "%d", jumped);

	    fclose(save);
	    free(location);
	    printf("Saved state %d\n", input[4] - '0');

	} else if(input[0] == 'l' && input[1] == 'o' && input[2] == 'a' && input[3] == 'd' && isdigit(input[4])){
	    
	    FILE * load;

	    char * location = malloc(sizeof(char) * 3);
	    location[0] = '.';
	    location[1] = 'c';
	    location[2] = input[4];

	    load = fopen(location, "r");
		
	    if(load == NULL){
		fprintf(stderr, "Invalid FILE\n");
	    } else {

		int c;
		for(int i = 0; i < 8; i++){
		    for(int j = 0; j < 8; j++){
			c = fgetc(load);
			global_board[i][j] = c - '0';
		    }
		}

		c = fgetc(load);
		if(c == '0'){
		    whiteturn = true;
		} else {
		    whiteturn = false;
		}

		c = fgetc(load);
		irow = c -'0';
		c = fgetc(load);
		icol = c -'0';
		c = fgetc(load);
		frow = c -'0';
		c = fgetc(load);
		fcol = c -'0';

		c = fgetc(load);
		if(c == '0'){
		    global_mustjump = true;
		} else {
		    global_mustjump = false;
		}

		int total = 0;
		while((c = fgetc(load)) != '-'){
		    total *= 10; 
		    total += c - '0';
		}
		timer = total;
		c = fgetc(load);
		AIflag = c -'0';
		c = fgetc(load);
		jumped = c -'0';
        
		printf("Loaded state %d\n", input[4] - '0');

		fclose(load);
	    }

		free(location);
		
	} else if(input[0] < 'A' || input[0] > 'H' || input[1] < '1' || input[1] > '8' || input[2] != ' ' || input[3] < 'A' || input[3] > 'H' || input[4] < '1' || input[4] > '8'){
	    printf("Invalid input: %d %d -> %d %d \n", input[0], input[1], input[3], input[4]);
	} else {

	    irow = input[0]-'A';
	    icol = input[1]-'0'-1;
	    frow = input[3]-'A';	
	    fcol = input[4]-'0'-1;

	    printf("\nMoved: %c%c -> %c%c\n",irow+'A', icol+'0'+1, frow+'A', fcol+'0'+1);

	    if(checkmove(global_board, whiteturn, irow, icol, frow, fcol) == 0){
		
		fprintf(log, "%c%c %c%c\n", irow+'A',icol+'0'+1,frow+'A',fcol+'0'+1);

		user = true;
		jumped = movepiece(global_board,whiteturn,irow,icol,frow,fcol);
		user = false;

		if(jumped == 1 && checkjump(global_board,whiteturn,frow,fcol,irow,icol) == 1){
		    global_mustjump = true;
		    printf("You must keep jumping!\n");
		} else {
		    global_mustjump = false;
		    whiteturn = !whiteturn;
		    ai_shift = !ai_shift;
		}
		
		user = true;
		makepromotion(global_board);
		user = false;

	    } else {
		printf("Invalid movement\n");
	    }

	    if(global_mustjump != true){
		timer++;
	    }

	}

	//free(best);	
    }

    fclose(log);

    printf("\n<Final Board>\n");
    printboard(global_board);

    if(checkwin(global_board) == 2){
	printf("Black win!\n");
	return 0;
    } else if(checkwin(global_board) == 1){
	printf("Red win!\n");
	return 0;
    } else {
	int white = 0;
	int red = 0;

	for(int i = 0; i < 8; i++){
	    for(int j = 0; j < 8; j++){
		if (global_board[i][j] == 1 || global_board[i][j] == 3){
		    white++;
		} else if(global_board[i][j] == 2 || global_board[i][j] == 4){
		    red++;
		}

	    }
	}

	if(white > red){
	    printf("Black win!\n");
	    return 0;
	} else if(red > white){
	    printf("Red win!\n");
	    return 0;
	} else {
	    printf("Stalemate!\n");
	    return 0;
	}
    }
}
