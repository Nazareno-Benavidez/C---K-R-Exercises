#include <stdio.h>
// This program copies its input to its output, replacing each string of one or more blanks by a single blank
int main()
{
    int c, last_c;

    last_c = 0;

    while((c = getchar()) != EOF){
        if(c != ' ' || last_c != ' ')
            putchar(c);
        last_c = c;
    }
}