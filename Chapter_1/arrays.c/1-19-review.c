#include <stdio.h>

#define MAXLINE 1000

int my_get_line(char line[], int maxline);
void reverse_line(char line[], int len);

/* Exercise 1−19. Write a function reverse(s) that reverses the character string s. Use it to write a program
that reverses its input a line at a time. */
int main()
{   
    char line[MAXLINE];
    int len;

    while((len = my_get_line(line, MAXLINE)) > 0){
        reverse_line(line, len);
        printf("%s\n", line);
    }
}

int my_get_line(char line[], int maxline)
{
    int c, i;

    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    while(i > 0 && (line[i-1] == ' ' || line[i-1] == '\t'))
        i--;
    
    line[i] = '\0';
    return i;
}

void reverse_line(char line[], int i)
{
    int temp, j;
    temp = j = 0;

    for(i = i-1; i > 0 && j < i; i--){
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
        j++;
    }
}
