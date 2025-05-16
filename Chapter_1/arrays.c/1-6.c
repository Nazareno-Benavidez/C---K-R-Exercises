#include <stdio.h>

/* count digits, white spaces, other */
int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for(i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while((c = getchar()) != EOF){
        if(c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if(c == '\n' || c == '\t' || c == ' ')
            ++nwhite;
        else
            ++nother;
    }

    printf("\nDigits = ");
    for(i = 0; i < 10; ++i)
        printf("%d", ndigit[i]);
    printf("\n White spaces = %d", nwhite);
    printf("\n Other = %d", nother);

    return 0;
}