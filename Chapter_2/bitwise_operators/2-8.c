#include <stdio.h>

unsigned int right_rot(unsigned int x, int n);

/* Exercise 2−8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right
by n positions */
int main()
{
    unsigned int x = 7; // integer to rotate
    int n = 4; // number of bits to rotate x to the right

    // print the result of rotating x to the right by n bits
    printf("%u\n", right_rot(x, n));

    return 0;
}

// rotate an integer to the right by n bits
unsigned int right_rot(unsigned int x, int n)
{
    unsigned int int_bits = sizeof(int) * 8; // number of bits in int
    n = n % int_bits; /* ensure that n < int_bits to avoid undefined behaviour and logic (n = 33, only 1 rotation to the right\
    needed because 32 comes back to the initial position (like a 360 rotation) */

    // if n is 0, no rotation needed, and avoid undefined behavior on (x << 32)
    if(n == 0) 
        return x;

    unsigned int mask = ~(~0<<n); // rightmost n bits set to 1 mask
    unsigned int x_bits = (mask & x)<< (int_bits - n); /* extract the rightmost n bits of x and shift them to the left end
    (int_bits - n) is the number of positions to shift to the left, e.g. 32-4 = <<28 */

    // right shift n bits of x and set them on the other side
    return (x >> n) | x_bits;
}