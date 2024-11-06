#include "readLatin.h"

int main(int argc, char * argv[]){
    if(argc==1){                                        // if given file is null.
        perror("Please give a file name.");
        return EXIT_FAILURE;
    }
    int **latinSquare;                                  // 2d array to store the puzzle.
    int size = readLatinSquare(latinSquare, argv[1]);   // size variable.
}