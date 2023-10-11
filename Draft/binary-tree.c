#include <stdio.h>
#include <stdlib.h>

// Tree definition
typedef struct treeNode
{
    int value;
    struct treeNode *childOne;
    struct treeNode *childTwo;
    struct treeNode *childThree;
} *binaryTree;

// Function declaration
binaryTree createNode(int x);
void displayPreorder(binaryTree parent);
void displayPostorder(binaryTree child);

int main()
{
    binaryTree n1, n2, n3, n4, n5, n6, n7;

    // Create tree nodes
    n1 = createNode(5);
    n2 = createNode(0);
    n3 = createNode(6);
    n4 = createNode(3);
    n5 = createNode(1);
    n6 = createNode(2);
    n7 = createNode(8);

    // Connect tree nodes
    n1->childOne = n2;
    n1->childTwo = n3;
    n1->childThree = n6;

    n2->childOne = NULL;
    n2->childTwo = NULL;
    n2->childThree = NULL;

    n3->childOne = n4;
    n3->childTwo = n5;
    n3->childThree = NULL;

    n4->childOne = NULL;
    n4->childTwo = NULL;
    n4->childThree = NULL;

    n5->childOne = NULL;
    n5->childTwo = NULL;
    n5->childThree = NULL;

    n6->childOne = n7;
    n6->childTwo = NULL;
    n6->childThree = NULL;

    n7->childOne = NULL;
    n7->childTwo = NULL;
    n7->childThree = NULL;

    // Display the tree
    // Expected display: 5, 0, 6, 3, 1, 2, 8
    printf("Preoder: \n");
    displayPreorder(n1);
    // Expected display: 0, 3, 1, 6, 8, 2, 5
    printf("Postoder: \n");
    displayPostorder(n1);

    return 0;
}

// Function definition
binaryTree createNode(int x)
{
    binaryTree newNode = (binaryTree)malloc(sizeof(struct treeNode));
    newNode->value = x;
    newNode->childOne = NULL;
    newNode->childTwo = NULL;
    newNode->childThree = NULL;

    return newNode;
}

void displayPreorder(binaryTree parent)
{
    if (parent == NULL)
    {
        return;
    }

    printf("%d\n", parent->value);
    displayPreorder(parent->childOne);
    displayPreorder(parent->childTwo);
    displayPreorder(parent->childThree);
}

void displayPostorder(binaryTree child)
{
    if (child == NULL)
    {
        return;
    }

    displayPostorder(child->childOne);
    displayPostorder(child->childTwo);
    displayPostorder(child->childThree);
    printf("%d\n", child->value);
}