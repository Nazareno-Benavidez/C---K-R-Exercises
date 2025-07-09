#include <stdio.h>

int u_to_lower(int c);

int main()
{
    int i;
    int c = 65;
    char s[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'g', 'H', 'I', 'J' };
    printf("%c", u_to_lower(c));
    
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            printf("%c", u_to_lower(s[i]));
        else 
            printf("%c", s[i]);
    }


    return 0;
}
int u_to_lower(int c)
{
    if(c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else 
        return c;
}