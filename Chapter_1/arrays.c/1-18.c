#include <stdio.h>

#define MAXLINE 1000

/* Exercise 1−18. Write a program to remove trailing blanks and tabs from each line of input, and to delete
entirely blank lines */
int my_get_line(char line[], int maxline);

int main()
{
    char line[MAXLINE];
    int len;

    while((len = my_get_line(line, MAXLINE)) > 0) // While there's another line (len is equal to the length of the line, so if len > 0)
        printf("\n%s\n", line);
}

int my_get_line(char line[], int maxline)
{
    int i, c;

    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    // if (line[i-1] == '\t' || line[i-1] == ' ') This was a wrong solution that only removed 1 tab or blank (the last one).
    //     line[i-1] = '\0';                     
    // else
    //     line[i] = '\0'; 

    while(i > 0 && (line[i-1] == '\t' || line[i-1] == ' ')) // i > 0 because if i = 0, i cannot be -1
        i--;  // line[i-1] is taken because it's the last character of the array, as i is updated after the last for loop cycle.
              // Therefore, the first time it checks if the last valid character(line[i-1]) is a \t or a ' ', then line[(i-1)-1] and so on. 
              /* Finally, i-- to go one character back per execution/cycle. */
    line[i] = '\0'; /* End of array is assigned to the element following the last valid character (not a blank space or a tab). */
    return i;
}