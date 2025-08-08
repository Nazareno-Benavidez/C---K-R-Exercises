#include <stdio.h>

#define INT_BITS (sizeof(int) * 8)

int reverse_bits(int x);

int main()
{
    int x = 1;

    printf("%d", reverse_bits(x));

    return 0;
}

int reverse_bits(int x)
{
    int x_updated = 0;
    unsigned int mask = 0;

    for(int i = 0; i <= INT_BITS; i++){
        mask = ((unsigned) x >> (INT_BITS-1-i))&1;
        x_updated = x_updated | (mask << (INT_BITS-1-i));
    }
}