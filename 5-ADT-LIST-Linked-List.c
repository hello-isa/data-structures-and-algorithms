#include <stdio.h>
#include <stdlib.h>

// Definition
typedef struct node
{
    int data;
    struct node *link;
} *LIST;

void initialize(LIST *L);              // Initialize empty list
void display(LIST L);                  // Display the content of the list
LIST createNode(int value);            // Create a new node which is needed every time you insert
void insertHead(LIST *L, int value);   // Insert a new element at the head of the list
void insertTail(LIST *L, int value);   // Insert a new element at the tail of the list
void insertSorted(LIST *L, int value); // Insert a new element in a sorted linked list

int main()
{
    LIST A;

    initialize(&A);

    printf("Insert at head:\n");
    insertHead(&A, 10);
    insertHead(&A, 5);
    display(A);

    printf("\nInsert at tail:\n");
    insertTail(&A, 42);
    display(A);

    int x = 32;
    printf("\nInsert %d in a sorted list:\n", x);
    insertSorted(&A, x);
    display(A);

    return 0;
}

void initialize(LIST *L)
{
    (*L) = NULL;
}

void display(LIST L)
{
    for (; L != NULL; L = L->link)
    {
        printf("[%d]->", L->data);
    }
    printf("\n");
}

LIST createNode(int value)
{
    LIST newNode = (LIST)malloc(sizeof(struct node));
    if (newNode != NULL) // To check if it is successfully created
    {
        newNode->data = value;
        newNode->link = NULL;
    }
    else
    {
        printf("Failed to allocate memory.\n");
    }

    return newNode;
}

void insertHead(LIST *L, int value)
{
    LIST newNode = createNode(value);

    if (*L == NULL) // If list is empty
    {
        *L = newNode; // Set the new node as the head of the list
    }
    else // List is not empty
    {
        newNode->link = *L; // Point the new node to the current head
        *L = newNode;       // Update the head to the new node
    }
}

void insertTail(LIST *L, int value)
{
    LIST newNode = createNode(value);

    if (*L == NULL) // If list is empty
    {
        *L = newNode;
    }
    else // If list is not empty
    {
        LIST *current;
        for (current = L; *current != NULL; current = &(*current)->link)
        {
        }
        newNode->link = *current;
        *current = newNode;
    }
}

void insertSorted(LIST *L, int value)
{
    LIST newNode = createNode(value);

    if (*L == NULL)
    {
        *L = newNode;
    }
    else
    {
        LIST *current;
        for (current = L; (*current) != NULL && (*current)->data < newNode->data; current = &(*current)->link)
        {
        }
        newNode->link = *current;
        *current = newNode;
    }
}