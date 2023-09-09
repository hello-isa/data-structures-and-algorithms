// Create a C program that will let you:
// 1) insert a new element in the first position of the list if the ID is unique
// 2) delete a matched element in the list based on the ID number and return a dummy element
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ID;
    char LN[16], FN[24], MI; // Last name, First name, Middle Initial
    char course[8];
    int yearLevel;
} Studrec;

typedef struct node
{
    Studrec stud;
    struct node *link;
} *StudList; // Definition of the List

// Function declaration
void insertFirstUnique(StudList *headOfList, Studrec newStud);
Studrec deleteMatch(StudList *headOfList, int studID);
void printList(StudList headOfList);

int main()
{
    Studrec StudOne = {11111, "Sainz", "Carlos", 'V', "BSME", 4};
    Studrec StudTwo = {22222, "Leclerc", "Charles", 'P', "BSChE", 3};
    Studrec StudThree = {33333, "Gasly", "Pierre", 'L', "BSBA", 4};

    StudList NodeOne = (StudList)malloc(sizeof(struct node));
    StudList NodeTwo = (StudList)malloc(sizeof(struct node));
    StudList NodeThree = (StudList)malloc(sizeof(struct node));

    NodeOne->stud = StudOne;
    NodeTwo->stud = StudTwo;
    NodeThree->stud = StudThree;

    NodeOne->link = NodeTwo;
    NodeTwo->link = NodeThree;
    NodeThree->link = NULL;

    Studrec StudFour = {44444, "Ocon", "Esteban", 'L', "BSCE", 3}; // Try existing and non-existing ID number

    // Function call
    insertFirstUnique(&NodeOne, StudFour);
    deleteMatch(&NodeOne, 22222); // Try existing and non-existing ID number
    printList(NodeOne);

    return 0;
}

// Function definition
// Pointer to node since when inserting in the first position you do not need to keep track of the previous node
void insertFirstUnique(StudList *headOfList, Studrec newStud)
{
    StudList current = NULL;

    // Check if list is not NULL and ID is unique
    for (current = (*headOfList); current != NULL && newStud.ID != current->stud.ID; current = current->link)
    {
    }

    // Traversal reached the end which means ID is unique
    if (current == NULL)
    {
        StudList newNode = (StudList)malloc(sizeof(struct node)); // Create a new node
        if (newNode == NULL)                                      // Check if the creation is successful
        {
            printf("Failed allocation.\n");
        }
        else
        {
            newNode->stud = newStud;
            newNode->link = *headOfList;
            *headOfList = newNode;
        }
    }
    else
    {
        printf("ID is not unique.\n");
    }
}

// Pointer to pointer to node since you need to keep track of the previous node
Studrec deleteMatch(StudList *headOfList, int studID)
{
    Studrec dummy = {00000, "XXXXX", "XXXXX", 'X', "XXXXX", 0};
    StudList *current = NULL;

    // Traverse to check if list is not NULL and find the matching ID
    for (current = headOfList; (*current) != NULL && studID != (*current)->stud.ID; current = &(*current)->link)
    {
    }

    // Traversal reached the end of the list which means no matched ID number
    if ((*current) == NULL)
    {
        printf("No matching ID.\n");
    }
    else // Did not reached the end hence there is a matching ID
    {
        (*current)->stud = dummy;
        current = &(*current)->link;
        free(current); // Free up the memory space a.k.a. delete
    }

    return dummy;
}

void printList(StudList headOfList)
{
    StudList current = headOfList;

    printf("Student list:\n");
    while (current != NULL)
    {
        printf("ID: %d, Name: %s %c %s, Course: %s-%d\n", current->stud.ID, current->stud.FN, current->stud.MI, current->stud.LN, current->stud.course, current->stud.yearLevel);
        current = current->link;
    }
}