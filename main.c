#include "readLatin.h"
#include "LatinSquareMethods.h"
#include  <time.h>

int main(int argc, char * argv[]){
    if(argc==1){                                        // if given file is null.
        perror("Please give a file name.");
        return EXIT_FAILURE;
    }
    int **latinSquare=NULL;                              // 2d array to store the puzzle.
    int size = readLatinSquare(&latinSquare, argv[1]);   // size variable.
    //printLatinSquare(&latinSquare,size);
    srand(time(NULL));                                  // seed the generator with the time.
    while(!isSolved(latinSquare, size)){                // loop until there are no 0's left.                             
        int randomNumber = 1+rand()%(size*size);                   // generate a rundom number.
        int position = findEmptySlot(latinSquare,size); // position that we can enter a number.
        if(checkMove(latinSquare,size,randomNumber,position)){   // cehck if the random number can be placed there.
            insertNumber(&latinSquare,size,position,randomNumber);     // insert the number in the latinSquare.
        }
    }
    printLatinSquare(&latinSquare,size);
}