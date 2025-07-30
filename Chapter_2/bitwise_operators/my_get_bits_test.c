#include <stdio.h> 

unsigned int my_get_bits(unsigned int x, int p, int n);

int main()
{
    int x = 63; // 00111111
    int p = 4; // leftmost bit in x -> 00010000
    int n = 3;  // bits to get -> 00011100

    printf("%d", my_get_bits(x, p, n));
    return 0;
}

unsigned int my_get_bits(unsigned int x, int p, int n)
{
    return (x >> (p+1-n)) &~(~0<<n);
    // First part: 00111111 >> (2) = 00001111 | Second part: &~(11111111<<3) = &~(11111000) = & 00000111
    // 00001111 & 00000111 = 00000111  (7 in decimal)
    // first p     second p   return
}