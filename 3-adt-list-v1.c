// Create a C program that lets you initialize, insert and display an ADT list v1
#include <stdio.h>
#define MAX 5

// Structure definition
typedef struct
{
    char elem[MAX];
    int count;
} LISTv1;

// Function declaration
void initListV1(LISTv1 *A);
void insertSorted(LISTv1 *A, char newElem);
void displayList(LISTv1 A);

int main()
{
    LISTv1 L;
    initListV1(&L);
    insertSorted(&L, 'A');
    insertSorted(&L, 'B');
    insertSorted(&L, 'C');
    insertSorted(&L, 'D');
    insertSorted(&L, 'E');
    displayList(L);

    return 0;
}

// Function definition
void initListV1(LISTv1 *A)
{
    A->count = 0;
}

void insertSorted(LISTv1 *A, char newElem)
{
    int x;

    // Check if array can accommodate new element
    if (A->count < MAX)
    {
        // Traverse the array to insert element
        for (x = A->count; x > 0 && newElem < A->elem[x]; x--) // Since we are inserting char, use < or > and not !=
        {
            A->elem[x] = A->elem[x - 1]; // Shifting
        }
        A->elem[x] = newElem;
        A->count++;
    }
    else
    {
        printf("Array is full.\n");
    }
}

void displayList(LISTv1 A)
{
    int x;
    for (x = 0; x < A.count; x++)
    {
        printf("Index %d: %c\n", x, A.elem[x]);
    }
}