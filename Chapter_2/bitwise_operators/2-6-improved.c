//readable version of 2-6.c
#include <stdio.h>

unsigned int my_set_bits(unsigned int x, int p, int n, unsigned int y); // "my_" in case there's already a set_bits function in stdio.h
/* Exercise 2−6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p
set to the rightmost n bits of y, leaving the other bits unchanged. */
int main()
{
    unsigned int x = 53;
    unsigned int y = 63;
    int p = 5;
    int n = 3;

    printf("%d", my_set_bits(x, p, n, y));

    return 0;
}

unsigned int my_set_bits(unsigned int x, int p, int n, unsigned int y)
{
    // return (x & ~(~(~0<<n)<<(p+1-n))) | ((y & (~(~0<<n)))<<(p+1-n)); //v.1 -> unreadable
 
    unsigned int mask = (~(~0<<n)); //if n = 3 (~(11111000)) = (00000111) -> bits values to compare / reset
    unsigned int y_bits = ((y & (mask)) << (p+1-n)); // rightmost bits of y starting at position p 
    unsigned x_bits = (x & ~(mask << (p+1-n))); // x with n bits from pos p set to 0

    // x_bits "to-change-bits"(n bits from pos p) are set to the rightmost bits of y (y_bits has them stored starting at p)
    return x_bits | y_bits;
}