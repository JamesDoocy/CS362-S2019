/* -----------------------------------------------------------------------
 *Unit Test 1
 *Tests councilRoomCard() function from dominion.c for card quantity and number of buys
 *After councilRoomCard() is called, the current player should gain 4 cards to their hand
 *and also gain 1 buy
 *Include the following lines in your makefile:
 *unittest1: unittest1.c dominion.o rngs.o
 *	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
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
    int testCardQuant = 0;
    int testNumBuys = 0;
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
  
    printf ("Current player's (player %d) card quantity: %d\n", currentPlayer, G.handCount[currentPlayer]);
    printf ("Current player's (player %d) number of buys: %d\n", currentPlayer, G.numBuys);

    //set testcardQuant = current hand count prior to test
    testCardQuant = G.handCount[currentPlayer];
    //set testNumBuys = current player's number of buys prior to test
    testNumBuys = G.numBuys;

    councilRoomCard(currentPlayer, &G, handPos);

    printf ("****TESTING councilRoomCard() for handCount + 4:\n"); 
    printf ("Current player's (player %d) card quantity: %d, expected: %d\n\n", currentPlayer, G.handCount[currentPlayer], testCardQuant + 4);
    printf ("****TESTING councilRoomCard() for numBuys + 1:\n");     
    printf ("Current player's (player %d) number of buys: %d, expected: %d\n", currentPlayer, G.numBuys, testNumBuys + 1);

    return 0;
}
