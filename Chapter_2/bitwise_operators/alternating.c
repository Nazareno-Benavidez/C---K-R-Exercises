// TO-DO
// CORRECT THIS CODE, MAKE IT WORK
#include <stdio.h>

#define INT_BITS (sizeof(int) * 8)
unsigned int has_alternating_bits(int x);

/* has_alternating_bits(x)
 Return 1 if x has alternating 0s and 1s in binary (e.g., 0b101010...).
*/
int main()
{
    int x = 2863311530;

    printf("%u", has_alternating_bits(x));

    return 0;
}

unsigned int has_alternating_bits(int x)
{
    unsigned int prev_bit = 8;
    unsigned int counter = 0;
    for(int i = INT_BITS-1; i >= 0 && (((unsigned)x>>i)&1)!= prev_bit; i--){
        counter++;
        prev_bit = (x>>i) & 1;
    }
    if(counter == INT_BITS)
        return 1;
    else
        return 0;
}