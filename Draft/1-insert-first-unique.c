// Create a C program that lets you insert an element at the first position of the linked list if it does not exist in the list
#include <stdio.h>
#include <string.h>
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
void displayList(StudList listMember);

int main()
{
    StudList studOne = (StudList)malloc(sizeof(struct node));
    StudList studTwo = (StudList)malloc(sizeof(struct node));
    StudList studThree = (StudList)malloc(sizeof(struct node));

    studOne->stud.ID = 11111;
    strcpy(studOne->stud.LN, "Carlos");
    strcpy(studOne->stud.FN, "Sainz");
    studOne->stud.MI = 'A';
    strcpy(studOne->stud.course, "BS CS");
    studOne->stud.yearLevel = 4;

    studTwo->stud.ID = 22222;
    strcpy(studTwo->stud.LN, "Yuki");
    strcpy(studTwo->stud.FN, "Tsunoda");
    studTwo->stud.MI = 'B';
    strcpy(studTwo->stud.course, "BS IS");
    studTwo->stud.yearLevel = 3;

    studThree->stud.ID = 33333;
    strcpy(studThree->stud.LN, "Max");
    strcpy(studThree->stud.FN, "Verstappen");
    studThree->stud.MI = 'C';
    strcpy(studThree->stud.course, "BS IT");
    studThree->stud.yearLevel = 2;

    studOne->link = studTwo;
    studTwo->link = studThree;
    studThree->link = NULL;

    // Element to be inserted
    Studrec studFour;

    studFour.ID = 99999; // Try existing and non-existing ID number
    strcpy(studFour.LN, "Alex");
    strcpy(studFour.FN, "Albon");
    studFour.MI = 'D';
    strcpy(studFour.course, "BS IT");
    studFour.yearLevel = 1;

    // Function call
    insertFirstUnique(&studOne, studFour);
    displayList(studOne);

    return 0;
}

// Function definition
void insertFirstUnique(StudList *listMember, Studrec newStud)
{
    StudList current = NULL;

    // Traverse through the list and check if the element is unique and list is not NULL
    for (current = *listMember; current != NULL && current->stud.ID != newStud.ID; current = current->link)
    {
    }

    // If the traversal reached the end of the list meaning the element does not exist in the list
    if (current == NULL)
    {
        // Since the element is unique, you can create a new node
        StudList newNode = (StudList)malloc(sizeof(struct node));

        // To check if the node is successfully created
        if (newNode == NULL)
        {
            printf("Allocation failed.\n");
        }
        else
        {
            newNode->stud = newStud;
            newNode->link = *listMember;
            *listMember = newNode;
        }
    }
    else
    {
        printf("Element is not unique.\n");
    }
}

void displayList(StudList listMember)
{
    printf("Student List:\n");
    while (listMember != NULL)
    {
        printf("ID: %d, Name: %s %s, Course: %s\n", listMember->stud.ID, listMember->stud.FN, listMember->stud.LN, listMember->stud.course);
        listMember = listMember->link;
    }
}