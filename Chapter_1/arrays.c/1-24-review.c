#include <stdio.h>
#include <stdbool.h>

#define MAXLEN 1000

int len;

void my_get_code(char code[], int maxlen);
void check_tokens(char code[], char opening, char terminating);

int main()
{
    char code[MAXLEN];

    extern int len;

    my_get_code(code, MAXLEN);

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

void check_tokens(char code[], char opening, char terminating)
{
    int i, k, last_token, unmatched_tokens;
    bool matchedToken = false;
    extern int len;

    i = k = last_token = unmatched_tokens = 0;

    for(k = 0; k < len; k++){
        i = k;
        if(code[k] == opening){
            i++;
            while(code[k] == opening && matchedToken == false && i < len){
                if(code[i] == terminating && i > last_token){
                    matchedToken = true;
                    last_token = i;
                }
                else 
                    i++;
            }  
        }
        if(matchedToken == false) 
            unmatched_tokens++;
        matchedToken = false;
    }
}