#include <stdio.h>

#define MAXWORD 11
#define MAXHIST 15
#define IN 1
#define OUT 0

int main()
{
    int c, state, wl, len, ovflow, temp, i, j;
    int maxvalue = 0;
    int wcontainer[MAXWORD];
    
    state = len = wl = ovflow = 0;
    for(i = 0; i < MAXWORD; ++i)
        wcontainer[i] = 0;

    while((c = getchar()) != EOF){
        if((' ' == c || '\n' == c || '\t' == c) && state == IN){
            state = OUT;
            
            if(wl > MAXWORD)
                ++ovflow;
            else
                ++wcontainer[wl];
            wl = 0;
            
        }
        else if(state == OUT){
            state = IN;
            wl = 1;
        }
        else   
            ++wl;
    }
    if(state == IN){
        if(wl > MAXWORD)
            ++ovflow;
        else
            ++wcontainer[wl];
        wl = 0;
    }
    for(i = 0; i < MAXWORD-1; i++){
        for(j = 0; j < MAXWORD-1-i; j++){
            if(wcontainer[j] > wcontainer[j+1]){
                temp = wcontainer[j];
                wcontainer[j] = wcontainer[j+1];
                wcontainer[j+1] = temp;
            }
        }
    }
    for(i = 0; i < MAXWORD; ++i){
        if(wcontainer[i] > maxvalue){
            maxvalue = wcontainer[i];
        }
    }
    putchar('\n');
    putchar('\n');
    
    for(i = MAXHIST; i > 0; i--){
        for(j = 0; j < MAXWORD; j++){
            if(wcontainer[j] > 0){
                if((len = wcontainer[j] * MAXHIST / wcontainer[MAXWORD-1]) <= 0)
                    len = 1;
            }
            else 
                len = 0;
            if(len >= i)
                printf("#");
            else   
                printf(" ");
        }
        putchar('\n');
    }

    /* write the equivalence of each rectangle below it */
}