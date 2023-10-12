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

void initializeStack(STACK *S);
void display(STACK S);
void PUSH(char x, STACK *S);
void POP(STACK *S);

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

    printf("\nAfter popping:\n");
    POP(&A);
    display(A);

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
        int n;
        for (n = S.top; n < MAX; n++)
        {
            printf("%d [%c]\n", n, S.elem[n]);
        }
    }
}

void PUSH(char x, STACK *S)
{
    if (S->top != -1)
    {
        S->top--;
        S->elem[S->top] = x;
    }
    else
    {
        printf("Stack is full.\n");
    }
}

void POP(STACK *S)
{
    S->top++;
}