#include <stdio.h>
#include <stdbool.h>

#define MAXLEN 1000 // Max code(input) length

int len; // code[] length

void my_get_code(char code[], int maxlen);
void check_tokens(char code[], char opening, char ending);
void check_esc_seq(char code[]);
void check_comments(char code[]);

/* Exercise 1−24. Write a program to check a C program for rudimentary syntax errors like unmatched
parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and
comments. (This program is hard if you do it in full generality.) */
// to solve for comments, where parantheses, brackets, braces, etc, might be unmaatched, create a bool variable "isComment". if(!isComment)
int main()
{
    char code[MAXLEN];

    my_get_code(code, MAXLEN);

    check_tokens(code, '{', '}');
    check_tokens(code, '(', ')');
    check_tokens(code, '[', ']');
    check_tokens(code, '\'', '\'');
    check_tokens(code, '\"', '\"'); 
    check_esc_seq(code);
    check_comments(code);

    return 0;
}

void my_get_code(char code[], int maxlen)
{
    int c;
    
    extern int len;

    for(len = 0; len < maxlen-1 && (c = getchar()) != EOF; len++)
        code[len] = c;
    code[len] = '\0';
}

/* Check for unmatched tokens (like '{' missing '}')
char opening = desired token('(', '{', '[', etc)
char closing = desired token closing (')', '}', ']', etc)
*/
void check_tokens(char code[], char opening, char closing)
{
    int i, k; // 'i' is used to look for a closing token for opening token 'k'  (code[k])
    int last_token = 0; // The position of the last closing token/delimiter found (like, '}', ']', ')')
    int unmatched_tokens = 0; // number of missing closing tokens
    bool matchedToken = false;  
    bool comment = false;

    extern int len; // code[] length

    i = 0;
    for(k = 0; k < len; k++){ 
        i = k; // i gets the current value of k each for iterations
        if(code[k] == '/' && code[k+1] == '/'){
            k+=2;
            while(code[k] != '\n' && k < len)
                k++;
            if(code[k] == '\n'){
                comment = false;
            }
            else
                comment = true;
            i = k;
        }
        else if(code[k] == '/' && code[k+1] == '*'){
            k+=2;
            while((code[k] != '*' && code[k+1] != '/') && k < len)
                k++;
            if(code[k] == '*' && code[k+1] == '/'){
                comment = false;
                k++;
            }
            else
                comment = true;
            i = k;
        }
        // if code[k] is an opening token, look for its closing token
        else if(code[k] == opening && comment == false){ 
            i++; // increase 'i' (read until 'k' closing token index is found)
            // While closing token hasn't been found, increase 'i' until it's found. Else, increase unmatched_tokens, as there's a missing token
            while(code[k] == opening && matchedToken == false && i < len){ 
                if(code[i] == '/' && code[i+1] == '/'){
                    i+=2;
                    while(code[i] != '\n' && i < len)
                        i++;
                    if(code[i] =='\n')
                        comment = false;
                    else 
                        comment = true;
                    k = i;
                }
                 else if(code[i] == '/' && code[i+1] == '*'){
                    i+=2;
                    while((code[i] != '*' && code[i+1] != '/') && i < len)
                        i++;
                    if(code[i] == '*' && code[i+1] == '/'){
                        comment = false;
                        i++;
                    }
                    else
                        comment = true;
                    k = i;
                }
                else if(code[i] == closing && i > last_token){ /* if closing token is found and it's not the previous token found, like: {{ } -> '}' would not be the closing token of the second '{'*/
                    last_token = i; // as current closing token isn't a repeated one, as it's in an index greater than the previous one, update it
                    matchedToken = true; 
                }
                else // No closing token found in current index
                    i++; // increase closing token looking index
            }
            // if no closing token was found for the current token, increase unmatched_tokens by one
            if(matchedToken == false) 
                unmatched_tokens++;
            matchedToken = false; // reset matchedToken regardless of if there was a matchedToken or not
        }
    }
    
    printf("\nNumber of unmatched %c%c tokens: %d\n", opening, closing, unmatched_tokens); // Print the number of missing closing tokens
}
// Check for unmatched escape sequences - e.g -> '\n', '\s'
void check_esc_seq(char code[])
{
    int k;
    int unmatched_esc_seq = 0; // number of unmatched escape sequences
    bool unmatched_esc = false;


    extern int len;

    // Look for escape sequences, then for it's matched closing
    for(k = 0; k < len; k++){
        //if a escape sequence is found ('\')
        if(code[k] == '\'' && code[k+1] == '\\'){
            k+=2; // increase 'k' by 2 to get at escape sequence's type (like n in '\n')
            // if type is valid, escape sequence is matched, unmatched_esc = false
            if(code[k] == 'a' || code[k] == 'b' || code[k] == 'e' || code[k] == 'f' || code[k] == 'n' || code[k] == 'r' 
                || code[k] == 't' || code[k] == 'v' || code[k] == '\\' || code[k] == '\'' || code[k] == '\"' || code[k] == '\?'
                || code[k] == 'x' || code[k] == 'u')
                {
                    unmatched_esc = false;
                }
            // if type not valid -> missing closing token, unmatched_esc = true
            else 
                unmatched_esc = true;
        } 
        // if the escape sequence had a missing closing token, unmatched escape sequences is increased
        if(unmatched_esc == true)
            unmatched_esc_seq++;
        unmatched_esc = false; // unmatched_esc is reseted for new iterations
    }
    printf("\nNumber of unmatched ESCAPE SEQUENCES: %d\n", unmatched_esc_seq); // print the number of unmatched escape sequences
}
// Check for unmatched comments
void check_comments(char code[])
{
    int k;
    int unmatched_comments = 0; // Number of unmatched comments

    extern int len;

    // Check for comments and, if found any, look for its closing tokens 
    for(k = 0; k < len; k++){ 
        // If a comment(/*) is found, look for its end
        if(code[k] == '/' && code[k+1] == '*'){ 
            k+=2;
            while((code[k] != '*' && code[k+1] != '/') && k < len) // get to the end of the comment or to the end of code[] if missing
                k++;
            // if comment has a closing token (end), get past it and iterate over the array again
            if(code[k] == '*' && code[k+1] == '/')
                k+=2; // go to the following index to comment end
            // if comment has no closing token (end) -> unmatched comment
            else { 
                unmatched_comments++;
                break;  // stop iterating over the array, as the rest of it is a whole unmatched comment
            }    
        }
    }
    printf("\nNumber of unmatched COMMENTS: %d\n", unmatched_comments); // Print n of unmatched comments 
}