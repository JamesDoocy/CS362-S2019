//James Doocy
//CS 362 (SWE 2) Spring 2019
//Assignment 4
//This program tests the Smithy card
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include "rngs.h"

#define NUM_TESTS 1000

int main(){

	srand(time(NULL));

	struct gameState G;
	int k[10] = {adventurer, council_room, feast, gardens, mine
			, remodel, smithy, village, baron, great_hall};
	int randPlayers, randSeed, i;
	int pre_handcount;
	int err_flag = 0;

	printf("***Now testing Smithy card for correct hand count:\n");

	for (i = 0; i < NUM_TESTS; i++){
		int currentPlayer = 0;
		int handPos = 0;
	
		//random # of players from 2-4	
		randPlayers = rand() % 3 + 2;
		//random seed from 1-1000
		randSeed = rand() % 1000 + 1;

		//randomize game state
		initializeGame(randPlayers, k, randSeed, &G);
		
		//save hand count in var pre_handcount
		pre_handcount = G.handCount[whoseTurn(&G)];
	
		//call Smithy card
		smithyCard(currentPlayer, &G, handPos);
		
		//check that  pre_handcount = pre_handcount + 3
		if (pre_handcount != G.handCount[whoseTurn(&G)] + 3){
			printf("***Error! Current handcount did not increase by 3***\n");
			printf("pre_handcount: %d\n", pre_handcount);
			printf("current handcount: %d\n", G.handCount[whoseTurn(&G)]);
			err_flag = 1;
		} 

	}
	if (err_flag == 0){
		printf("***No errors found***\n");
	}
	return 0;
}

