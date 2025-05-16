#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);

int main()
{
    int len;
    int long_line = 80;
    char line[MAXLINE];

    while((len = my_getline(line, MAXLINE)) > 0){
        if(len > long_line)
            printf("\n%s", line);
    }
}

int my_getline(char line[], int maxline)
{
    int c, i;

    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++){
        line[i] = c;
    }
    line[i] = '\0';
    return i;
}