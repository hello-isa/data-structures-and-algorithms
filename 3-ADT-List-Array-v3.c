// Version 3: List is a structure containing a pointer to the 1st element of a dynamic array, and variable count
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Definition
typedef struct
{
    char *elemPtr;
    int count;
} LIST;

typedef enum
{
    F,
    T
} boolean;

void initialize(LIST *L);              // Initialize to an empty list
void display(LIST L);                  // Display the content of the list
void insert(LIST *L, char w, int pos); // Insert an element at any position in the list
void delete(LIST *L, char x);          // Delete an element in the list
void deleteOcc(LIST *L, char y);       // Delete all the occurrences of an element in the list
boolean isMember(LIST L, char z);      // Check if element is a member of the list

int main()
{
    LIST A;

    printf("Initializing empty list:\n");
    initialize(&A);

    printf("\nAfter insertion:\n");
    insert(&A, 'a', 0);
    insert(&A, 'b', 1);
    insert(&A, 'c', 2);
    insert(&A, 'd', 3);
    insert(&A, 'a', 4);
    display(A);

    printf("\nAfter deletion:\n");
    delete (&A, 'd');
    display(A);

    char deleteAll = 'a';
    printf("\nAfter deleting all occurrences of %c:\n", deleteAll);
    deleteOcc(&A, deleteAll);
    display(A);

    char member = 'c';
    (isMember(A, member) == T) ? printf("\n%c is a member of the list.\n", member) : printf("\n%c is NOT a member of the list.\n", member);

    return 0;
}

void initialize(LIST *L)
{
    L->elemPtr = (char *)malloc(MAX * sizeof(char));
    L->count = 0;
}

void display(LIST L)
{
    int n;

    for (n = 0; n < L.count; n++)
    {
        printf("%d [%c]\n", n, L.elemPtr[n]);
    }
}

void insert(LIST *L, char w, int pos)
{
    if (L->count >= MAX)
    {
        printf("List is full.\n");
    }
    else if (pos < 0 || pos > L->count)
    {
        printf("Invalid position for insertion.");
    }
    else
    {
        int n;
        for (n = L->count; n > pos; n--)
        {
            L->elemPtr[n] = L->elemPtr[n - 1];
        }
        L->elemPtr[pos] = w;
        L->count++;
    }
}

void delete(LIST *L, char x)
{
    int n, j;
    int pos;
    int found = F; // Initialize found flag to False

    for (n = 0; n < L->count; n++)
    {
        if (L->elemPtr[n] == x)
        {
            pos = n;   // Get the position of the matched 'x' element
            found = T; // Found flag is True
        }
    }

    if (found)
    {
        L->count--;
        for (j = pos; j < L->count; j++)
        {
            L->elemPtr[j] = L->elemPtr[j + 1];
        }
    }
}

void deleteOcc(LIST *L, char y)
{
    int n, j;
    for (n = j = 0; n < L->count; n++)
    {
        if (L->elemPtr[n] == y)
        {
            j++;
        }
        else
        {
            L->elemPtr[n - j] = L->elemPtr[n];
        }
    }
    L->count = L->count - j;
}

boolean isMember(LIST L, char z)
{
    int n;
    for (n = 0; n < L.count; n++)
    {
        if (L.elemPtr[n] == z)
        {
            return T;
        }
    }
    return F;
}