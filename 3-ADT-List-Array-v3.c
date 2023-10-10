#include <stdio.h>
#define MAX 5

// Definition
typedef struct
{
    char *elemPtr;
    int count;
} LIST;

void initialize(LIST *L); // Initialize to an empty list
void display(LIST L);     // Display the content of the list

int main()
{
    LIST A;

    printf("Initializing empty list:\n");
    initialize(&A);

    return 0;
}

void initialize(LIST *L)
{
    L->count = 0;
}

void display(LIST L)
{
    int n;

    for (n = 0; n < L.count; n++)
    {
        printf("%d [%d]", n, L.elemPtr[n]);
    }
}