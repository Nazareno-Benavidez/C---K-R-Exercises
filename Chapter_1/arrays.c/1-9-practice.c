#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void my_copy(char to[], char from[]);

int main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    while((len = my_getline(line, MAXLINE)) > 0){
        if(len > max){
            max = len;
            my_copy(longest, line);
        }
    }
    if(max > 0 && max > 1)
        printf("\nThe longest line was %d characters long. \nIt was: %s.", max, longest);
    else if(max > 0 && max == 1)
        printf("\nThe longest line was %d character long. \nIt was: %s.", max, longest);
    else
        printf("No lines were input.");

    return 0;
}

int my_getline(char line[], int maxline)
{
    int c, i;

    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    i++;
    line[i] = '\0';
    return i;
}

void my_copy(char to[], char from[])
{
    int i;

    for(i = 0; (to[i] = from[i]) != '\0'; i++)
        ;
}