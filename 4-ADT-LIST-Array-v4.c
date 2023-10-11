#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Definition
typedef struct list
{
    char *elemPtr;
    int count;
} *LIST;

typedef enum
{
    F,
    T
} boolean;

void initialize(LIST *L);              // Initialize into empty array
void display(LIST L);                  // Display the content of the list
void insert(LIST *L, char w, int pos); // Insert an element at any position in the list
void delete(LIST *L, char x);          // Delete an element from the list
void deleteOcc(LIST *L, char y);       // Delete all occurrences of the element from the list
boolean isMember(LIST L, char z);      // Check if an element is a member of the list

int main()
{
    LIST A;

    printf("Initialize empty list:\n");
    initialize(&A);
    display(A);

    printf("\nAfter insertion:\n");
    insert(&A, 'a', 0);
    insert(&A, 'b', 1);
    insert(&A, 'b', 2);
    insert(&A, 'c', 3);
    insert(&A, 'd', 4);
    display(A);

    printf("\nAfter deletion:\n");
    delete (&A, 'a');
    display(A);

    char deleteAll = 'b';
    printf("\nDelete all occurrences of %c:\n", deleteAll);
    deleteOcc(&A, deleteAll);
    display(A);

    char member = 'd';
    (isMember(A, member) == T) ? printf("\n%c is a member of the list.\n") : printf("\n%c is NOT a member of the list.\n");

    return 0;
}

void initialize(LIST *L)
{
    (*L) = (LIST)malloc(sizeof(struct list));
    if ((*L) != NULL)
    {
        (*L)->elemPtr = (char *)malloc(MAX * sizeof(char));
        (*L)->count = 0;
    }
}

void display(LIST L)
{
    int n;
    for (n = 0; n < L->count; n++)
    {
        printf("%d [%c]\n", n, L->elemPtr[n]);
    }
}

void insert(LIST *L, char w, int pos)
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

        for (n = (*L)->count; n > pos; n++)
        {
            (*L)->elemPtr[n] = (*L)->elemPtr[n - 1];
        }
        (*L)->elemPtr[pos] = w;
        (*L)->count++;
    }
}

void delete(LIST *L, char x)
{
    int n, pos;
    int found = F;

    for (n = 0; n < (*L)->count; n++)
    {
        if ((*L)->elemPtr[n] == x)
        {
            pos = n;
            found = T;
        }
    }

    if (found)
    {
        (*L)->count--;
        for (n = pos; n < (*L)->count; n++)
        {
            (*L)->elemPtr[n] = (*L)->elemPtr[n + 1];
        }
    }
}

void deleteOcc(LIST *L, char y)
{
    int n, j;
    for (n = j = 0; n < (*L)->count; n++)
    {
        if ((*L)->elemPtr[n] == y)
        {
            j++;
        }
        else
        {
            (*L)->elemPtr[n - j] = (*L)->elemPtr[n];
        }
    }
    (*L)->count = (*L)->count - j;
}

boolean isMember(LIST L, char z)
{
    int n;
    for (n = 0; n < L->count; n++)
    {
        if (L->elemPtr[n] == z)
        {
            return T;
        }
    }
    return F;
}