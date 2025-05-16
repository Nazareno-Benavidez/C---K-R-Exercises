#include <stdio.h>

#define OUT 0
#define IN 1

/* Count lines, words, and characters in input */
int main()
{
    int c, nl, nw, nc, state;
    
    nl = nw = nc = 0;
    state = OUT;

    while((c = getchar()) != EOF){
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\n' ||  c == '\t')
            state = OUT;
        else if(state == OUT){
            state = IN;
            ++nw;
        }
    }
    printf("\n Word Count: %d\n Character Count: %d \n Newline Count: %d \n", nw, nc, nl);
    return 0;
}