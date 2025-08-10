#include <stdio.h>

#define INT_BITS (sizeof(int) * 8)

unsigned int has_alternating_bits(int x);

int main()
{
    int x = 1431655765; //-1431655766

    printf("%u", has_alternating_bits(x));

    return 0;
}

unsigned int has_alternating_bits(int x)
{
    if((((unsigned int)x >> INT_BITS-1) == 1) && ((((unsigned int)x >> 1) ^ x) == -1))
        return 1;
    else if ((((unsigned int) x  >> INT_BITS-1) == 0) && ((((unsigned int)x << 1) ^ x) == -1))
        return 1;
    else
        return 0;
}