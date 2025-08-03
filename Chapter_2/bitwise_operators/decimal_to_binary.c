#include <stdio.h>

// function that prints the binary representation of an integer
void dec_to_bin(int x);

int main()
{
    int x = -64; // example number (can be positive or negative -> both signed and unsigned integers are supported)

    dec_to_bin(x); // call func to print binary representation

    return 0;
}

// function to print the binary representation of an integer
void dec_to_bin(int x)
{
    unsigned int int_bits = sizeof(int) * 8; // number of bits in an int (normally 32)
    unsigned int x_bit; // current bit being printed
    
    // loop over each bit from MSB to LSB
    for(int i = 1; i <= int_bits; i++){
        // right shift the integer so that the current iterated bit is in the LSB position
        // apply a 00000001 mask to clear the rest of the integer and only keep the current iterated bit
        x_bit = (x>>(int_bits-i)) & 1;  
        printf("%u", x_bit); // print extracted bit (0 or 1)

        if(i % 8 == 0) // add a space after every byte
            printf(" ");
    }
    printf("\n"); // newline at the end to keep the output clean
}