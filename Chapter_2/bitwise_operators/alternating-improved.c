#include <stdio.h>

#define INT_BITS (sizeof(int) * 8)
unsigned int has_alternating_bits(int x);

int main()
{
    int x = 2863311530;

    printf("%u", has_alternating_bits(x));
}

unsigned int has_alternating_bits(int x)
{
    if((((unsigned)x >> (INT_BITS-1))==1) && ((unsigned)x + ((unsigned)x>>1)) == -1)
        return 1;
    
    else if((((unsigned)x >> (INT_BITS-1))==0) && ((unsigned)x + ((unsigned)x<<1)) == -1)
        return 1;
    else
        return 0;
}