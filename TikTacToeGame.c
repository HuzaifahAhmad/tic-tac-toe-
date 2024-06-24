#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>



// prints the board
void printBoardGrid(char boardGrid[3][3]) {
    for (int i = 0; i < 3 ; i++) {
        for (int j = 0; j < 3; j++) {
            if (j < 2) {
                printf("%c\t|\t", boardGrid[i][j]);
            } else {
                printf("%c\t", boardGrid[i][j]);
            }
        }
        if (i >= 2) {
            
        }  else if (i <= 1)
        printf("\n-----------------------------------");
        printf("\n");
    }
}


// computer places 0 on board
void computerTurn(char boardGrid[3][3]) {
    srand(time(NULL));

    while (1) {
        int computerRow = rand() % 3;
        int computerColumn = rand() % 3;
        int countGrid = 0;


        // if == " ", place then break
        if (boardGrid[computerRow][computerColumn] != 'X' && boardGrid[computerRow][computerColumn] != 'O') {
            boardGrid[computerRow][computerColumn] = 'O';
            break;
        }
            // if == X or O, new numbers, do again
        else if (boardGrid[computerRow][computerColumn] == 'X' || boardGrid[computerRow][computerColumn] == 'O') {
            for (int i = 0; i < 3 ; i++) {
                for (int j = 0; j < 3; j++) {
                    if (boardGrid[i][j] == 'X' || boardGrid[i][j] == 'O') {
                        countGrid += 1;
                    } 
                }
            }

            if (countGrid == 9) {
                break;
            } else {
                continue;
            }
        } 

        
    }
}

int takeRowInputFromUser () {
    int row;
    char newline;
    while (1) {
        printf("Enter row number (1-3): ");

        // attempt to read an integer
        if (scanf("%d%c", &row, &newline) != 2 || newline != '\n') {
            printf("Invalid input. Please enter a number\n");
            // clear input buffer
            while (getchar() != '\n');   
        } else {
            // check if row is within the valid range
            if (row >= 1 && row <= 3) {
                break; // valid row number, exit the loop
            } else {
                printf("Enter valid row number (1-3)\n");
            }
        }
    }
    return row;
}

int takeColumnInputFromUser () {
    int column;
    char newline;
    while (1) {
        printf("Enter column number (1-3): ");

        // attempt to read an integer
        if (scanf("%d%c", &column, &newline) != 2 || newline != '\n') {
            printf("Invalid input. Please enter a number\n");
            // clear input buffer
            while (getchar() != '\n'); 
        } else {
            // check if column is within the valid range
            if (column >= 1 && column <= 3) {
                break; // valid column number, exit the loop
            } else {
                printf("Enter valid column number (1-3)\n");
            }
        }
    }
    return column;
}

// turn string to lower case
void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// prints win message
void printWinMessage(bool *shouldBreak) {
    *shouldBreak = true;  
}

void printComputerWinMessage(bool *shouldBreak) {
    printf("YOU LOST! COMPUTER WON! Thanks for playing\n");
    *shouldBreak = true;      
}

// checks for win
void checkHumanWin(char boardGrid[3][3], bool *shouldBreak) {

    // check for human horizontal win
    if (
        (boardGrid [0][0] == 'X' && boardGrid [0][1] == 'X' && boardGrid [0][2] == 'X') ||
        (boardGrid [1][0] == 'X' && boardGrid [1][1] == 'X' && boardGrid [1][2] == 'X') ||
        (boardGrid [2][0] == 'X' && boardGrid [2][1] == 'X' && boardGrid [2][2] == 'X')
        ) {
        printWinMessage(shouldBreak);
    }

    // check for human vertical win
    else if ((boardGrid [0][0] == 'X' && boardGrid [1][0] == 'X' && boardGrid [2][0] == 'X') ||
             (boardGrid [0][1] == 'X' && boardGrid [1][1] == 'X' && boardGrid [2][1] == 'X') || 
             (boardGrid [0][2] == 'X' && boardGrid [1][2] == 'X' && boardGrid [2][2] == 'X')) {
        printWinMessage(shouldBreak);
    } 
    // check for human diagonal win
    else if ((boardGrid [0][0] == 'X' && boardGrid [1][1] == 'X' && boardGrid [2][2] == 'X') || 
             (boardGrid [0][2] == 'X' && boardGrid [1][1] == 'X' && boardGrid [2][0] == 'X')) {
        printWinMessage(shouldBreak);
    }

}

