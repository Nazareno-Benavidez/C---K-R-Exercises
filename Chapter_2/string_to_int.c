#include <stdio.h>

int my_s_to_int(const char s[]);

int main()
{
    char s[10] = { '3', '2', '5', '8', '6', '\0'};

    
    printf("%d", my_s_to_int(s));

    return 0;
}

int my_s_to_int(const char s[])
{
    int i, n;

    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = 10 * n + (s[i] - '0'); //10 * 0 + 3 = 3 -> 3 * 10 + 2 = 32 -> 32 * 10 + 5 = 325 -> 325 * 10 + 8 = 3258 -> 3258 * 10 + 6 = 32586 
    
    return n;
}