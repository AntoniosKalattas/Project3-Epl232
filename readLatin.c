#include "readLatin.h"

void readLatinSquare(int **LatinSquare, char *filename){
    //create the file pointer.
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp==NULL){                       // if faild to open file.
        printf("Faild to open file.");
    }
    int columns;
    fscanf(fp,"%d g\n", &columns);
    printf("%d \n", columns);

    LatinSquare = (int **)malloc(columns *sizeof(int*));

    for(int i=0;i<columns;i++){
        LatinSquare[i]= (int *)calloc(0,columns * sizeof(int));
    }
    for(int i=0;i<columns;i++){
        for(int j=0;j<columns;j++){
            fscanf(fp,"%d",&LatinSquare[i][j]);
        }
    }

    for(int i=0;i<columns;i++){
        for(int j=0;j<columns;j++){
            printf(" %d ",LatinSquare[i][j]);
        }
        printf("\n");
    }
}