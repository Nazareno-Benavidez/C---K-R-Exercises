#include <stdio.h>

void lsb_check(int x);
void msb_check(int x);

// Write a C program to check Least Significant Bit (LSB) of a number is set or not.
// Write a C program to check Most Significant Bit (MSB) of a number is set or not.
int main()
{
    int x = -1; 

    lsb_check(x);
    msb_check(x);
    return 0;
}

void lsb_check(int x)
{
    unsigned int lsb_mask = 1;
    unsigned int x_lsb = x & lsb_mask;
    
    if(x_lsb > 0)
        printf("x's LSB is set.\n");
    else
        printf("x's LSB is not set.\n");
}

void msb_check(int x)
{
    unsigned int x_msb = ((unsigned int)x >> (sizeof(int) * 8-1));

    printf("%d", x_msb);
    if(x_msb > 0)
        printf("x's MSB is set.\n");
    else
        printf("x's MSB is not set.\n");
}