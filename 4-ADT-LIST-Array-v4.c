#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Definition
typedef struct list
{
    char *elemPtr;
    int count;
} *LIST;

void initialize(LIST *L); // Initialize into empty array
void display(LIST L);     // Display the content of the list

int main()
{
    LIST A;

    printf("Initialize empty list:\n");
    initialize(&A);
    display(A);

    return 0;
}

void initialize(LIST *L)
{
    (*L)->elemPtr = (char *)malloc(MAX * sizeof(char));
    (*L)->count = 0;
}

void display(LIST L)
{
    int n;
    for (n = 0; n < L->count; n++)
    {
        printf("%d [%d]\n", n, L->elemPtr[n]);
    }
}