#include <stdio.h>

unsigned int set_bits(int x);

int main()
{
    int x = 37;

    printf("%u", set_bits(x));

    return 0;
}

unsigned int set_bits(int x)
{
    unsigned int counter = 0;

    while(x){
        x &= x-1;
        counter++;
    }

    return counter;
}