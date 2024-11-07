#include "LatinSquareMethods.h"

/** @brief Finds and return the first empty space in the LatinSquare
 * 
 * @param int Pointer to the latinSquare.
 * @param int The size of the array.
 * 
 * @return The position of the empty slot.
 */
int findEmptySlot(int **latinSquare, int size){
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            if(latinSquare[i][j]==0)
                return size*i + j;
    return -1;
}

/** @brief Checks if there is any 0's left.
 * 
 * True is no 0's can be found.
 * False if there is atleast one 0.
 * 
 * @param int Pointer to the LatinSquare.
 * @param int Size of the 2d array.
 */
bool isSolved(int **latinSquare, int size){
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            if(latinSquare[i][j]==0){
                return false;
            }
    return true;
}

/** @brief Checks if there is the same element in the same row or column
 * 
 * @param int Pointer to latisSquare.
 * @param int Size.
 * @param int Input value.
 * @param int position,.
 */
bool checkMove(int **latinSquare, int size, int value, int position){
    int x=(position)%size;
    int y =(position)/size;
    // Check row
    for(int i=0;i<size;i++)
        if(abs(latinSquare[y][i])==value)
            return false;
    // Check column
    for(int i=0;i<size;i++)
        if(abs(latinSquare[i][x])==value)
            return false;
    return true;
}

/** @brief Inserts a number in the given position in the LatinSquare.
 * 
 * @param int Pointer to the 2d LatinSquare.
 * @param int Position.
 * @param int value.
 */
void insertNumber(int ***latinSquare, int size, int position, int value) {
    int row = (position) / size;
    int col = (position) % size;
    (*latinSquare)[row][col] = value;
}
