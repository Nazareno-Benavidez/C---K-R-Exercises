#include <stdio.h>
//Word counting program
#define OUT 0
#define IN 1
int main()
{
    int c, wc, state, last_c;
    wc = 0;
    while((c = getchar()) != EOF){
        if((c == '\n' || c == ' ' || c == '\t') && last_c != '\n' && last_c != ' ' && last_c != '\t'){
            state = OUT;
            ++wc;
            last_c = c;
        }
        else{
            state = IN;
            last_c = c;
        }
    }
    if(state == 1)
        ++wc;
    printf("\n The number of words is: %d", wc);
    return 0;
}