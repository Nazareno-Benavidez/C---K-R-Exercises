#include <stdio.h>

#define INT_BITS (sizeof(int) * 8) // number of bits in an int (standard: 32)

 /* Swap all even-positioned bits with their adjacent odd-positioned bits.
 Example: 0b10101010 → 0b01010101. */
int swap_even_odd_bits(int x); 

int main()
{
    int x = 170; // should print 85 for 170 -> 170 = 10101010 -> 01010101 = 85

    // print x with swapped bits
    printf("%d", swap_even_odd_bits(x));

    return 0;
}

int swap_even_odd_bits(int x)
{
    int result = 0; // container of x swapped
    for(int i = INT_BITS-1; i>0; i-=2){ // swap pairs of bits from left to right (i-=2 because it iterates over 2 bits each time)
        int odd_bit = (((unsigned int)x >> i)&1)<<(i-1); // extract bit from the left (i-th odd) and move it to the even position(i-1)
        int even_bit = (((unsigned int)x >> (i-1))&1) << i; // extract bit from the right (i-th even) and move it to the odd pos (i)

        result |= (odd_bit | even_bit); // combine swapped bits into result
    }

    // return int with all adjacent even and odd bits swapped
    return result;
}