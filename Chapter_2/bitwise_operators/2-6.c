#include <stdio.h>

unsigned int my_set_bits(unsigned int x, int p, int n, unsigned int y);
/* Exercise 2−6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p
set to the rightmost n bits of y, leaving the other bits unchanged. */
// Solved
int main()
{
    unsigned int x = 53;
    int p = 5;
    int n = 3;
    unsigned int y = 63;

    printf("%d", my_set_bits(x, p, n, y));

    return 0;
}

unsigned int my_set_bits(unsigned int x, int p, int n, unsigned int y)
{
    return (x & ~(~(~0<<n)<<(p+1-n))) | ((y & (~(~0<<n)))<<(p+1-n));
}