#include <stdio.h>

unsigned int is_even(int x);

int main()
{
    int x = 5;

    if(is_even(x))
        printf("Even number.");
    else
        printf("Odd number.");

    return 0;
}

unsigned int is_even(int x)
{
    return (x&1) == 0;
}
