/* -----------------------------------------------------------------------
 *Unit Test 3
 *Tests treasureMapCard() function from dominion.c for correect execution 
 *After treasureMapCard() is called, -1 should be returned if there's only 1
 *treasure_map card in deck, and 1 should be returned if there are 2 in the deck
 *Include the following lines in your makefile:
 *unittest3: unittest3.c dominion.o rngs.o
 *	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int asserttrue(int, int);

int asserttrue(int a, int b){
    if (a == b)
        return 1;
    else
        return 0;
}

int main() {

    struct gameState G;
    int init_pass = -1;
    int numPlayer = 2;
    int handPos = 0;
    int seed = 1000;
    int currentPlayer = 0;

    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    init_pass = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    if (asserttrue(init_pass, 1)){
        printf ("initializeGame() failed. Exiting...\n"); 
        return 0;  
    }

    G.deck[0][0] = treasure_map;
    //test to make sure treasure map card can't be played with only one it hand
    if (asserttrue(treasureMapCard(0, &G, currentPlayer, handPos), -1)){
        printf ("1 Treasure Map card test passed\n"); 
    } else {
        printf ("1 Treasure Map card test failed. Hand has only one treasure map.\n");
    }

    G.deck[0][1] = treasure_map;
    //test with two treasure map cards in hand
    if (asserttrue(treasureMapCard(0, &G, currentPlayer, handPos), 1)){
        printf ("2 Treasure Map cards test passed\n"); 
    } else {
        printf ("2 Treasure Map cards test failed.\n");
    }

    return 0;
}
