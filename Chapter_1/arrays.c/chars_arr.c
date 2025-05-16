#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];  

    max = 0;
    while((len = my_getline(line, MAXLINE)) > 0){
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0)
        printf("\nThe length of the longest line was: %d\nIt was: %s", max, longest);
    return 0;
}

int my_getline(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if('\n' == c){
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
void copy(char to[], char from[])
{
    int i;

    for(i = 0; (to[i] = from[i]) != '\0'; i++)
        ;
}