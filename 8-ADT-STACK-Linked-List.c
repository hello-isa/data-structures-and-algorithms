#include <stdio.h>
#include <stdlib.h>

// Definition
typedef struct node
{
    char elem;
    struct node *link;
} *STACK;

void initializeStack(STACK *S);
void display(STACK S);
STACK createNode(char x);
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
    STACK newNode = createNode(x);
    newNode->link = *S;
    *S = newNode;
}