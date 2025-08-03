#include <stdio.h>

unsigned int invert(unsigned int x, unsigned int p, unsigned int n);

/*Exercise 2−7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p
inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/
int main()
{
    unsigned int x = 64;
    unsigned int p = 6;
    unsigned int n = 3;

    printf("%u", invert(x, p, n));

    return 0;
}

unsigned int invert(unsigned int x, unsigned int p, unsigned int n)
{
    unsigned int mask = ~(~0<<n);
    unsigned int x_cleared = x & (~(mask << (p+1-n)));
    unsigned int x_inverted_bits = ((~x>>(p+1-n)) & (mask))<<(p+1-n);

    return x_cleared | x_inverted_bits;
}