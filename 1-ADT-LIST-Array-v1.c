#include <stdio.h>
#define MAX 5

// Definition
typedef struct
{
    int elem[MAX];
    int count; // Keep track of the number of elements
} LIST;

void initialize(LIST *L);             // Initialize to empty list
void display(LIST L);                 // Display the content of the list
void insert(LIST *L, int x, int pos); // Insert an element at any position
void delete(LIST *L, int pos);        // Delete at any position

int main()
{
    LIST A;

    initialize(&A);

    insert(&A, 11, 0);
    insert(&A, 12, 1);
    insert(&A, 13, 2);
    insert(&A, 14, 3);
    insert(&A, 15, 4);
    printf("Insertion:\n");
    display(A);

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
        printf("%d [%d]\n", n, L.elem[n]);
    }
}

void insert(LIST *L, int x, int pos)
{
    if (L->count >= MAX)
    {
        // Check if list is full
        printf("List is full.\n");
    }
    else if (pos < 0 || pos > MAX - 1)
    {
        // Check if position to be inserted exist in the list
        // Position starts from 0 until MAX-1
        printf("Invalid position for insertion.\n");
    }
    else
    {
        // Insertion is allowed since list is not full and position is valid
        int n;

        for (n = L->count; n > pos; n--)
        {
            L->elem[n] = L->elem[n - 1]; // Shifting
        }
        L->elem[pos] = x;
        L->count++;
    }
}

void delete(LIST *L, int pos)
{
    if (pos < 0 && pos)
}