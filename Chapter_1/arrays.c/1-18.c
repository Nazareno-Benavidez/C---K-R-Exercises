#include <stdio.h>

#define MAXLINE 1000

/* Exercise 1−18. Write a program to remove trailing blanks and tabs from each line of input, and to delete
entirely blank lines */
int my_get_line(char line[], int maxline);

int main()
{
    char line[MAXLINE];
    int len;

    while((len = my_get_line(line, MAXLINE)) > 0)
        printf("\n%s\n", line);
}

int my_get_line(char line[], int maxline)
{
    int i, c;

    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    // if (line[i-1] == '\t' || line[i-1] == ' ') this doesn't delete all trailing blanks and tabs, it only checks if the last char is a 
    //     line[i-1] = '\0';                      blank or a tab. Therefore, it doesn't do what the exercise asks for.
    // else
    //     line[i] = '\0'; 

    while(i > 0 && (line[i-1] == '\t' || line[i-1] == ' '))
        i--;

    line[i] = '\0';
    return i;
}