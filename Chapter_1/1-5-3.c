#include <stdio.h>
//program to count newlines.
void main()
{
    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF){
        if(c == '\n')
            ++nl;
    }
    printf("\n%d\n", nl);
}