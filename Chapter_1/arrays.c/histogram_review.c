#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXWORD 16
#define MAXHIST 15

int main()
{
    int c, state, wl, ovflow, i, len, j;
    int maxvalue;
    int fdigit, ldigit;

    state = wl = ovflow = len = maxvalue = 0;

    int wcontainer[MAXWORD];

    for(i = 0; i < MAXWORD; i++){
        wcontainer[i] = 0;
    }

    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            if(state == IN){
                state = OUT;
                if(wl > MAXWORD)
                    ovflow++;
                else
                    ++wcontainer[wl];
                wl = 0;
            }
        }
        else {
            if(state == OUT)
                state = IN;
            wl++;
        }
    }
    if(state == IN){
        state == OUT;
        if(wl > MAXWORD)
            ovflow++;
        else
            ++wcontainer[wl];
        wl = 0;
    }
    for(i = 0; i < MAXWORD; i++){
        if(wcontainer[i] > maxvalue)
            maxvalue = wcontainer[i];
    }
    for(i = MAXHIST; i > 0; i--){
        for(j = 0; j < MAXWORD; j++){
            if(wcontainer[j] > 0){
                if((len = wcontainer[j] * MAXHIST / maxvalue) <= 0)
                    len = 1;
            }
            else
                len = 0;
            if(len >= i){
                printf("#");
            }
            else
                printf(" ");
        }
        putchar('\n');
    }
    putchar('\n');
    for(i = 0; i < MAXWORD; i++){
        if(i >= 10){
            fdigit = i;
            while(fdigit >= 10)
                fdigit /= 10;
            printf("%d", fdigit);
        }
        else
            printf("%d", i);
    }
    putchar('\n');
    for(i = 0; i < MAXWORD; i++){
        if(i < 10)
            printf(" ");
        else
            printf("%d", i % 10);
    }
    printf("\nOverflow words = %d", ovflow);
}