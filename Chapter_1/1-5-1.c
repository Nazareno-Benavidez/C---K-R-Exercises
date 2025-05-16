#include <stdio.h>

void main()
{
    int c; // we do not use a simple char variable because, as you know naza, it does not operate with negative numbers.

    while((c = getchar()) != EOF){ //getchar() takes input -> input
        putchar(c); //putchar() writes input -> output
    }
}