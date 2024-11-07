#include "stack.h"

void initStack(Stack *s){
    if (!s) return;
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
    if(!node){
        perror("fail to allocate memory for push");
        return;
    }
    // Allocate and copy the Latin square data
    node->square = (int **)malloc(size * sizeof(int *));
    if(!node->square){
        free(node);
        return;
    }

    for (int i = 0; i < size; i++) {
        node->square[i] = (int *)malloc(size * sizeof(int));
        if(!node->square[i]){
            perror("Faild to Allocate space for node's latinSquare.");
            for (int j = 0; j < i; j++) {
                free(node->square[j]);
            }
            free(node->square);
            free(node);
            return;
        }
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
    return s->length==0;
}

void freeNode(Node *node, int size){
    if(!node)
        return;
    for(int i=0;i<size;i++)
        free(node->square[i]);
    
    free(node->square);
    free(node);
    return;
}

void freeStack(Stack *s, int size){
    if(!s)
        return;
    while(!isEmpty(s)){
        Node *n =pop(s);
        freeNode(n,size);
    }
    free(s);
        
}