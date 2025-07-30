#include <stdio.h>

unsigned int clear_effects_status(unsigned char status);
int main()
{
    char status = 169; // 10101001
    
    printf("%d", clear_effects_status(status));

    return 0;
}

unsigned int clear_effects_status(unsigned char status)
{
    return status = status &~077; // 10101001 & 11000000 = 10000000
}