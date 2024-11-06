#include <stdio.h>

void printBoard(int **board, int n) {
    // prints top border
    for (int i = 0; i < n; i++) {
        printf("+-----");
    }
    printf("+\n");
    // prints each row with borders
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // print each element with alignment
            printf("| %3d ", board[row][col]);
        }
        printf("|\n");
        // prints row separator
        for (int i = 0; i < n; i++) {
            printf("+-----");
        }
        printf("+\n");
    }
}