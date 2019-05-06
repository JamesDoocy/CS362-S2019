/* -----------------------------------------------------------------------
 *Card Test 3
 *Tests great_hall card effect from dominion.c for correct quantity of cards and actions
 *After great_hall is called, current hand should have same number of cards and one more action
 *Include the following lines in your makefile:
 *cardtest3: cardtest3.c dominion.o rngs.o
 *  gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
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
    int testNumActions = 0;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int* bonus = 0;
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
    printf ("****Testing Great Hall card\n");
    printf ("Current player's (player %d) card quantity: %d\n", currentPlayer, G.handCount[currentPlayer]);
    printf ("Current player's (player %d) number of actions: %d\n", currentPlayer, G.numActions);

    //set testcardQuant = current hand count prior to test
    testCardQuant = G.handCount[currentPlayer];
    //set test NumActions = current player num actions prior to test
    testNumActions = G.numActions;

    cardEffect(great_hall, choice1, choice2, choice3, &G, handPos, bonus);

    printf ("****Great Hall card ran:\n");    
    printf ("Current player's (player %d) card quantity: %d, expected: %d\n", currentPlayer, G.handCount[currentPlayer], testCardQuant + 1);
    printf ("Current player's (player %d) number of actions: %d, expected %d\n", currentPlayer, G.numActions, testNumActions + 1);
    return 0;
}
