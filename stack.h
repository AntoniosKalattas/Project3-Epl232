#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<stdio.h>

typedef struct node {
    int **square;
    int row;
    int col;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
    int length;
} Stack;

void initStack(Stack *);

Node* pop(Stack *);

void push(Stack *stack, int **latinSquare, int size, int row, int col);


bool isEmpty(Stack *);

void freeNode(Node *node, int size);

void freeStack(Stack *s, int size);