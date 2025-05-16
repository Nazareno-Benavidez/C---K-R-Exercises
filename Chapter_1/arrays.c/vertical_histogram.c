#include <stdio.h>

/* word length histogram program */

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAXHIST 15 /* histogram's max length */
#define MAXWORD 16 /* words' max length */

int main()
{
    int c, i, j,wl, state;
    int len = 0; /* length of each bar */
    int maxvalue = 0; /* longest word */
    int ovflow = 0; /* overflow words */
    int fdigit = 0; /* first digit of the length of a word(like 10 -> 1) */
    int ldigit = 0; /* last digit of the length of a word (like 10 -> 0) */
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
    putchar('\n');
    for(j = MAXHIST; j > 0; --j){
        for(i = 0; i < MAXWORD; ++i){
            if(wcontainer[i] > 0){
                if ((len = wcontainer[i] * MAXHIST / maxvalue) <= 0){
                    len = 1;
                }
            }
            else {
                len = 0;
            }
            if(len >= j)
            printf("#");
        else
            printf(" ");
        }
        putchar('\n');
    }
    for(i = 0; i < MAXWORD; ++i){
        if(i >= 10){
            fdigit = ldigit = i;
            while(fdigit >= 10)
                fdigit /= 10;
            printf("%d", fdigit);
            // printf("\r");
        }
        else
            printf("%d", i);
    }
    putchar('\n');
    for(i = 0; i < MAXWORD; ++i){
        if(i < 10)
            printf(" ");
        else
            printf("%d", i % 10);
        
    }
    if(ovflow > 0){
        printf("\nThere are %d words >= %d\n", ovflow, MAXWORD);
    }
}