void checkComputerWin(char boardGrid[3][3], bool *shouldBreak) {
    // check for computer horizontal win
    if ((boardGrid [0][0] == 'O' && boardGrid [0][1] == 'O' && boardGrid [0][2] == 'O') || 
        (boardGrid [1][0] == 'O' && boardGrid [1][1] == 'O' && boardGrid [1][2] == 'O') || 
        (boardGrid [2][0] == 'O' && boardGrid [2][1] == 'O' && boardGrid [2][2] == 'O')) {
        printComputerWinMessage(shouldBreak);
    } 
    // check for computer vertical win
    else if ((boardGrid [0][0] == 'O' && boardGrid [1][0] == 'O' && boardGrid [2][0] == 'O') || 
             (boardGrid [0][1] == 'O' && boardGrid [1][1] == 'O' && boardGrid [2][1] == 'O') || 
             (boardGrid [0][2] == 'O' && boardGrid [1][2] == 'O' && boardGrid [2][2] == 'O')) {
        printComputerWinMessage(shouldBreak);
    } 

    // check for computer diagonal win
    else if ((boardGrid [0][0] == 'O' && boardGrid [1][1] == 'O' && boardGrid [2][2] == 'O') || 
             (boardGrid [0][2] == 'O' && boardGrid [1][1] == 'O' && boardGrid [2][0] == 'O')) {
        printComputerWinMessage(shouldBreak);
    } 
}

// check for draw
void checkDraw(char boardGrid[3][3]) {
    int countGrid = 0;

    for (int i = 0; i < 3 ; i++) {
        for (int j = 0; j < 3; j++) {
            if (boardGrid[i][j] == 'X' || boardGrid[i][j] == 'O') {
                countGrid += 1;
            } 
        }
    }
    if (countGrid == 9) {
        printf("DRAW!! Try again!\n");
    }
}
 

int main() {
            char wouldYouLikeToPlayGame[50];


            printf ("**********************\n");
            printf ("WECLOME TO TIC TAC TOE\n");
            printf ("**********************\n");

            printf("Would you like to play a round? (Yes/No): ");


            while (1) 
            {
            fgets(wouldYouLikeToPlayGame, sizeof(wouldYouLikeToPlayGame), stdin);
            // remove the newline character if there
            wouldYouLikeToPlayGame[strcspn(wouldYouLikeToPlayGame, "\n")] = 0;

            toLowerCase(wouldYouLikeToPlayGame);

                if (strcmp(wouldYouLikeToPlayGame, "yes") == 0){
                    
                    char grid[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
                    int row;
                    int column;
                    printf("-----------------------\n");
                    printf("Do the first turn\n");
                    printf("------------------------\n");
                    printf("\n");

                    printBoardGrid(grid);
                    printf("\n");

                    bool shouldBreak = false;

                    //placing X on grid
                    for (int i = 0; i < 5; i++) {
                        if (shouldBreak) {
                            break;
                        }
                        

                        while (!shouldBreak) {
                            row = takeRowInputFromUser();
                            column = takeColumnInputFromUser();
                            // check if space already == X or O
                            if (grid[row-1][column-1] == 'X' ||  grid[row-1][column-1] == 'O') {
                                printf("Space already taken, pick another space\n");
                                continue;
                            } else {
                                break;
                            }
                        }

                        grid[row-1][column-1] = 'X';

                        checkHumanWin(grid, &shouldBreak);
                        if (shouldBreak) {
                            printBoardGrid(grid);
                            printf("\n");
                            printf("YOU WON! Game finished! Thanks for playing\n");
                            break;
                        }

                        computerTurn(grid);
                        printBoardGrid(grid);
                        printf("\n");

                        checkComputerWin(grid, &shouldBreak);
                        if (shouldBreak) {                   
                            break;
                        }

                        if (i == 4) {
                            checkDraw(grid);
                        }

                    }

                    printf("Would You like to play another round? (Yes/No): ");

                } 
                else if (strcmp(wouldYouLikeToPlayGame, "no") == 0 ) {
                    break;
                }
                else {
                    printf("Invalid Input. Enter (Yes/No): ");
                }

            };


    printf("GAME ENDED! Thanks for playing!\n");

    return 0;
}
