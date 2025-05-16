#include <stdio.h>
#define IN 1
#define OUT 0

/* print histogram of the lengths of words in its input */
void bin_assigner(int wlength, int bins[])
{
    if(wlength >= 1 && wlength <= 4)
        ++bins[0];
    else if(wlength >= 5 && wlength <= 7)
        ++bins[1];
    else if(wlength >= 8 && wlength <= 10)
        ++bins[2];
    else
        ++bins[3];
}
int main()
{
    int c, i, wlength, state;
    int bins[4];

    wlength = state = 0;
    for(i = 0; i < 4; ++i)
        bins[i] = 0;

    while((c = getchar()) != EOF){
        if(('\n' == c || '\t' == c || ' ' == c) && state == IN){
            state = OUT;
            bin_assigner(wlength, bins);
            wlength = 0;
        }
        else{
            if(state == OUT)
                state = IN;
            ++wlength;
        }
    }
    if(state == IN){
        state = OUT;
        bin_assigner(wlength, bins);
    }
    putchar('\n');
    for(i = 0; i < bins[0]; ++i)
        printf("#");
    printf("\t1-4(%d)", bins[0]);

    putchar('\n');
    for(i = 0; i < bins[1]; ++i)
        printf("#");
    printf("\t5-7(%d)", bins[1]);

    putchar('\n');
    for(i = 0; i < bins[2]; ++i)
        printf("#");
    printf("\t8-10(%d)", bins[2]);
    
    putchar('\n');
    for(i = 0; i < bins[3]; ++i)
        printf("#");

    printf("\t11+(%d)", bins[3]);
    putchar('\n');
    return 0;
}