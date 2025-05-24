#include <stdio.h>

#define MAXLINE 1000
#define CUT_N 80 // Column where lines are cut by a \n | Used CUT_N 4 to debug

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
    int last_b; // Last blank found within the current line
    int next_cut_n = cut_n-1; // Next cut column
    last_b = k = 0;
    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c !='\n'; i++)
        line[i] = c;

    line[i] = '\0';

    // Read line[] and write newline[], separating the former into multiple lines if it's long
    for(j = 0; k < i && j < maxline-1; k++){ // k goes through line[]'s index (reads) - j writes on newline[]'s index 
        if(line[k] == ' ') // A space was found in current line's index being read
            last_b = j; // Last blank is assigned to be newline's current index
        if(j >= next_cut_n){ // When j is at cut column
            if(last_b == j) // If last blank is current newline index, replace it with an '\n'
                newline[j] = '\n';
            else if(last_b > 0){ // If there wasn't a blank at newline's current index but before it, last blank in newline will be '\n'
                newline[last_b] = '\n';
                newline[j] = line[k]; // newline's current index gets the last value of line read (line[k] -> actual value)
            }
            // Cut the current line/word if there wasn't a blank
            else{ // There wasn't a blank in the current line
                newline[j] = '\n'; 
                j++; // Add 1 to j to then write line[k] value
                newline[j] = line[k]; // newline gets the last value of line[] read
            }
            last_b = 0; // Reset last_b value
            next_cut_n += cut_n; // Update next_cut_n
        }
        // Write line[k] value if not at cut column
        else 
            newline[j] = line[k];
        j++;
    }

    newline[j] = '\0'; 
    return i;
}