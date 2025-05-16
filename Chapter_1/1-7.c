#include <stdio.h>
#include <stdbool.h>

int power(int base, int n);
int main()
{
    int c, base, n, result;
    bool operating = true;
    
    while(operating){
        printf("----------- POWERS CALCULATOR -----------\nPlease enter the base.\n");
        while((base = getchar()) != EOF){
            base = getchar();
            base = base - '0';
            if(base >= 0 && base <= 9)
                break;
            else
                printf("Invalid input - NOT A NUMBER.\nEnter the number that you want to use as the base, please.\n");
        }

        printf("Now, enter the exponent, please.\n");
        while((n = getchar())!= EOF){
            n = getchar();
            n = n - '0';
            if(n >= 0 && n <= 9)
                break;
                
            else 
                printf("Invalid input - NOT A NUMBER.\nEnter the exponent, please.\n");
        }
        
        result = power(base, n);
        printf("\nBase = %d\nExponent = %d\nResult = %d", base, n, result);
    }
}
int power(int base, int n){
    int i, p;
    p = 1;
    for(i = 1; i <= n; i++)
        p = p * base;

    return p;
}