#include <stdio.h>

unsigned int right_rot(unsigned int x, int n);

/* Exercise 2−8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right
by n positions */
int main()
{
    unsigned int x = 7;
    int n = 4;

    printf("%d\n%d", right_rot(x, n), sizeof(int) * 8);

    return 0;
}

unsigned int right_rot(unsigned int x, int n)
{
    int i;
    unsigned int int_bits = sizeof(int) * 8;
    unsigned int mask = ~(~0<<n);
    unsigned int x_bits = (mask & x); //<< (int_bits - n);
    unsigned int x_rotated = 0;
    unsigned int x_test = 0;
    for(i=0; i<n; i++){
        //x_rotated = x_rotated | (x_bits << (int_bits-1) - i);
        //x_rotated = x_bits << (int_bits-1) -i;
        printf("\n%d\n", x_rotated);
    }

    return (x >> n) | x_rotated;
}