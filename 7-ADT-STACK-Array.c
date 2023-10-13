// Stack will grow from MAX-1 to 0
#include <stdio.h>
#include <stdlib.h>
#define MAX 8

// Definition
typedef struct
{
    char elem[MAX];
    int top;
} STACK;

void initializeStack(STACK *S); // Initialize empty stack
void display(STACK S);          // Display the content of the stack
void PUSH(char x, STACK *S);    // Insert element into the stack
void POP(STACK *S);             // Delete an element from the stack
int TOP(STACK S);               // Return the index of the top element in the stack
int isEmpty(STACK S);           // Check if the stack is empty
int isFull(STACK S);            // Check if the stack is full

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

    printf("\nTop: %d\n", TOP(A));

    printf("\nAfter popping:\n");
    POP(&A);
    POP(&A);
    display(A);

    printf("\nTop: %d\n", TOP(A));

    (isEmpty(A) == 1) ? printf("\nStack is empty.\n") : printf("\nStack is NOT empty.\n");

    (isFull(A) == 1) ? printf("\nStack is full.\n") : printf("\nStack is NOT full.\n");

    return 0;
}

void initializeStack(STACK *S)
{
    S->top = MAX - 1;
}

void display(STACK S)
{
    if (S.top == MAX - 1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        for (; S.top < MAX; S.top++)
        {
            printf("%d [%c]\n", S.top, S.elem[S.top]);
        }
    }
}

void PUSH(char x, STACK *S)
{
    if (S->top != -1)
    {
        S->elem[S->top] = x;
        S->top--;
    }
    else
    {
        printf("Stack is full.\n");
    }
}

void POP(STACK *S)
{
    if (S->top != MAX - 1)
    {
        S->top++;
    }
}

int TOP(STACK S)
{
    return S.top;
}

int isEmpty(STACK S)
{
    (S.top == MAX) ? 1 : 0;
}

int isFull(STACK S)
{
    (S.top == 0) ? 1 : 0;
}
