/* -----------------------------------------------------------------------
 *Card Test 2
 *Tests adventurerCard() function from dominion.c for 
 *After adventurerCard() is called, current hand should 
 *Include the following lines in your makefile:
 *cardtest2: cardtest2.c dominion.o rngs.o
 *	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
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
    int seed = 1000;
    int currentPlayer = 0;
    int drawntreasure = 0;
    int cardDrawn = 0;
    int temphand[50];
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    init_pass = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    if (asserttrue(init_pass, 1)){
        printf ("initializeGame() failed. Exiting...\n"); 
        return 0;  
    }
    printf ("****TESTING adventurerCard() for handCount + 1:\n"); 
    printf ("Current player's (player %d) card quantity: %d\n", currentPlayer, G.handCount[currentPlayer]);

    //set testcardQuant = current hand count prior to test
    testCardQuant = G.handCount[currentPlayer];

    adventurerRefactor(&G, currentPlayer, 0);

    printf ("****TESTING adventurerCardCard() for handCount + 1:\n"); 
    printf ("Current player's (player %d) card quantity: %d, expected: %d\n\n", currentPlayer, G.handCount[currentPlayer], testCardQuant + 1);


    return 0;
}
