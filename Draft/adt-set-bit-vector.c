// Create a C program that will perform the following operations for the bit vector implementation of ADT set:
// Display bit pattern, display set element, check if it is a member, deletion, insertion, union, intersection and difference

// Given set: SET A = {7, 4, 0, 2} or 149

#include <stdio.h>
#include <stdlib.h>
#define MAX 8

// User-defined data type
typedef int SET[MAX];
typedef enum
{
    F,
    T
} boolean;

// Function declaration
void displayBitPattern(SET X);
void displaySetElement(SET X);
boolean isMember(SET X, int elem);
void delete(SET X, int elem); // An array is a pointer; 0(1)
void insert(SET X, int elem); // 0(1)
void displaySet(SET X);
SET *unionSet(SET X, SET Y); // Return type is pointer array since you cannot return an array in C
SET *intersectionSet(SET X, SET Y);
SET *differenceSet(SET X, SET Y);

int main()
{
    SET A = {1, 0, 1, 0, 1, 0, 0, 1}; //{7, 4, 0, 2}

    // Function call
    printf("Bit pattern of SET A:\n");
    displayBitPattern(A);

    printf("\nElements of SET A:\n");
    displaySetElement(A);

    int isElemMember = 0; // Try member and non-members of the SET
    printf("\n\nIs %d a member of SET A?\n", isElemMember);
    if ((isMember(A, isElemMember)) == T)
    {
        printf("Yes, %d is a member of the SET.\n", isElemMember);
    }
    else
    {
        printf("No, %d is not a member of the SET.\n", isElemMember);
    }

    int deleteElem = 4;
    printf("\nElements of SET A after deletion of %d:\n", deleteElem);
    delete (A, deleteElem);
    displayBitPattern(A);

    int insertElem = 6;
    printf("\nElements of SET A after insertion of %d:\n", insertElem);
    insert(A, insertElem);
    displayBitPattern(A);

    SET B = {0, 1, 1, 0, 0, 1, 0, 1};
    SET *C, *D, *E;

    printf("\nFor set union, intersection and difference\n");
    printf("SET A:\t\t\t");
    displaySet(A);
    printf("SET B:\t\t\t");
    displaySet(B);

    printf("Union:\t\t\t");
    C = unionSet(A, B);
    displaySet(*C);

    printf("Intersection:\t");
    D = intersectionSet(A, B);
    displaySet(*D);

    printf("Difference:\t\t");
    E = differenceSet(A, B);
    displaySet(*E);

    return 0;
}

// Function definition
void displayBitPattern(SET X)
{
    int n, m = 0;

    for (n = 0; n < MAX; n++)
    {
        printf("%d [%d]\n", m++, X[n]);
    }
}

void displaySetElement(SET X)
{
    int n;

    for (n = 0; n < MAX; n++)
    {
        if (X[n] == 1)
        {
            printf("%d ", n);
        }
    }
}

boolean isMember(SET X, int elem)
{
    int n = X[elem];
    (n == 1) ? T : F;
}

void delete(SET X, int elem)
{
    X[elem] = 0;
}

void insert(SET X, int elem)
{
    X[elem] = 1;
}

void displaySet(SET X)
{
    int n;

    printf("{");
    for (n = 0; n < MAX; n++)
    {
        printf("%d ", X[n]);
    }
    printf("}\n");
}

SET *unionSet(SET X, SET Y)
{
    // Create the SET in the heap
    SET *Z = (SET *)malloc(sizeof(SET));

    // Check if memory allocation is successful
    if (Z != NULL)
    {
        int n;
        for (n = 0; n < MAX; n++)
        {
            // Dereferencing first before accessing the array in the heap
            // Bitwise OR since  element must belong to X or Y or both
            (*Z)[n] = X[n] | Y[n];
        }
    }
    else
    {
        printf("Memory allocation failed.");
    }

    // Not necessary to include a return statement for pointer
    return Z;
}

SET *intersectionSet(SET X, SET Y)
{
    SET *Z = (SET *)malloc(sizeof(SET));

    if (Z != NULL)
    {
        int n;
        for (n = 0; n < MAX; n++)
        {
            // Bitwise AND since element must be common to both A and B
            (*Z)[n] = X[n] & Y[n];
        }
    }
    else
    {
        printf("Memory allocation failed.");
    }

    return Z;
}

SET *differenceSet(SET X, SET Y)
{
    SET *Z = (SET *)malloc(sizeof(SET));

    if (Z != NULL)
    {
        int n;
        for (n = 0; n < MAX; n++)
        {
            // Element must be in A but not in B
            (*Z)[n] = X[n] - Y[n]; // Output can be 1, 0 and -1

            // If the output is -1, set it to 0
            if ((*Z)[n] < 0)
            {
                (*Z)[n] = 0;
            }
        }
    }
    else
    {
        printf("Memory allocation failed.");
    }

    return Z;
}