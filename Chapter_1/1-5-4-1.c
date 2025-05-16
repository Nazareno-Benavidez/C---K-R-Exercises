#include <stdio.h>

#define OUT 0
#define IN 1

int main()
{
    char c;
    int nl, nw, state;
    
    state = OUT;
    nl = nw = 0;

    while((c = getchar()) != EOF){
        putchar(c);
        if(c == '\n'){
            putchar('\n');
        }
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT){
            state = IN;
            ++nw;
        }
    }
    // printf("\n%d\n", nw);
    return 0;
}