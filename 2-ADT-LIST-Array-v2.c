#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Definition
typedef struct node
{
    int elem[MAX];
    int count;
} *LIST;

// Function declaration
void initialize(LIST *L);             // Initialize empty list
void display(LIST L);                 // Display the elements of the list
void insert(LIST *L, int x, int pos); // Insert an element at any position in the list

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
    insert(&A, 44, 3);
    insert(&A, 55, 4);
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