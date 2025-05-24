#include <stdio.h>

#define MAXLINE 1000
#define CUT_N 4

int my_get_line(char line[], char newline[], int maxline, int cut_n);

/* Exercise 1−22. Write a program to ``fold'' long input lines into two or more shorter lines after the last
non−blank character that occurs before the n−th column of input. Make sure your program does something
intelligent with very long lines, and if there are no blanks or tabs before the specified column. */
int main()
{
    int len;
    char line[MAXLINE], newline[MAXLINE];

    while((len = my_get_line(line, newline, MAXLINE, CUT_N)) > 0)
        printf("%s\n", newline);

    return 0;
}

int my_get_line(char line[], char newline[], int maxline, int cut_n)
{
    int c, i, j, k, last_b;
    int next_cut_n = cut_n;
    last_b = k = 0;
    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c !='\n'; i++)
        line[i] = c;

    line[i] = '\0';

    for(j = 0; k < i && j < maxline-1; k++){
        if(line[k] == ' ')
            last_b = j;
        if(j >= next_cut_n){
            if(last_b > 0){
                newline[last_b] = '\n';
            }
            else{
                newline[j] = '\n';
                j++;
            }
            last_b = 0;
            next_cut_n += cut_n;
        }
        if(last_b != j)
            newline[j] = line[k];
        j++;
    }

    newline[j] = '\0';
    return i;
}