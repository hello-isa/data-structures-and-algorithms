// This is a C program that deletes the matched element
#include <stdio.h>
#include <stdlib.h>

// Structure definition
typedef struct node
{
    char data;
    struct node *link;
} *LIST;

// Function definition
void deleteElem(LIST *A, char elem);
void displayList(LIST A);

int main()
{
    LIST nodeOne = (LIST)malloc(sizeof(struct node));
    LIST nodeTwo = (LIST)malloc(sizeof(struct node));
    LIST nodeThree = (LIST)malloc(sizeof(struct node));
    LIST nodeFour = (LIST)malloc(sizeof(struct node));

    nodeOne->data = 'A';
    nodeTwo->data = 'B';
    nodeThree->data = 'C';
    nodeFour->data = 'D';

    nodeOne->link = nodeTwo;
    nodeTwo->link = nodeThree;
    nodeThree->link = nodeFour;
    nodeFour->link = NULL;

    printf("Node 1 address: %p\n", nodeOne);
    printf("Node 2 address: %p\n", nodeTwo);
    printf("Node 3 address: %p\n", nodeThree);
    printf("Node 4 address: %p\n", nodeFour);

    // Function call
    deleteElem(&nodeOne, 'c');
    displayList(nodeOne);

    return 0;
}

void displayList(LIST A)
{
    int x = 0;
    for (; A != NULL; A = A->link)
    {
        printf("Node %d: %c\n", x++, A->data);
    }
}

void deleteElem(LIST *A, char elem)
{
    LIST *current;

    for (current = A; *current != NULL && elem != (*current)->data; current = &(*current)->link)
    {
    }

    if (*current != NULL)
    {
        LIST temp;
        temp = *current;
        *current = temp->link;
        free(current);
    }
    else
    {
        printf("Matched element found.\n");
    }
}
