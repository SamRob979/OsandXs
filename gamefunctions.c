#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "boardfunctions.h"
#include "gamefunctions.h"

/* gamefunctions contains the functions necessary for getting user input
 * and dealing with things not directy related to the board such as deciding
 * which player begins and looping until the game is over.
 * 
 * Author: Sam Robinson
 */


/* Returns the move space that a player has indicated, valid moves consist
 * of integers 1 - 9, representing the nine square of the gameboard.
 * 
 * Inputs:
 * - turn: character indicating which player currently has their turn
 * 
 * Outputs:
 * - move: an integer (1 - 9) indicating which space the player wants to play to
 */

int getMove(char turn)
{
    int move = 0;
    
    // If player enters an invalid move, ask again until valid input is recieved
    while ((move < 1) || (move > 9)) {
        printf("Enter a board position (1 - 9, %c): ", turn);
        scanf("%d", &move);
    }
    
    return move;
}


/* Uses pseudorandom number generation to decide which player moves first to keep
 * multiple games fair. The random number seed is based on the system time so it 
 * changes with every execution of the program to ensure unpredictability.
 * 
 * Inputs:
 * - N/A
 * 
 * Outputs:
 * - randNum: a random boolean number that dictates which player moves first
 */

int decideFirstPlayer()
{
    // Set seed for pseudorandom number generation based on systen time
    srand(time(NULL));
    
    // Use modulo to return only 0 or 1
    int randNum = rand() % 2;
    
    return randNum;
}


/* Contains the main loop needed to set up and run the program, along with
 * interactive messages based on the board state. runGame calls many of the
 * other functions and forms the core of the program.
 * 
 * Inputs:
 * - N/A
 * 
 * Outputs:
 * - N/A
 */

void runGame()
{
    // Define and set up gameboard
    char Board[NUM_ROWS][NUM_COLS];
    initialiseBoard(Board);
    
    // playerTurn is the current player's character
    char playerTurn;
    
    // Count is an incrementing variable used to alternate between players
    int count = decideFirstPlayer();
    
    // Clear the console and display which player will start
    system("clear");
    printf("%c will start!", 'X' - (count % 2) * ('X' - 'O'));
    
    
    // Loop to keep executing until either a player has won or a draw is reached
    do {
        // Print spacer and board
        printf("\n");
        printBoard(Board);
        
        // Calculate which player should go next based on current player
        playerTurn = 'X' - (count % 2) * ('X' - 'O');
        count++;
        
        // Make the required move and clear the screen ready for the next player
        makeMove(Board, getMove(playerTurn), playerTurn);
        system("clear");
        
    } while (!hasWon(Board) && !hasDrawn(Board));
    
    // Print the final board state (win or draw)
    printf("\n");
    printBoard(Board);
    
    // Display closing message depending on what condition was reached
    if (hasDrawn(Board)) {
        printf("It's a draw!\n");
    } else {
        printf("%c has won!\n", playerTurn);
    }
}
