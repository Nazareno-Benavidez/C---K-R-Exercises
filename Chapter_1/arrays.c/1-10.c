#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int my_get_line(void);
void my_copy(void);

/* print the longest input line(like in 1-9), but using external variables */
int main()
{
    int len;
    extern char line[], longest[];
    extern int max;

    max = 0;
    while((len = my_get_line()) > 0)
        if(len > max){
            max = len;
            my_copy();
        }
    
    if(max > 0)
        printf("\nThe longest line was %d characters long.\nIt was: %s", max, longest);
}

int my_get_line(void)
{
    int c, i;
    extern char line[];

    for(i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    while(i > 0 && (line[i-1] == ' ' || line[i-1] == '\t'))
        i--;

    line[i] = '\0';
    return i;
}

void my_copy(void)
{
    int i;
    extern char line[], longest[];

    for(i = 0; (longest[i] = line[i]) != '\0'; i++)
        ;
}