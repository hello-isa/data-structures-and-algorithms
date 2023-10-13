#include <stdio.h>
#include <stdlib.h>

// Definition
typedef struct node
{
    char elem;
    struct node *link;
} *STACK;

void initializeStack(STACK *S); // Initialize empty stack
void display(STACK S);          // Display the content of the stack
STACK createNode(char x);       // Create a new node
void PUSH(char x, STACK *S);    // Insert element into the stack
void POP(STACK *S);             // Delete an element from the stack
char TOP(STACK S);              // Return the value the top element holds
int isEmpty(STACK S);           // Check if the stack is empty
int isFull(STACK S);            // Not applicable in linked list implementation

int main()
{
    STACK A;

    printf("After initialization:\n");
    initializeStack(&A);
    display(A);

    printf("\nAfter pushing:\n");
    PUSH('S', &A);
    PUSH('T', &A);
    PUSH('A', &A);
    PUSH('C', &A);
    PUSH('K', &A);
    display(A);

    printf("\nTop: %c\n", TOP(A));

    printf("\nAfter popping:\n");
    POP(&A);
    POP(&A);
    display(A);

    printf("\nTop: %c\n", TOP(A));

    (isEmpty(A) == 1) ? printf("\nStack is empty.\n") : printf("\nStack is NOT empty.\n");

    return 0;
}

void initializeStack(STACK *S)
{
    *S = NULL;
}

void display(STACK S)
{
    if (S == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        for (; S != NULL; S = S->link)
        {
            printf("[%c]->", S->elem);
        }
        printf("\n");
    }
}

STACK createNode(char x)
{
    STACK newNode = (STACK)malloc(sizeof(struct node));
    if (newNode != NULL)
    {
        newNode->elem = x;
        newNode->link = NULL;
    }

    return newNode;
}

void PUSH(char x, STACK *S)
{
    // Create new node every time you insert
    STACK newNode = createNode(x);
    newNode->link = *S;
    *S = newNode;
}

void POP(STACK *S)
{
    STACK temp;
    temp = *S;
    *S = temp->link;
    free(temp);
}

char TOP(STACK S)
{
    return S->elem;
}

int isEmpty(STACK S)
{
    return (S == NULL) ? 1 : 0;
}
