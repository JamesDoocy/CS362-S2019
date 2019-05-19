//James Doocy
//CS 362 (SWE 2) Spring 2019
//Assignment 4
//This program tests the Council Room card
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
	int pre_buysNum;
	int err_flag = 0;

	printf("Now testing Council Room Card for Correct number of buys:\n");

	for (i = 0; i < NUM_TESTS; i++){
		int currentPlayer = whoseTurn(&G);
		int handPos = 0;
	
		//random # of players from 2-4	
		randPlayers = rand() % 3 + 2;
		//random seed from 1-1000
		randSeed = rand() % 1000 + 1;

		//randomize game state
		initializeGame(randPlayers, k, randSeed, &G);
		
		//save number of buys in variable
		pre_buysNum = G.numBuys;
	
		//call Council Room card
		councilRoomCard(currentPlayer, &G, handPos);
		
		//check that pre_buysNum == pre_buysNum + 1
		if (pre_buysNum != (G.numBuys + 1)){
			printf("***Error! Current number of buys did not increase by 1***\n");
			printf("pre_buysNum: %d\n", pre_buysNum);
			printf("current number of buys: %d\n", G.numBuys);
			err_flag = 1;
		} 

	}
	if (err_flag == 0){
		printf("***No errors found***\n");
	}
	return 0;
}

