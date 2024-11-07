#include "readLatin.h"

int readLatinSquare(int ***LatinSquare, char *fileName){
    FILE *fp;                           // creates the file pointer
    fp = fopen(fileName,"r");

    if(fp==NULL){                       // failed to open file
        printf("Faild to open file.");
        return EXIT_FAILURE;
    }
    int size;                           // reads the first line on the .txt file, sets it as the size value
    if (fscanf(fp,"%d",&size)!=1){      // tries to read the first integer
        printf("File is empty.\n");
        fclose(fp);
        return EXIT_FAILURE;
    }
    if(size<2){
        perror("Wrong size. Should be >=2");
        return EXIT_FAILURE;
    }
    
    *LatinSquare=(int **)malloc(size*sizeof(int *));

    for(int i=0;i<size;i++)            // allocate spaces for the 2d dynamic array
        (*LatinSquare)[i]=(int *)malloc(size*sizeof(int *));

    for(int i=0;i<size;i++)            // reads the 2d array from the file
        for(int j=0;j<size;j++){
            fscanf(fp, "%d", &(*LatinSquare)[i][j]);
        }
    fclose(fp);                         // closes the file
    return size;                        // returns the size
}
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
    // IMPORTANT!!! Create a latin_square.txt file, where you will store a latinSquare.  IMPORTANT!!!!!!!
    int **latinSquare;                                  // Pointer for 2D Latin square.
    char *fileName ="latin_square.txt";                 // Name of debug file to read from.

    FILE *fp=NULL;                                      //  
    fp = fopen(fileName, "r");                          // 
    if(!fp){
        perror("No latin_square.txt can be found. Please create and re-run the debug.");
        return EXIT_FAILURE;
    }
    int size =readLatinSquare(&latinSquare, fileName);  // Read the Latin from file
    if(size<2){                             // if the size is 1.
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
