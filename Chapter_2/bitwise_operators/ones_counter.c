#include <stdio.h>

#define INT_BITS (sizeof(int) * 8)
unsigned int count_ones(int x);
//Return the number of 1’s in the binary representation of x (Hamming weight).
int main()
{
    int x = 127;

    //printf("%u", count_ones(x));
    printf("%u", count_ones(x));
}

unsigned int count_ones(int x)
{
    unsigned int x_bit = 0;
    unsigned int counter = 0;
    for(int i = INT_BITS-1; i >= 0; i--){
        x_bit = ((unsigned)x >> i) & 1;
        if(x_bit == 1){
            counter++;
        }
    }

    return counter;
}