#include <stdio.h>

#define MAXLEN 1000

void my_get_code(char code[], char newcode[], int maxlen);

/* Exercise 1−23. Write a program to remove all comments from a C program. Don't forget to handle quoted
strings and character constants properly. C comments don't nest. */
int main()
{
    char code[MAXLEN]; // code with comments
    char newcode[MAXLEN]; // code without comments

    my_get_code(code, newcode, MAXLEN);

    printf("\n%s\n", newcode);

    return 0;
}

void my_get_code(char code[], char newcode[], int maxlen)
{
    int c, i, k, j;
    j = 0;

    // Write code[]
    for(i = 0; i < maxlen-1 && (c = getchar()) != EOF; i++)
        code[i] = c;
    code[i] = '\0';

    // Read code[] and write it in newcode[] removing comments
    for(k = 0; k < i  && j < maxlen-1; k++){// k = read variable (reads through code[]) j = write variable (writes code[k] value in newcode[])
        // if double '/' comment is encountered, remove everything from the first '/' to '\n' (end of comment)
        if(code[k] == '/' && code[k+1] == '/'){
            // Find end of comment
            while(code[k] != '\n') 
                k++;
            newcode[j] = code[k]; // Write '\n' in newcode[], omitting the whole comment
        }
        // Else if '/* */' comment is encountered, remove everything from "/*" to "*/" (end of comment)
        else if(code[k] == '/' && code[k+1] == '*'){
            k+=2; // get past "/*"
            // Find end of comment
            while((code[k] != '*' && code[k+1] != '/')) // while not at "*/"
                k++;
            k+=2; // get at code[*/ + 1]
            newcode[j] = code[k]; // Write next code[]'s value after the end of the comment
        }
        // If not a comment
        else    
            newcode[j] = code[k]; // Write code[]'s value into newcode[]
        j++;
    }
} 