/** @file stack.c
 *  @brief Stack; to store the different states of the latin square.
 *
 *  @author Antonios Kalattas.
 *  @author Alexandros Georgiou.
 */

#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<stdio.h>

/** 
 * @struct node
 * @brief represents a single state of the Latin square
 * contains the square state, row and column of last placement and links to the next node in the stack
 */
typedef struct node {
    int **square;      
    int row;            
    int col;           
    struct node* next;  
} Node;

/** 
 * @struct stack
 * @brief represents the stack structure; holds the states of the Latin square
 */
typedef struct stack {
    Node* top;          
    int length;        
} Stack;

/**
 * @brief initializes the stack to an empty state
 * 
 * @param s Pointer to the stack to initialize
 */
void initStack(Stack *s);

/**
 * @brief removes and returns the top node from the stack
 * 
 * @param stack Pointer to the stack
 * @return Node* Pointer to the popped node / NULL if the stack is empty
 */
Node* pop(Stack *stack);

/**
 * @brief pushes a new node with the current state of the Latin square onto the stack
 * 
 * @param stack Pointer to the stack
 * @param latinSquare 2D array representing the Latin square state
 * @param size Size of the Latin square (n x n)
 * @param row Row index where the number was placed
 * @param col Column index where the number was placed
 */
void push(Stack *stack,int **latinSquare,int size,int row,int col);

/**
 * @brief checks if the stack is empty
 * 
 * @param s Pointer to the stack
 * @return true if the stack is empty, false otherwise
 */
bool isEmpty(Stack *s);

/**
 * @brief frees the memory allocated for a single node, including its 2D array
 * 
 * @param node Pointer to the node to free
 * @param size Size of the Latin square (n x n) in the node
 */
void freeNode(Node *node,int size);

/**
 * @brief frees all nodes in the stack and releases allocated memory
 * 
 * @param s Pointer to the stack
 * @param size Size of the Latin square in each node of the stack
 */
void freeStack(Stack *s,int size);
