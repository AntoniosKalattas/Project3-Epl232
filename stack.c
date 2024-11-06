#include "stack.h"

void initStack(Stack *s){
    s->top=NULL;
    s->length = 0;
}

Node* pop(Stack *stack) {
    if (stack->length == 0) return NULL;
    Node *node = stack->top;
    stack->top = stack->top->next;
    stack->length--;
    return node;
}
void push(Stack *stack, int **latinSquare, int size, int row, int col) {
    // Allocate a new node
    Node *node = (Node *)malloc(sizeof(Node));

    // Allocate and copy the Latin square data
    node->square = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        node->square[i] = (int *)malloc(size * sizeof(int));
        memcpy(node->square[i], latinSquare[i], size * sizeof(int));
    }

    // Copy the row and column values
    node->row = row;
    node->col = col;

    // Set the next pointer of the new node to the current top
    node->next = stack->top;

    // Update the top pointer to the new node
    stack->top = node;

    // Increment the length of the stack
    stack->length++;
}

bool isEmpty(Stack *s){
    if(s->length==0)
        return true;
    return false;
}

void freeStack(Stack *s){

}