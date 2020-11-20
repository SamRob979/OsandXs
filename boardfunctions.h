#ifndef BOARDFUNCTIONS
#define BOARDFUNCTIONS

#define NUM_ROWS 3
#define NUM_COLS 3

void initialiseBoard(char gameBoard[NUM_ROWS][NUM_COLS]);

void printBoard(char gameBoard[NUM_ROWS][NUM_COLS]);

void makeMove(char gameBoard[NUM_ROWS][NUM_COLS], int pos, char player);

int hasWon(char gameBoard[NUM_ROWS][NUM_COLS]);

int hasDrawn(char gameBoard[NUM_ROWS][NUM_COLS]);

#endif
