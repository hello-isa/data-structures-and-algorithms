#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Definition
typedef struct node
{
    int elem[MAX];
    int count;
} *LIST;

typedef enum
{
    F,
    T
} boolean;

// Function declaration
void initialize(LIST *L);             // Initialize empty list
void display(LIST L);                 // Display the elements of the list
void insert(LIST *L, int x, int pos); // Insert an element at any position in the list
void delete(LIST *L, int pos);        // Delete at any position in the list
boolean isMember(LIST L, int y);      // Check if an element is a member of the list
void deleteOcc(LIST *L, int x);       // Delete all the occurrences of an element in the list

int main()
{
    LIST A = (LIST)malloc(sizeof(struct node));

    initialize(&A);
    printf("Initialize empty list:\n");
    display(A);

    printf("\nAfter insertion:\n");
    insert(&A, 11, 0);
    insert(&A, 22, 1);
    insert(&A, 33, 2);
    insert(&A, 11, 3);
    insert(&A, 22, 4);
    display(A);

    printf("\nAfter deletion:\n");
    delete (&A, 1);
    display(A);

    int x = 11;
    (isMember(A, x) == T) ? printf("\n%d is member of the list.\n", x) : printf("\n%d is NOT member of the list.\n", x);

    int y = 11;
    printf("\nAfter deleting all occurrence of %d:\n", y);
    deleteOcc(&A, y);
    display(A);

    return 0;
}

// Function definition
void initialize(LIST *L)
{
    (*L)->count = 0; // Since it is a double pointer, you need to dereference first before accessing
}

void display(LIST L)
{
    int n;
    for (n = 0; n < L->count; n++)
    {
        printf("%d [%d]\n", n, L->elem[n]);
    }
}

void insert(LIST *L, int x, int pos)
{
    if ((*L)->count >= MAX)
    {
        printf("List is full.\n");
    }
    else if (pos < 0 || pos > (*L)->count)
    {
        printf("Invalid position for insertion.\n");
    }
    else
    {
        int n;

        for (n = (*L)->count; n > pos; n--)
        {
            (*L)->elem[n] = (*L)->elem[n - 1];
        }
        (*L)->elem[pos] = x;
        (*L)->count++;
    }
}

void delete(LIST *L, int pos)
{
    if (pos < 0 || pos > (*L)->count)
    {
        printf("Invalid position for deletion.\n");
    }
    else
    {
        int n;

        for (n = pos; n < (*L)->count; n++)
        {
            (*L)->elem[n] = (*L)->elem[n + 1];
        }
        (*L)->count--;
    }
}

boolean isMember(LIST L, int y)
{
    int n;

    for (n = 0; n < L->count; n++)
    {
        if (y == L->elem[n])
        {
            return T;
        }
    }
    return F;
}

void deleteOcc(LIST *L, int x)
{
    int n, j = 0;

    for (n = 0; n < (*L)->count; n++)
    {
        if ((*L)->elem[n] == x)
        {
            (*L)->elem[n] = (*L)->elem[n + 1];
            j++;
        }
    }
    (*L)->count = (*L)->count - j;
}