// Create a C program that will display the bit pattern of the given integer. Display it into 4 bits.
// It should be compiler independent and will use bitwise and shift operators.
// NOTE: I used short for simulation purposes.

#include <stdio.h>

// Function declaration
void displayBitPattern(short x);

int main()
{
    short num = 10;

    // Function call
    printf("The bit pattern of %d: ", num);
    displayBitPattern(num);

    return 0;
}

// Function definition
void displayBitPattern(short x)
{
    // Convert the size from bytes into bits
    int bits = sizeof(short) * 8;
    int n;

    // Traverse each bit of the given number,s tarting from the leftmost to the rightmost bit
    for (n = bits - 1; n >= 0; n--)
    {
        // Shift the bits of x to the right by n positions
        // If both are 1 in binary values, it will print 1 else 0
        ((x >> n) & 1) ? printf("1") : printf("0");

        // To make it into 4-bit for easer readability
        if (n % 4 == 0)
        {
            printf(" ");
        }
    }
}