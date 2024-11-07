#include "readLatin.h"
#include "LatinSquareMethods.h"
#include "stack.h"
#include  <time.h>


/** @struct BackTrackingCounters
 * 
 * This struct is keeping track, on the counters, such
 * as how many pushes, and pops, and the total steps;
 * 
 */
typedef struct{
    int step;   
    int pushes;
    int pops;
}BackTrackingCounters;

/** @brief It will initialise the BackTrackingCounters with default values.
 * 
 * @param BackTrackingCounters Pointer to BackTrackingCounters.
 * @return void.
 */
void initBackTrackingCounters(BackTrackingCounters *counters);

/** @brief It will solve the given LatinSquare.
 * 
 * Using recursion and backtracking it will solve the latinSquare.
 * It will move forward if the algorithm can find a number to place on the 
 * first empty slot. If it cannot, it will go to the previous empty slot
 * and try to find a new value to assing there.
 * 
 * @param Node Pointer currect top node of the stack.
 * @param int The size of the latinSquare.
 * @param Stack Pointer to the stack.
 * @param BackTrackingCounters Pointer to the BackTrackingCounters.
 * 
 * @return void.
 */
void solveLatinSquare(Node *node, int size, Stack *stack, BackTrackingCounters *);

int main(int argc, char * argv[]){
    if(argc==1){                                        // if given file is null.
        perror("Please give a file name.");
        return EXIT_FAILURE;
    }
    int **latinSquare=NULL;                             // 2d array to store the first state puzzle.

    int size = readLatinSquare(&latinSquare, argv[1]);  // size variable.

    Stack *stack = (Stack *)malloc(sizeof(Stack));      // create a stack, used for storing the states of the latinSquares.
    if(stack==NULL){                                    // if allocation faild.
        printf("Faild to allocate space for stack.");
        return EXIT_FAILURE;
    }
    initStack(stack);                                   // initiallise the stack.

    push(stack,latinSquare,size,0,0);                   // push the very first state of the latin square.
    BackTrackingCounters *counters =(BackTrackingCounters *)malloc(sizeof(BackTrackingCounters));   // allocate space for BackTrackingCounters.
    if(counters==NULL){                                 // if allocation faild.
        printf("Faild to allocate space for BackTrackingCounters.");
        return EXIT_FAILURE;
    }
    initBackTrackingCounters(counters);                 // initialise the BackTrackingCounters.

    solveLatinSquare(stack->top, size, stack, counters);// Solve the latinSquare.
    printf("PUSH NUM: %d\n",counters->pushes);
    printf("POP NUM: %d",counters->pops); 
    freeStack(stack, size);
}

void solveLatinSquare(Node *node, int size, Stack *stack, BackTrackingCounters *counter){
    //base case
    if(isSolved(node->square, size))
        return;
    
    int position = findEmptySlot(node->square,size);        // position that we can enter a number.
    bool found=false;                                       // variable to know if a number was found to fit in the slot.
    for(int number=1;number<=size;number++){                // try all the possible numbers, from 1 to size.
        if(checkMove(node->square,size,number,position)){   // cehck if the random number can be placed there.
            found=true;
            int row =(position)%size;                       
            int col =(position)/size;
            insertNumber(&node->square,size,position,number);   // insert the number in the latinSquare.
            counter->pushes++;                                  // increase the push counter.
            push(stack,node->square,size,row,col);              // push the new state of the latinSquare.
            printf("PUSH: STEP %d\n", counter->step);              
            printLatinSquare(&node->square,size);               // prints the state of the latin Square.
            counter->step++;                                    // increase the pop counter.
            solveLatinSquare(stack->top,size,stack, counter);   // recursive call.                                        
            if(isSolved(stack->top->square, size))              // if the recursive call back is because the puzzle is solved.
                return;
            else{                                               // if the recursive call back was due to backtracking.
                found=false;                                    // make the found variable false again.
                Node *n = pop(stack);                           // pop the very top element in the stack -> delete the previous state of the latinSquare.
                freeNode(n,size);
                printf("POP: STEP %d\n", counter->step);
                printLatinSquare(&stack->top->square,size);
                counter->pops++;                                // increase the pop counter.
                counter->step++;                                // increase the total steps.
            }
        }
    }
    if(!found){                                                 // if we couldn't find a number for that slot, backtrack to previous state.
        return;
    }
}

void initBackTrackingCounters(BackTrackingCounters *counters){
    counters->pops=0;
    counters->pushes=0;
    counters->step=1; 
}