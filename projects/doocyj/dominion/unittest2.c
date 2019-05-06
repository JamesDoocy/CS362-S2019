/* -----------------------------------------------------------------------
 * Unit Test 2
 *Tests mineCard() function from dominion.c for card count
 *After mineCard() is called, the current player should have the same number of cards

 * Include the following lines in your makefile:
 * unittest2: unittest2.c dominion.o rngs.o
 *     gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
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
    int init_pass = -1;
    int numPlayer = 2;
    int handPos = 0;
    int seed = 1000;
    int currentPlayer = 0;
    int choice1; 
    int choice2 = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    init_pass = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    if (asserttrue(init_pass, 1)){
        printf ("initializeGame() failed. Exiting...\n"); 
        return 0;  
    }
  
    /* */
    /*test that the number of cards in the hand doesn't change, since the lesser treasure should get trashed*/
    printf("Testing minecard()\n");
    printf ("Current player's (player %d) pre-test card quantity: %d\n", currentPlayer, G.handCount[currentPlayer]);
    testCardQuant = G.handCount[currentPlayer];
    choice1 = copper;

    mineCard(&G, currentPlayer, choice1, choice2, handPos);
    printf ("Current player's (player %d) card quantity: %d, expected: %d\n\n", currentPlayer, numHandCards(&G), testCardQuant);

    return 0;
}
