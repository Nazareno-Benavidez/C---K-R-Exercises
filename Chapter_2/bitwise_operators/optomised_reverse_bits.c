#include <stdio.h>

#define INT_BITS (sizeof(int) * 8) // number of bits in an int (standard: 32 bits)

unsigned int reverse_bits(unsigned int x); // function to reverse the bits of an int

int main()
{
    unsigned int x = 64;

    // print the reversed representation of any unsigned int
    printf("%u", reverse_bits(x));

    return 0;
}

unsigned int reverse_bits(unsigned int x)
{
    unsigned result = 0; // reversed bits container

    // loop over all bit positions 
    for(int i = 0; i < INT_BITS; i++){
        /* shift result left by 1 to make room for the next bit (00000001 <<=1 -> 00000010) 
        also, move bits from LSB to MSB -> if you have 0b1 (1 decimal) -> the total of <<=1 performed = 31 (31*<<=1), therefore, 
        the LSB moved 31 times, 1 = new MSB */
        result <<=1;
        result |= (x >> i)&1; // extract the i-th bit of x and place it in the LSB position
    }

    // return the reversed version of x
    return result;
}