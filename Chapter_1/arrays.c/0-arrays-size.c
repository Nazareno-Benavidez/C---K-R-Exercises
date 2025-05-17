#include <stdio.h>

/* The size of an array in C, measured in bytes, is determined by multiplying the number of elements by the size of each one.
For example, for int arrays, its elements correspond to integers; therefore, an array like int a[5] occupies 20(5 * 4) bytes of memory.
That's because an integer variable occupies 4 bytes, and there we have 5 integers. 
 The sizeof operator can be used to calculate the size of an array. */
int main()
{
    int intArray[5];    // Each int is 4 bytes
    char charArray[10]; // Each char is 1 byte
    double doubleArray[3];  // Each double is 8 bytes

    printf("Size of intArray: %d\n", sizeof(intArray)); // Prints 20
    printf("Size of charArray: %d\n", sizeof(charArray)); // Prints 10
    printf("Size of doubleArray: %d\n", sizeof(doubleArray)); // Prints 24
}