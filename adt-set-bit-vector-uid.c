// Create C program for the union, intersection and difference operations of the bit vector implementation for ADT set.
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// User-defined data type
typedef int SET[MAX];

// Function declaration
void displaySet(SET A);
// Return type is pointer array since you cannot return an array in C
SET *setUnion(SET X, SET Y);
SET *setIntersection(SET X, SET Y);
SET *setDifference(SET X, SET Y);

int main()
{
    SET A = {1, 0, 0, 1, 0}; // A = {0, 3}
    SET B = {0, 1, 0, 1, 1}; // B = {1, 3, 4}
    SET *C, *D, *E;

    printf("SET A: \t\t\t");
    displaySet(A);
    printf("SET B: \t\t\t");
    displaySet(B);

    printf("Union: \t\t\t");
    C = setUnion(A, B);
    displaySet(*C);

    printf("Intersection: \t");
    D = setIntersection(A, B);
    displaySet(*D);

    printf("Difference: \t");
    E = setDifference(A, B);
    displaySet(*E);

    return 0;
}

// Function definition
void displaySet(SET A)
{
    int n;
    printf("{");
    for (n = 0; n < MAX; n++)
    {
        printf("%d ", A[n]);
    }
    printf("}\n");
}

SET *setUnion(SET X, SET Y)
{
    // Create the SET in the heap
    SET *Z = (SET *)malloc(sizeof(SET));

    // Check if memory allocation is successful
    if (Z != NULL)
    {
        int n;
        for (n = 0; n < MAX; n++)
        {
            // Dereferencing first before accessing the array
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

SET *setIntersection(SET X, SET Y)
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

SET *setDifference(SET X, SET Y)
{
    SET *Z = (SET *)malloc(sizeof(SET));

    if (Z != NULL)
    {
        int n;
        for (n = 0; n < MAX; n++)
        {
            // Element must be in A but not in B
            (*Z)[n] = X[n] - Y[n];

            // Output can only be 1, 0 or -1
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