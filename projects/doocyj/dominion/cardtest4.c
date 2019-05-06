/* -----------------------------------------------------------------------
 *Card Test 4
 *Tests steward card effect from dominion.c for correct quantity of cards
 *After steward is called with choice1 = 1, +2 cards
 *After steward is called with choice1 = 2, +2 coins
 *After steward is called with choice1 = 3, -2 cards
 *When discarding, choice 2 and 3 choose the discard
 *Include the following lines in your makefile:
 *cardtest4: cardtest4.c dominion.o rngs.o
 *  gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
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
    printf ("****Testing Steward card\n");
    printf ("Current player's (player %d) card quantity: %d\n", currentPlayer, G.handCount[currentPlayer]);

    //set testcardQuant = current hand count prior to test
    testCardQuant = G.handCount[currentPlayer];

    choice1 = 1;
    cardEffect(steward, choice1, choice2, choice3, &G, handPos, bonus);

    printf ("****Steward card ran with +2 cards:\n");    
    printf ("Current player's (player %d) card quantity: %d, expected: %d\n", currentPlayer, G.handCount[currentPlayer], testCardQuant + 2 - 1);


    printf ("\nCurrent player's (player %d) card quantity: %d\n", currentPlayer, G.handCount[currentPlayer]);
    //set testcardQuant = current hand count prior to test again
    testCardQuant = G.handCount[currentPlayer];
    choice1 = 2;
    cardEffect(steward, choice1, choice2, choice3, &G, handPos, bonus);
    printf ("****Steward card ran with +2 coins:\n");    
    printf ("Current player's (player %d) card quantity: %d, expected: %d\n", currentPlayer, G.handCount[currentPlayer], testCardQuant + 2 - 1);
    
    printf ("\nCurrent player's (player %d) card quantity: %d\n", currentPlayer, G.handCount[currentPlayer]);
    //set testcardQuant = current hand count prior to test again
    testCardQuant = G.handCount[currentPlayer];
    choice1 = 3;
    choice2 = G.hand[currentPlayer][0];
    choice3 = G.hand[currentPlayer][1];
    cardEffect(steward, choice1, choice2, choice3, &G, handPos, bonus);
    printf ("****Steward card ran with -2 cards:\n");    
    printf ("Current player's (player %d) card quantity: %d, expected: %d\n", currentPlayer, G.handCount[currentPlayer], testCardQuant - 2 - 1);

    return 0;
}
