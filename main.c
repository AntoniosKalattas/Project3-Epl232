#include "readLatin.h"
#include "LatinSquareMethods.h"
#include "stack.h"
#include  <time.h>

void solveLatinSquare(Node *node, int size, Stack *stack);

int main(int argc, char * argv[]){
    if(argc==1){                                        // if given file is null.
        perror("Please give a file name.");
        return EXIT_FAILURE;
    }
    int **latinSquare=NULL;                             // 2d array to store the puzzle.
    int size = readLatinSquare(&latinSquare, argv[1]);  // size variable.
    Stack *stack = (Stack *)malloc(sizeof(Stack));      // create a stack, used for backtracking.
    initStack(stack);                                   // initiallise the stack.

    push(stack,latinSquare,size,0,0);                        // push the very first state of the latin square.


    solveLatinSquare(stack->top, size, stack);
}

void solveLatinSquare(Node *node, int size, Stack *stack){
    static int step=1;
    //base case
    if(isSolved(node->square, size))
        return;
    
    int position = findEmptySlot(node->square,size); // position that we can enter a number.
    bool found=false;
    for(int number=1;number<=size;number++){
        if(checkMove(node->square,size,number,position)){   // cehck if the random number can be placed there.
            found=true;
            int row =(position)%size;                       
            int col =(position)/size;
            insertNumber(&node->square,size,position,number);   // insert the number in the latinSquare.
            push(stack,node->square,size,row,col);              // push the new state of the latinSquare.
            printf("PUSH: STEP %d\n", step);                    //
            printLatinSquare(&node->square,size);               // prints the state of the latin Square.
            int lengthOfStack = stack->length;                  // get the new lengt of the stack.
            step++;
            solveLatinSquare(stack->top,size,stack);            // recursive call.                                        
            if(isSolved(stack->top->square, size))              // if the recursive call back is because the puzzle is solved.
                return;
            
            else{
                found=false;
                pop(stack);
                printf("POP: STEP %d\n", step);
                printLatinSquare(&stack->top->square,size);
                step++;
            }
        }
    }
    if(!found){
        return;
    }
}