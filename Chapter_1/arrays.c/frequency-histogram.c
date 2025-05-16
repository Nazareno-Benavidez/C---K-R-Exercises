#include <stdio.h>

/* print a histogram of the frequencies of different characters in its input */
int main()
{
    int c, i, n, max;
    n = 0;
    int ninputs[4];
    
    for(i = 0; i < 4; ++i)
        ninputs[i] = 0;

    while((c = getchar()) != EOF){
        if(c >= '0' && c <= '9')
            ++ninputs[0];
        else if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            ++ninputs[1];
        else if('.' == c || ',' == c || ';' == c || ':' == c || '!' == c || '?' == c)
            ++ninputs[2];
        else
            ++ninputs[3];
    }

    for(i = 0; i < 4; ++i){
        if (max < ninputs[i])
            max = ninputs[i];
    }

    printf("%d", max);

    return 0;
}