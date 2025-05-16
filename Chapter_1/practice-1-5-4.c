#include<stdio.h>

#define OUT 0
#define IN 1 

int main()
{
    int c, state, counter;

    counter = state = OUT;

    while((c = getchar()) != EOF){
        if(counter == 0){
            ++counter;
            putchar('\n');
        }
        if(c == ' ' || c == '\n' || c == '\t'){
            if(state == IN){
                putchar('\n');
                state = OUT;
            }
        }
        else {
            if(state == OUT)
                state = IN;

            putchar(c);
        }
    }
    putchar('\n');
}