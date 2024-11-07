#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


/** @brief finds and returns the first empty space in the LatinSquare
 * 
 * @param int Pointer to the latinSquare
 * @param int The size of the array
 * 
 * @return The position of the empty slot
 */
int findEmptySlot(int **,int);

/** @brief checks if any 0's are left
 * 
 * True; no 0's where found
 * False; atleast one 0 was found
 * 
 * @param int Pointer to the LatinSquare.
 * @param int Size of the 2d array.
 */
bool isSolved(int **,int);

/**
 * @brief checks if a number can be placed at the specified position in the Latin square
 * 
 * This function verifies whether placing a number at the specified position violates
 * the rules of the Latin square
 * 
 * @param latinSquare Pointer to a 2D array representing the Latin square
 * @param size Size of the Latin square
 * @param value Number to be checked
 * @param position Where the number is to be placed
 * 
 * @return true Number can be placed at the specified position without violating any rules
 * @return false Number at the specified position violates a rule
 */
bool checkMove(int **latinSquare, int size, int value, int position);

/**
 * @brief inserts a number at a specific position in the Latin square
 * 
 * This function places a number at a specific position in the array representing the Latin square
 * 
 * @param latinSquare Double pointer to the 2D array representing the Latin square
 * @param size The size of the Latin square
 * @param position Where the number will be placed
 * @param value Number to place at the specified position
 */
void insertNumber(int ***latinSquare, int size, int position, int value);

