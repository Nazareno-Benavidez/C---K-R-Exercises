#include <stdio.h>

#define MAXLINE 1000

int my_get_line(char line[], int maxline);
void reverse_line(char line[], int len); // int len will be the length of the line, literally i in my_get_line 

/* Exercise 1−19. Write a function reverse(s) that reverses the character string s. Use it to write a program
that reverses its input a line at a time. */
int main()
{
    char line[MAXLINE];
    int len;

    while((len = my_get_line(line, MAXLINE)) > 0){ // while there's another line
        reverse_line(line, len); // reverse_line gets line and the value of len
        printf("%s\n", line);
    }
}

int my_get_line(char line[], int maxline)
{
    int c, i;

    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    while(i > 0 && (line[i-1] == '\t' || line[i-1] == ' ')) //
        i--;

    line[i] = '\0';
    return i;
}

void reverse_line(char line[], int i)
{
    int temp; // temp is used to store temporary values
    int j; // j is the start of the array, as it value is then initialised to 0
    temp = j = 0; // variables initialisation

    /* for loop that swaps pairs of characters 
    i = variable length = last character = last character - 1 -> that is done not to swap the '\0' character;
    i(array end) is decreased every iteration of the loop and j(array start) is increased
    j cannot be greather than i (j < i) because it would be swapping already swapped indexes or just one index with itself(j = i) */
    for(i = i-1; i > 0 && j < i; --i){ 
        temp = line[i]; // temp stores the value of the element in line of index i (current value of i)
        line[i] = line[j]; // line[i] changes to line[j], meaning that line[i]'s value is now the value of line[j]
        line[j] = temp; // line[j] gets the initial value of line[i], stored in temp
        j++; // j is increased
    }
}