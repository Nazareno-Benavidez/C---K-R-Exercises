#include <stdio.h>
#define IN 1
#define OUT 0

// Prints its input one word per line

int main()
{
    int c, state, counter;
    c = state = counter = 0;
    
    while((c = getchar()) != EOF){
        if(0 == counter){
            putchar('\n');
            ++counter;
        }
        if(c == '\n' || c == '\t' || c == ' '){
            if(state == IN){
                state = OUT;
                putchar('\n');
            }
        }
        else {
            if(state == OUT)
                state = IN;
            putchar(c);
        }
    }
    return 0;
}