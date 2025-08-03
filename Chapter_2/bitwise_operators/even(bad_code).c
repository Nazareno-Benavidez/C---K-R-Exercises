#include <stdio.h>

void is_even(int x);

// program to check if a number is even
int main()
{
    int x = 5;

    is_even(x);
}

void is_even(int x)
{
    unsigned int lsb_mask = 1;
    int x_lsb = x & lsb_mask;

    if(x_lsb > 0)
        printf("Not even");
    else
        printf("Even");
}