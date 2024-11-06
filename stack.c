#include <stdio.h>

typedef struct Node {
    int row;
    int col;
    struct Node* next;
} NODE;

typedef struct Stack {
    NODE* top;
    int length;
} STACK;

NODE* pop(STACK *stack) {
    if (stack->length == 0) return NULL;
    NODE *node = stack->top;
    stack->top = stack->top->next;
    (stack->length)--;
    return node;
}
void push(STACK *stack, int **gameState, int row, int col) {
    NODE *node = malloc(sizeof(NODE));
    // Allocate and copy gameState to node->square
    node->row = row;
    node->col = col;
    node->next = stack->top;
    stack->top = node;
    stack->length++;
}
