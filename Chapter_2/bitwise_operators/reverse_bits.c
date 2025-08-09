#include <stdio.h>

#define INT_BITS (sizeof(int) * 8)

int reverse_bits(int x);

int main()
{
    int x = 64;

    printf("%d", reverse_bits(x));

    return 0;
}

int reverse_bits(int x)
{
    int x_updated = 0;
    unsigned int rightmost_bits = 0;
    unsigned int leftmost_bits = 0;

    for(int i = 0; i < INT_BITS; i++){
        rightmost_bits = (((unsigned int) x >>i)&1) << (INT_BITS-1-i);
        leftmost_bits = (((unsigned int) x >> (INT_BITS-1-i))&1) << i;

        x_updated = rightmost_bits | leftmost_bits;
       // printf("%d", x_updated);
        //x_updated = x_updated | (bits << (INT_BITS-1-i));
    }

    return x_updated;
}