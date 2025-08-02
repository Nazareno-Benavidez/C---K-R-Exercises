#include <stdio.h>

/*
 * The function and variables use 'unsigned int' because we are manipulating raw bit patterns.
 * Using unsigned types ensures well-defined behavior for bitwise operations and shifts,
 * avoids sign-extension issues, and clearly indicates that these values represent bits,
 * not signed numbers.
 */
unsigned int my_set_bits(unsigned int x, int p, int n, unsigned int y);
/* Exercise 2−6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p
set to the rightmost n bits of y, leaving the other bits unchanged. */
int main()
{
    int x = 16;
    int y = 1;
    int p = 0;
    int n = 1;
    
    printf("%d", my_set_bits(x, p, n, y));
    return 0;
}

unsigned int my_set_bits(unsigned int x, int p, int n, unsigned int y)
{
    unsigned int pos = p+1-n; // Position of the rightmost bit in the group
    unsigned int n_bit_mask = ~(~0<<n); // Mask with n rightmost bits set (e.g. 0b00000111)

    unsigned int x_cleared = x & ~(n_bit_mask<<pos); // Clear n bits at position p
    unsigned int y_bits = (y & n_bit_mask)<<pos; // Extract rightmost n bits from y and position them

    return x_cleared | y_bits; // Combine the two parts
}