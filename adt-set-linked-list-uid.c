#include <stdio.h>
#include <stdlib.h>

// Data type definition
typedef struct node
{
    int elem;
    struct node *link;
} *SET;

// Function declaration
void displayList(SET X);
void setUNion(SET X, SET Y, SET Z);

int main()
{
    // SET A, first set
    SET ANodeOne = (SET)malloc(sizeof(struct node));
    SET ANodeTwo = (SET)malloc(sizeof(struct node));
    SET ANodeThree = (SET)malloc(sizeof(struct node));

    ANodeOne->elem = 2;
    ANodeTwo->elem = 4;
    ANodeThree->elem = 7;

    ANodeOne->link = ANodeTwo;
    ANodeTwo->link = ANodeThree;
    ANodeThree->link = NULL;

    // SET B, second set
    SET BNodeOne = (SET)malloc(sizeof(struct node));
    SET BNodeTwo = (SET)malloc(sizeof(struct node));
    SET BNodeThree = (SET)malloc(sizeof(struct node));
    SET BNodeFour = (SET)malloc(sizeof(struct node));
    SET BNodeFive = (SET)malloc(sizeof(struct node));

    BNodeOne->elem = 1;
    BNodeTwo->elem = 2;
    BNodeThree->elem = 5;
    BNodeFour->elem = 7;
    BNodeFive->elem = 9;

    BNodeOne->link = BNodeTwo;
    BNodeTwo->link = BNodeThree;
    BNodeThree->link = BNodeFour;
    BNodeFour->link = BNodeFive;
    BNodeFive->link = NULL;

    // Third set
    SET C = NULL;

    // Function call
    printf("SET A: ");
    displayList(ANodeOne);
    printf("SET B: ");
    displayList(BNodeOne);

    setUNion(ANodeOne, BNodeOne, C);

    return 0;
}

// Function definition
void displayList(SET X)
{
    for (; X != NULL; X = X->link)
    {
        printf("[%d]->", X->elem);
    }
    printf("\n");
}

void setUNion(SET X, SET Y, SET Z)
{
}