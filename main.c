#include "readLatin.h"

int main(int argc, char * argv[]){
    if(argc==1){
        perror("Please give a file name.");
        return EXIT_FAILURE;
    }
    int **latinSquare;
    readLatinSquare(latinSquare, argv[1]);

}