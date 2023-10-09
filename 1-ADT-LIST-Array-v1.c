#include <stdio.h>
#define MAX 5

// Definition
typedef struct
{
    int elem[MAX];
    int count; // Keep track of the number of elements
} LIST;

typedef enum
{
    F,
    T
} boolean;

// Function declaration
void initialize(LIST *L);             // Initialize to empty list
void display(LIST L);                 // Display the content of the list
void insert(LIST *L, int x, int pos); // Insert an element at any position
void delete(LIST *L, int pos);        // Delete at any position
boolean isMember(LIST L, int x);

int main()
{
    LIST A;

    printf("Initialize empty list:\n");
    initialize(&A);
    display(A);

    printf("\nAfter insertion:\n");
    insert(&A, 11, 0);
    insert(&A, 12, 1);
    insert(&A, 13, 2);
    insert(&A, 14, 3);
    insert(&A, 15, 4);
    display(A);

    printf("\nAfter deletion:\n");
    delete (&A, 2);
    delete (&A, 1);
    display(A);

    int y = 14;
    (isMember(A, y) == T) ? printf("\n%d is a member of the list.", y) : printf("\n%d is NOT a member of the list.", y);

    return 0;
}

// Function definition
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
    if (pos < 0 || pos > L->count)
    {
        printf("Invalid position for deletion.");
    }
    else
    {
        int n;
        for (n = pos; n < L->count; n++)
        {
            L->elem[n] = L->elem[n + 1]; // Shifting
        }
        L->count--;
    }
}

boolean isMember(LIST L, int x)
{
    int n;
    for (n = 0; n < L.count; n++)
    {
        if (x == L.elem[n])
        {
            return T;
        }
    }
    return F; // This is outside of the loop so that this statement will only be executed once the loop has gone through the list and didn't found any match
    // Placing this inside the loop will return F as soon as it encounters element that does not match x which is incorrect if x is present later in the list
}