#include <stdio.h>
#define MAX 5

// Definition
typedef struct
{
    int elem[MAX];
    int count;
} *LIST;

// Function declaration
void initialize(LIST L);
void display(LIST L);

int main()
{
    LIST A;

    initialize(A);
    printf("Initialize empty list:\n");
    display(A);

    return 0;
}

// Function definition
void initialize(LIST L)
{
    L->count = 0;
}

void display(LIST L)
{
    int n;
    for (n = 0; n < L->count; n++)
    {
        printf("%d [%d]\n", n, L->elem[n]);
    }
}