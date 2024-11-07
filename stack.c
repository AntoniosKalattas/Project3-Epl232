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
    // allocates a new node
    Node *node = (Node *)malloc(sizeof(Node));
    if(!node){
        perror("fail to allocate memory for push");
        return;
    }
    // allocates and copy the Latin square data
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

    // copies the row and column values
    node->row = row;
    node->col = col;

    // sets the next pointer of the new node to the current top
    node->next = stack->top;

    // updates the top pointer to the new node
    stack->top = node;

    // increases the length of the stack
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

#ifdef DEBUG
int main() {
    int size = 3;
    int **latinSquare=(int **)malloc(size*sizeof(int*));
    for (int i=0;i<size;i++){
        latinSquare[i]=(int *)malloc(size*sizeof(int));
        for (int j=0;j<size;j++) 
            latinSquare[i][j]=(i+j)%size+1;
    }
    Stack *stack=(Stack*)malloc(sizeof(Stack));            //Initialize stack
    initStack(stack);
    push(stack,latinSquare,size,0,0);                       //Push the state of latin in to the stack
    printf("Is stack empty? %s\n",isEmpty(stack)?"Yes":"No");// Check if stack is empty
    Node *node=pop(stack);                                  // Pop square from stack
    if(node)
        freeNode(node, size);                               // Free node
    else 
        printf("Pop operation returned NULL\n");
    for (int i=0;i<size;i++)                                // Free Latin square
        free(latinSquare[i]);
    free(latinSquare);
    freeStack(stack, size);                                 // Free stack
    return 0;
}
#endif
