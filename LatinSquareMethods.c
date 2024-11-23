/** @file latinsquare.c
 *  @brief Latin Square operations.
 *
 * This file implements the functions declared in LatinSquareMethods.h.
 *
 *  @author Antonios Kalattas
 *  @author Alexandros Georgiou
 */
#include "LatinSquareMethods.h"

int findEmptySlot(int **latinSquare,int size){
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            if(latinSquare[i][j]==0)
                return size*i + j;
    return -1;
}

bool isSolved(int **latinSquare,int size){
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            if(latinSquare[i][j]==0)
                return false;
    return true;
}

bool checkMove(int **latinSquare,int size,int value,int position){
    int x=(position)%size;
    int y =(position)/size;
    // checks row
    for(int i=0;i<size;i++)
        if(abs(latinSquare[y][i])==value)
            return false;
    // checks column
    for(int i=0;i<size;i++)
        if(abs(latinSquare[i][x])==value)
            return false;
    return true;
}

void insertNumber(int ***latinSquare,int size,int position,int value) {
    int row =(position)/size;
    int col =(position)%size;
    (*latinSquare)[row][col]=value;
}

#ifdef DEBUG
int main(){
    int size=3;
    int **latinSquare=(int **)malloc(size*sizeof(int *));   // initializes a sample Latin square with some empty slots (0 represents empty)
    for(int i=0;i<size;i++){
        latinSquare[i]=(int *)malloc(size*sizeof(int));
        for(int j=0;j<size;j++)
            latinSquare[i][j]=(i+j)%size+1;
    }

    latinSquare[0][0]=0;                                    // makes the first slot to be 0, to check the findEmpty.

    printf("Initial Latin Square:\n");
    int emptySlot=findEmptySlot(latinSquare,size);          // tests findEmptySlot
    if (emptySlot!=-1)
        printf("First empty slot found at position: %d (row%d,column %d)\n",emptySlot,emptySlot/size,emptySlot%size);
    else
        printf("No empty slot found.\n");
    bool solved=isSolved(latinSquare, size);                // tests isSolved
    printf("Is the Latin square solved? %s\n",solved?"Yes":"No");
    int testValue=2;                                        // tests checkMove
    bool moveValid = checkMove(latinSquare, size, testValue, emptySlot);
    printf("Is it valid to insert %d at position %d? %s\n",testValue,emptySlot,moveValid?"Yes":"No");
    if(moveValid){                                          // tests insertNumber
        printf("Inserting %d at position %d\n",testValue,emptySlot);
        insertNumber(&latinSquare,size,emptySlot,testValue);
    } 
    else
        printf("Invalid move. Cannot insert %d at position %d.\n",testValue,emptySlot);
    for(int i=0;i<size;i++)                                 // cleans up allocated memory
        free(latinSquare[i]);
    free(latinSquare);
    return 0;
}
#endif
