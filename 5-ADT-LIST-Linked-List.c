#include <stdio.h>
#include <stdlib.h>

// Definition
typedef struct node
{
    int data;
    struct node *link;
} *LIST;

typedef enum
{
    F,
    T
} boolean;

void initialize(LIST *L);              // Initialize empty list
void display(LIST L);                  // Display the content of the list
LIST createNode(int value);            // Create a new node which is needed every time you insert
void insertHead(LIST *L, int value);   // Insert a new element at the head of the list
void insertTail(LIST *L, int value);   // Insert a new element at the tail of the list
void insertSorted(LIST *L, int value); // Insert a new element in a sorted list
void deleteHead(LIST *L);              // Delete the first element (head) of the list
void deleteTail(LIST *L);              // Delete the last element(tail) of the list
void deleteOccur(LIST *L, int x);      // Delete all occurrences of an element in the list
boolean isMember(LIST L, int y);       // Check if an element is a member of the list

int main()
{
    LIST A;

    initialize(&A);

    printf("Insert at head:\n");
    insertHead(&A, 20);
    insertHead(&A, 20);
    insertHead(&A, 5);
    display(A);

    printf("\nInsert at tail:\n");
    insertTail(&A, 42);
    insertTail(&A, 100);
    display(A);

    int x = 32;
    printf("\nInsert %d in a sorted list:\n", x);
    insertSorted(&A, x);
    display(A);

    printf("\nDelete head:\n");
    deleteHead(&A);
    display(A);

    printf("\nDelete tail:\n");
    deleteTail(&A);
    display(A);

    int deleteAll = 20;
    printf("\nDelete all occurrences of %d:\n", deleteAll);
    deleteOccur(&A, deleteAll);
    display(A);

    int member = 42;
    (isMember(A, member) == T) ? printf("\n%d is a member of the list.\n", member) : printf("\n%d is NOT a member of the list.\n", member);

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
void deleteHead(LIST *L)
{
    LIST *temp;
    temp = L;
    *L = (*temp)->link;
    free(temp);
}

void deleteTail(LIST *L)
{
    LIST *current, *temp;
    // To know the last element, the link is NULL
    for (current = L; (*current)->link != NULL; current = &(*current)->link)
    {
    }
    temp = current;
    *current = (*temp)->link;
    free(temp);
}

void deleteOccur(LIST *L, int x)
{
    LIST *current, *temp;
    for (current = L; (*current) != NULL;)
    {
        if ((*current)->data == x)
        {
            temp = current;
            *current = (*temp)->link;
            free(temp);
        }
        else
        {
            current = &(*current)->link;
        }
    }
}

boolean isMember(LIST L, int y)
{
    LIST current;
    for (current = L; current != NULL; current = current->link)
    {
        if (current->data == y)
        {
            return T;
        }
    }
    return F;
}