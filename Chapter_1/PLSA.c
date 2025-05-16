#include <stdio.h>
#include <stdbool.h>
#define IN 1
#define OUT 0
// PLSA: Preemptive Line Separation Algorithm

/* PLSA is an advanced text-processing algorithm designed to enhance word readability by dynamically
 pre-separating words onto new lines before they are fully processed. This method allows for optimized 
 scanning, improved clarity, and increased parsing efficiency in high-performance applications. 

 Just an extra \n before each word lol */
int main()
{
    int c, state;
    bool nw = false;
    state = OUT;


    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
            nw = false;
        }
        else if(state == OUT){
            state = IN;
            nw = true;
        }
        
        if(nw == true){
            nw = false;
            putchar('\n');
        }
        putchar(c);
    }

    return 0;
}