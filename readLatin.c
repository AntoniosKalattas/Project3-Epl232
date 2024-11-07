#include "readLatin.h"

/** @brief It will read the latin square from the given file
 * 
 * @param int Pointer to the LatinSquare 2d table
 * @param char Pointer to the .txt file
 *  
 * @return (int)The Size of the 1d array.
 */
int readLatinSquare(int ***LatinSquare, char *fileName){
    FILE *fp;                           //create the file pointer.
    fp = fopen(fileName,"r");
    if(fp==NULL){                       // if faild to open file.
        printf("Faild to open file.");
        return EXIT_FAILURE;
    }
    int size;                           // read the first line on the .txt file, set it as the size value.
    fscanf(fp,"%d \n", &size);

    *LatinSquare=(int **)malloc(size*sizeof(int *));

    for(int i=0;i<size;i++)            // Allocate space for the 2d dynamic array.
        (*LatinSquare)[i]=(int *)malloc(size*sizeof(int *));

    for(int i=0;i<size;i++)            // read the 2d array from the file.
        for(int j=0;j<size;j++){
            fscanf(fp, "%d", &(*LatinSquare)[i][j]);
            //(*LatinSquare)[i][j] *= -1;
        }
    fclose(fp);                         // close the file.
    return size;                        // return the size.
}

/** @brief It will print the latinSquare, used for debug perposes.
 * 
 * @param int Pointer to the LatinSquare 2d array.
 * @param int Size of the array.
 * 
 * @return void
 */
void printLatinSquare(int ***LatinSquare, int size){
    // prints top border
    for(int i=0;i<size;i++){
        printf("+-----");
    }
    printf("+\n");
    // prints each row with borders
    for(int row=0;row<size;row++) {
        for(int col=0;col<size;col++){
            // print each element with alignment
            if((*LatinSquare)[row][col]>=0)
                printf("| %2d  ", (*LatinSquare)[row][col]);
            else
                printf("| (%d) ", abs((*LatinSquare)[row][col]));
        }
        printf("|\n");
        // prints row separator
        for(int i=0;i<size;i++){
            printf("+-----");
        }
        printf("+\n");
    }
}