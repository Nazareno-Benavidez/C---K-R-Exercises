#include <stdio.h>

unsigned int invert_bits(unsigned int x, int p, int n);

/*Exercise 2−7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p
inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/
// Solved.
int main()
{
    unsigned int x = 170;
    int p = 5;
    int n = 3;

    printf("%d", invert_bits(x, p, n));

    return 0;
}

unsigned int invert_bits(unsigned int x, int p, int n)
{
    unsigned mask = ~(~0<<n); // n = 3 => mask = 00000111 -> bits to change/compare with &
    unsigned int x_inverted_bits = (((~x>>(p+1-n))& mask)<<(p+1-n)); /* x is inverted and by doing >>(p+1-n), the n bits to get end
    at being the rightmost bits. Then, for ~170, p=5 and n=3 that yields 00001010 and the non n bits are set to 0 with the mask.
    Finally, after getting 00000010, the rightmost bits are moved so that they start at p => 00010000.*/
    unsigned int x_cleared = (x & ~(mask << (p+1-n))); /* mask(00000111) is set to starting position p -> 00111000, then inverted
    -> 11000111 to CLEAR THE n BITS OF x STARTING AT POS p. x bits(10101010) are compared using & with 11000111 => 10000010*/

    return x_cleared | x_inverted_bits; // set the n inverted bits to x_cleared
}