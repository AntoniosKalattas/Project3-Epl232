#include "readLatin.h"
#include "LatinSquareMethods.h"
#include "stack.h"
#include  <time.h>


/** @struct BackTrackingCounters
 * 
 * struct that keeps track, on the counters, such
 * as how many pushes, pops, and total steps
 */
typedef struct{
    int step;   
    int pushes;
    int pops;
}BackTrackingCounters;

/** @brief initializes the BackTrackingCounters with the default values
 * 
 * @param BackTrackingCounters Pointer to BackTrackingCounters
 * @return void
 */
void initBackTrackingCounters(BackTrackingCounters *counters);

/** @brief solves the given LatinSquare
 * 
 * Using recursion and backtracking it solves the latinSquare by moving
 * forward if the algorithm finds a number to place on the 
 * first empty slot. If it cannot, it backtracks to the previous empty slot
 * and tries to find a new value to assign there
 * 
 * @param Node Pointer current top node of the stack.
 * @param int The size of the latinSquare.
 * @param Stack Pointer to the stack.
 * @param BackTrackingCounters Pointer to the BackTrackingCounters.
 * 
 * @return void.
 */
void solveLatinSquare(Node *node, int size, Stack *stack, BackTrackingCounters *);

int main(int argc, char * argv[]){
    if(argc==1){                                        // file's null.
        perror("Please give a file name.");
        return EXIT_FAILURE;
    }
    int **latinSquare=NULL;                             // 2d array to store the first state puzzle

    int size = readLatinSquare(&latinSquare, argv[1]);  // size variable
    if(size==EXIT_FAILURE){
        return EXIT_FAILURE;
    }

    Stack *stack = (Stack *)malloc(sizeof(Stack));      // creates a stack, used for storing the states of the latinSquares
    if(stack==NULL){                                    // allocation fails
        printf("Faild to allocate space for stack.");
        return EXIT_FAILURE;
    }
    initStack(stack);                                   // initiallizes the stack

    push(stack,latinSquare,size,0,0);                   // pushes the very first state of the latin square
    BackTrackingCounters *counters =(BackTrackingCounters *)malloc(sizeof(BackTrackingCounters));   // allocates space for BackTrackingCounters
    if(counters==NULL){                                 // if allocation fails
        printf("Faild to allocate space for BackTrackingCounters.");
        return EXIT_FAILURE;
    }
    initBackTrackingCounters(counters);                 // initializes the BackTrackingCounters

    solveLatinSquare(stack->top, size, stack, counters);// solves the latinSquare
    printf("PUSH NUM: %d\n",counters->pushes);
    printf("POP NUM: %d\n",counters->pops); 

    freeStack(stack, size);                             // free the stack in total.
    for(int i=0;i<size;i++){                            // free the each row of the first latinSquare we read.
        free(latinSquare[i]);                           
    }
    free(latinSquare);                                  // free the latinSquare.
    free(counters);                                     // free the struct counters.
    return 0;                   
}

void solveLatinSquare(Node *node, int size, Stack *stack, BackTrackingCounters *counter){
    //base case
    if(isSolved(node->square, size))
        return;
    
    int position = findEmptySlot(node->square,size);        // position that we can enter a number (the empty spot)
    bool found=false;                                       // variable to know if a number was found to fit in the slot.
    for(int number=1;number<=size;number++){                // tries all the possible numbers, from 1 to size
        if(checkMove(node->square,size,number,position)){   // checks if the random number can be placed there
            found=true;
            int row =(position)%size;                       
            int col =(position)/size;
            insertNumber(&node->square,size,position,number);   // inserts the number in the latinSquare
            counter->pushes++;                                  // increases the push counter
            push(stack,node->square,size,row,col);              // pushes the new state of the latinSquare
            printf("PUSH: STEP %d\n", counter->step);              
            printLatinSquare(&node->square,size);               // prints the state of the latin Square
            counter->step++;                                    // increases the pop counter
            solveLatinSquare(stack->top,size,stack, counter);   // recursive call in order to solve the latinSquare, by keep adding numbers                                        
            if(isSolved(stack->top->square, size))              // recursive calls back; puzzle is solved
                return;
            else{                                               // recursive calls back for backtracking
                found=false;                                    // makes the found variable false again (since it wasn't a match)
                Node *n = pop(stack);                           // pops the very top element in the stack -> deletes the previous state of the latinSquare.
                freeNode(n,size);
                printf("POP: STEP %d\n", counter->step);
                printLatinSquare(&stack->top->square,size);
                counter->pops++;                                // increases the pop counter
                counter->step++;                                // increases the total steps
            }
        }
    }
    if(!found){                                                 // no number found for that slot; backtracks to previous state.
        return;
    }
}

void initBackTrackingCounters(BackTrackingCounters *counters){
    counters->pops=0;
    counters->pushes=0;
    counters->step=1; 
}
