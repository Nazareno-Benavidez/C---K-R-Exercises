#include <stdio.h>


#define INT_BITS (sizeof(int) * 8)

unsigned int has_alternating_bits(int x);

int main()
{
    int x = 3; // 2863311530

    printf("%u", has_alternating_bits(x));

    return 0;
}

unsigned int has_alternating_bits(int x)
{
    int x_shifted = 0;
    int y = 0;

    if(x >> (INT_BITS-1) == 1)
        x_shifted = x >> 1;
    else
        x_shifted = x << 1;
    
    y = x ^ x_shifted;

    return (y & (y + 1) == 0); // y & ensure that for a number n, like 00001111, n+1 doesn't yield a 00010000(n+1 result) == 0 comparison.
}