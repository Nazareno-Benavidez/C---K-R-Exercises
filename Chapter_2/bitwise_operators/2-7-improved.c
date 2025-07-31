#include <stdio.h>

unsigned int invert_bits(unsigned int x, int p, int n);

/*Exercise 2−7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p
inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/
// Solved V.2 -> clear code - decent comments
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
    // Compute the bit position where inversion starts (rightmost bit = position 0)
    unsigned int pos = p+1-n;
    // Create a mask with n rightmost bits set: e.g., n = 3 -> 00000111
    unsigned int mask = ~(~0<<n);
    // Invert x, shift right to align target bits with LSBs, mask to keep only those n bits
    // Then shift left to move inverted bits back to their original position
    unsigned int x_inverted_bits = (((~x>>pos) & mask)<<pos); 
    // Clear the n bits at the target position in x by shifting and inverting the mask
    unsigned int x_cleared = (x & ~(mask<<pos)); // 10101010 

    // Merge the cleared x with the inverted bits
    return x_cleared | x_inverted_bits; // 10000010 | 00000010 
}