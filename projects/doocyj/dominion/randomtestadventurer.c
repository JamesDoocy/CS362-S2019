//James Doocy
//CS 362 (SWE 2) Spring 2019
//Assignment 4
//This program tests the Adventurer card
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

	printf("***Now testing Adventurer card:\n");

	for (i = 0; i < NUM_TESTS; i++){
		int drawntreasure = 0;
		int currentPlayer = 0;
		int cardDrawn = 0;
		int temphand[50];
	
		//random # of players from 2-4	
		randPlayers = rand() % 3 + 2;
		//random seed from 1-1000
		randSeed = rand() % 1000 + 1;

		//randomize game state
		initializeGame(randPlayers, k, randSeed, &G);
		
		//save hand count in var pre_handcount
		pre_handcount = G.handCount[whoseTurn(&G)];
	
		//call adventurer card
		adventurerCard(drawntreasure, &G, currentPlayer, cardDrawn, temphand);
		
		//check that pre_handcount = pre_handcount + 2
		if (pre_handcount != G.handCount[whoseTurn(&G)] + 2){
			printf("***Error! Current handcount did not increase by 2***\n");
			printf("pre_handcount: %d\n", pre_handcount);
			printf("current handcount: %d\n", G.handCount[whoseTurn(&G)]);
		} 

	}
	return 0;
}

