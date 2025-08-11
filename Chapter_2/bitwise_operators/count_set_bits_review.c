#include <stdio.h>

unsigned int count_set_bits(int x);

int main()
{
    int x = 58;

    printf("%u", count_set_bits(x));

    return 0;
}

unsigned int count_set_bits(int x)
{
    int i;
    for(i = 0; x != 0; i++){
        x &= x-1;
    }

    return i;
}