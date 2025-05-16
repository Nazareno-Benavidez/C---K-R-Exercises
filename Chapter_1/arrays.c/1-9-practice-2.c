#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int my_get_line(char line[], int maxline);
void my_copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    char line[MAXLINE], longest[MAXLINE]; /* current input line, longest line saved */
    int len, max;  /* current line length, maximum line length */
    len = max = 0;

    while((len = my_get_line(line, MAXLINE)) > 0){ /* while there's another line (cheked by comparing its length with 0) */
        if(len > max){
            max = len;
            my_copy(longest, line);
        }
    }

    if(max > 0)
        printf("\nThe longest line was %d characters long.\n It was: %s\n", max, longest);
}

/* getline: read a line into line[] ** remember that char arrays are directly modified and not just copied **, return its length */
int my_get_line(char line[], int maxline)
{
    int c, i;

    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    line[i] = '\0';
    return i;
}
/* copy: copy 'from' into 'to' ** remember that char arrays are directly modified and not just copied **; assume to is big enough */
void my_copy(char to[], char from[])
{
    int i;

    for(i = 0; (to[i] = from[i]) != '\0'; i++)
        ;
}