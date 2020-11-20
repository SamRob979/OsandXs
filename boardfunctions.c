#include <stdio.h>

#include "boardfunctions.h"

/* boardfunctions contains the functions necessary for interacting with the
 * gameboard. The gameboard is represented by a 3x3 2D character array with
 * information about what moves each player has made. 'X' - moves made by the
 * crosses player, 'O' - moves made by the noughtes player, ' ' - unoccupied
 * spaces.
 * 
 * Author: Sam Robinson
 */


/* Sets up the gameboard as a 3x3 2D character array of empty spaces, ready
 * to be used for moves. Can generate boards of any size if NUM_ROWS and
 * NUM_COLS are adjusted.
 * 
 * Inputs:
 * - gameBoard[][]: the empty array to be initialised
 * 
 * Outputs:
 * - N/A
 */

void initialiseBoard(char gameBoard[NUM_ROWS][NUM_COLS])
{
    // Nested loops to cycle through array values
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            // Fills every index in the array with a space character
            gameBoard[i][j] = ' ';
        }
    }
}


/* Prints the current state of the gameboard to the console using primative
 * ascii graphics. Although the board looks incorrecly formatted, when printed
 * to the console the alignment is correct.
 * 
 * Inputs:
 * - gameBoard[][]: the board array to be printed to the screen
 * 
 * Outputs:
 * - N/A
 */

void printBoard(char gameBoard[NUM_ROWS][NUM_COLS])
{
    // Inserts whatever charcter is a particular square to the right position
    printf(
    " -----1----- -----2----- -----3----- \n"
    "|           |           |           |\n"
    "|           |           |           |\n"
    "|     %c     |     %c     |     %c     |\n"
    "|           |           |           |\n"
    "|           |           |           |\n"
    " -----4----- -----5----- -----6----- \n"
    "|           |           |           |\n"
    "|           |           |           |\n"
    "|     %c     |     %c     |     %c     |\n"
    "|           |           |           |\n"
    "|           |           |           |\n"
    " -----7----- -----8----- -----9----- \n"
    "|           |           |           |\n"
    "|           |           |           |\n"
    "|     %c     |     %c     |     %c     |\n"
    "|           |           |           |\n"
    "|           |           |           |\n"
    " ----------- ----------- ----------- \n", 
    gameBoard[0][0], gameBoard[0][1], gameBoard[0][2],
    gameBoard[1][0], gameBoard[1][1], gameBoard[1][2],
    gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
}


/* Assigns characters to the gameboard on a specific square based on which
 * player made the move. The move in only assigned if the space is empty.
 * 
 * Inputs:
 * - gameBoard[][]: the gameboard that will be modified
 * - pos: the linear index of the move position
 * - player: a character representing which player made the move
 * 
 * Outputs:
 * - N/A
 */

void makeMove(char gameBoard[NUM_ROWS][NUM_COLS], int pos, char player)
{
    // Convert the linear index used in the UI to a 2D array index
    int row = (pos - 1) / NUM_ROWS;
    int col = (pos - 1) % NUM_COLS;
    
    // Only make the move if the position is free
    if (gameBoard[row][col] == ' ') {
        gameBoard[row][col] = player;
    }
}


/* Returns a boolean indicating whether or not a player has won (got
 * three of their character in a row). 0 = no player has won yet,
 * 1 = one of the players has won.
 * 
 * Inputs:
 * - gameBoard[][]: the gameboard that will be checked for the win condition
 * 
 * Ouputs:
 * - hasWon: a boolean represented if a player has won the game or not
 */

int hasWon(char gameBoard[NUM_ROWS][NUM_COLS])
{
    int hasWon = 0;
    
    // Check each row for win condition
    for (int i = 0; i < NUM_ROWS; i++) {
        if ((gameBoard[i][0] == gameBoard[i][1]) && (gameBoard[i][0] == gameBoard[i][2]) && (gameBoard[i][0] != ' ')) {
            hasWon = 1;
        }
    }
    
    // Check each column for win condition
    for (int i = 0; i < NUM_COLS; i++) {
        if ((gameBoard[0][i] == gameBoard[1][i]) && (gameBoard[0][i] == gameBoard[2][i]) && (gameBoard[0][i] != ' ')) {
            hasWon = 1;
        }
    }
    
    // Check top-left to bottom-right diagonal for win condition
    if ((gameBoard[0][0] == gameBoard[1][1]) && (gameBoard[0][0] == gameBoard[2][2]) && (gameBoard[1][1] != ' ')) {
        hasWon = 1;
    }
    
    // Check botton-left to top-right diagonal for win condition
    if ((gameBoard[0][2] == gameBoard[1][1]) && (gameBoard[0][2] == gameBoard[2][0]) && (gameBoard[1][1] != ' ')) {
        hasWon = 1;
    }
    
    return hasWon;
}


/* Similar to hasWon, returns a boolean indicating if the game has ended in a
 * draw (board is full but no three-in-a-row). 0 = game has not ended in a draw, 
 * 1 = game has ended in a draw.
 * 
 * Inputs:
 * - gameBoard[][]: the gameboard that will be checked for the draw condition
 * 
 * Outputs:
 * - hasDrawn: a boolean indicating whether a draw has been reached
 */

int hasDrawn(char gameBoard[NUM_ROWS][NUM_COLS])
{
    // Count represents the number of occupied spaces currently on the board
    int count = 0;
    
    // Nested loops to determine how many occupied spaces are currently on the board
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            // If a space in not empty, count will be incremented
            if (gameBoard[i][j] != ' ') {
                count++;
            }
        }
    }
    
    // If the number of occupied spaces is equal to the total spaces, the board is full
    return count == NUM_ROWS * NUM_COLS;
}
