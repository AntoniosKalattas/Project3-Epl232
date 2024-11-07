#include "readLatin.h"

/** @brief Reads the latin square from the given file
 * 
 * @param int Pointer to the LatinSquare 2d table
 * @param char Pointer to the .txt file
 *  
 * @return (int)The Size of the 1d array.
 */
int readLatinSquare(int ***LatinSquare, char *fileName){
    FILE *fp;                           // creates the file pointer.
    fp = fopen(fileName,"r");
    if(fp==NULL){                       // if failed to open file.
        printf("Faild to open file.");
        return EXIT_FAILURE;
    }
    int size;                           // reads the first line on the .txt file, sets it as the size value.
    fscanf(fp,"%d \n", &size);

    *LatinSquare=(int **)malloc(size*sizeof(int *));

    for(int i=0;i<size;i++)            // allocate spaces for the 2d dynamic array.
        (*LatinSquare)[i]=(int *)malloc(size*sizeof(int *));

    for(int i=0;i<size;i++)            // reads the 2d array from the file.
        for(int j=0;j<size;j++){
            fscanf(fp, "%d", &(*LatinSquare)[i][j]);
        }
    fclose(fp);                         // closes the file.
    return size;                        // returns the size.
}

/** @brief It will print the latinSquare.
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
            // prints each element with alignment
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

#ifdef DEBUG
int main() {
    int **latinSquare;                                  // Pointer for 2D Latin square.
    char *fileName ="latin_square.txt";                 // Name of debug file to read from.
    int size =readLatinSquare(&latinSquare, fileName);  // Read the Latin from file
    if(size==EXIT_FAILURE){                             // if the size is 1.
        printf("Error reading the Latin square.\n");
        return EXIT_FAILURE;
    }
    printf("Latin Square of size %d:\n",size);          // Print the Latin square size.
    printLatinSquare(&latinSquare, size);               // Print the state of square.
    for (int i=0;i<size;i++)                            // Free the allocated memory for Latin square
        free(latinSquare[i]);
    free(latinSquare);
    return EXIT_SUCCESS;
}
#endif