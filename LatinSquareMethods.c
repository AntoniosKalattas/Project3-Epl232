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

#ifdef DEBUG
int main(){
    int size=3;
    int **latinSquare=(int **)malloc(size*sizeof(int *));   // Initialize a sample Latin square with some empty slots (0 represents empty)
    for(int i=0;i<size;i++){
        latinSquare[i]=(int *)malloc(size*sizeof(int));
        for(int j=0;j<size;j++)
            latinSquare[i][j]=(i+j)%size+1;
    }
    printf("Initial Latin Square:\n");
    printLatinSquare(latinSquare,size);
    int emptySlot=findEmptySlot(latinSquare,size);       // Test findEmptySlot
    if (emptySlot!=-1)
        printf("First empty slot found at position: %d (row %d, column %d)\n",emptySlot,emptySlot/size,emptySlot%size);
    else
        printf("No empty slot found.\n");
    bool solved = isSolved(latinSquare, size);              // Test isSolved
    printf("Is the Latin square solved? %s\n",solved?"Yes":"No");
    int testValue = 2;                                      // Test checkMove
    bool moveValid = checkMove(latinSquare, size, testValue, emptySlot);
    printf("Is it valid to insert %d at position %d? %s\n",testValue,emptySlot,moveValid?"Yes":"No");
    if(moveValid){                                        // Test insertNumber
        printf("Inserting %d at position %d\n",testValue,emptySlot);
        insertNumber(&latinSquare,size,emptySlot,testValue);
        printLatinSquare(latinSquare,size);
    } 
    else
        printf("Invalid move. Cannot insert %d at position %d.\n",testValue,emptySlot);
    for(int i=0;i<size;i++)                        // Clean up allocated memory
        free(latinSquare[i]);
    free(latinSquare);
    return 0;
}
#endif