#include <stdio.h>

#define INT_BITS (sizeof(int) * 8)

int copy_msb_to_all(int x);

/* copy_msb_to_all(x)
 Return a number where all bits are set to the MSB of x (i.e., if MSB is 1, return all 1’s, else all 0’s).
*/
int main()
{
    int x = 5;

    printf("%d", copy_msb_to_all(x));

    return 0;
}

int copy_msb_to_all(int x)
{
    if(((unsigned)x >> (INT_BITS-1)) & 1)
        return x | -1; // return -1; - easier
    else
        return x & 0; // return 0 - easier
}