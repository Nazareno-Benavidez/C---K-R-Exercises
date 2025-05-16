#include <stdio.h>

/* word length histogram program */

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAXHIST 15 /* histogram's max length */
#define MAXWORD 12 /* words' max length */

int main()
{
    int c, i, j,wl, state;
    int len = 0; /* length of each bar */
    int maxvalue = 0; /* longest word */
    int ovflow = 0; /* overflow words */
    int wcontainer[MAXWORD]; /* words length container */

    wl = state = 0;
    for(i = 0; i < MAXWORD; ++i)
        wcontainer[i] = 0;

    while((c = getchar()) != EOF){
        if(('\n' == c || '\t' == c || ' ' == c) && state == IN){
            state = OUT;
            if(wl > MAXWORD)
                ++ovflow;
            else{
                ++wcontainer[wl];
                //printf("\nwl: %d\n", wl);
            }
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
        state = OUT;
        if (wl > MAXWORD)
            ++ovflow;
        else
            ++wcontainer[wl];
        wl = 0;
    }
    for(i = 0; i < MAXWORD; ++i){
        if(wcontainer[i] > maxvalue){
            maxvalue = wcontainer[i];
        }
    }
    for(i = 0; i < MAXWORD; ++i){
        if(i > 0){
            printf("%d %d\t", i, wcontainer[i]);
        }
        if(wcontainer[i] > 0){
            if ((len = wcontainer[i] * MAXHIST / maxvalue) <= 0){
                len = 1;
            }
        }
        else {
            len = 0;
        }
        while(len > 0){
             printf("#");
             --len;
        }
            putchar('\n');
    }
    if(ovflow > 0){
        printf("There are %d words >= %d\n", ovflow, MAXWORD);
    }
}