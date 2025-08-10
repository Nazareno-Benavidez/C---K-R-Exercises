#include <stdio.h>

#define INT_BITS (sizeof(int) * 8) // number of bits in an int (standard: 32 bits)

int reverse_bits(int x); // function to reverse the bits of an int

int main()
{
    int x = 64;

    // print the reversed-bit representation of any int
    printf("%d", reverse_bits(x));

    return 0;
}

int reverse_bits(int x)
{
    int x_updated = 0; // reversed bits container 
    unsigned int rightmost_bits = 0; // i-th bit from the right -> to place it in left INT_BITS-1-i position
    unsigned int leftmost_bits = 0; // i-th bit from the left -> to place it in right i position

    // loop over all bit positions and reverse bits
    for(int i = 0; i < INT_BITS; i++){
        // extract the i-th bit from the right (LSB side) and shift it to its mirrored position from the left (MSB side)
        rightmost_bits = (((unsigned int) x >>i)&1) << (INT_BITS-1-i);
        // extract the i-th bit from the left (MSB side) and shift it to its mirrored position from the right side (LSB side)
        leftmost_bits = (((unsigned int) x >> (INT_BITS-1-i))&1) << i; 


        // combine both mirrored bits into the result
        x_updated |= (rightmost_bits | leftmost_bits);
    }

    return x_updated; // return the integer with reversed bits
}