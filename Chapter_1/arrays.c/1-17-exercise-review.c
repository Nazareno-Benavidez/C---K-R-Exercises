#include <stdio.h>
#define MAXLINE 1000

int my_get_line(char line[], int maxline);

int main()
{
    int len;
    int long_line = 80;
    char line[MAXLINE];

    while((len = my_get_line(line, MAXLINE)) > 0){
        if(len > long_line)
            printf("\nThe length of the line (%s) is %d", line, len);
    }
}

int my_get_line(char line[], int maxline)
{
    int i, c;

    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    
    line[i] = '\0';
    return i;
}