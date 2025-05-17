#include <stdio.h>

#define MAXLINE 1000

int my_get_line(char line[], int maxline);

/* Exercise 1−18. Write a program to remove trailing blanks and tabs from each line of input, and to delete
entirely blank lines */
int main()
{
    char line[MAXLINE];
    int len;

    while((len = my_get_line(line, MAXLINE)) > 0)
        printf("%s\n", line);
}

int my_get_line(char line[], int maxline)
{
    int c, i;

    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    while(i > 0 && (line[i-1] == '\t' || line[i-1] == ' '))
        i--;
    line[i] = '\0';
    return i;
}

