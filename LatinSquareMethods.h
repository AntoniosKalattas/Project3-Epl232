#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


/** @brief Finds and return the first empty space in the LatinSquare
 * 
 * @param int Pointer to the latinSquare.
 * @param int The size of the array.
 * 
 * @return The position of the empty slot.
 */
int findEmptySlot(int **,int);

/** @brief Checks if there is any 0's left.
 * 
 * True is no 0's can be found.
 * False if there is atleast one 0.
 * 
 * @param int Pointer to the LatinSquare.
 * @param int Size of the 2d array.
 */
bool isSolved(int **,int);

bool checkMove(int **,int,int,int);

void insertNumber(int ***latinSquare, int size, int position, int value);
