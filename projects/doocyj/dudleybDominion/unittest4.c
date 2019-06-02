/* -----------------------------------------------------------------------
 *Unit Test 4
 *Tests smithyCard() function from dominion.c for correct quantity of drawn cards
 *After smithyCard() is called, current hand should have 3 more cards

 *Include the following lines in your makefile:
 *unittest4: unittest4.c dominion.o rngs.o
 *	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
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
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    init_pass = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    if (asserttrue(init_pass, 1)){
        printf ("initializeGame() failed. Exiting...\n"); 
        return 0;  
    }
  
    printf ("Current player's (player %d) card quantity: %d\n", currentPlayer, G.handCount[currentPlayer]);

    //set testcardQuant = current hand count prior to test
    testCardQuant = G.handCount[currentPlayer];

    smithyRefactor(&G, currentPlayer, handPos);

    printf ("****TESTING smithyCard() for handCount + 2:\n"); 
    printf ("Current player's (player %d) card quantity: %d, expected: %d\n\n", currentPlayer, G.handCount[currentPlayer], testCardQuant + 2);


    return 0;
}
