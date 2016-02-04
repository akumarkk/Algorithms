#include <stdio.h>
#include <stdlib.h>


int
gcd_mod(int a, int b)
{
    if(b == 0)
        return a;
    return gcd_mod(b, a%b);
}

int
gcd_imod(int a, int b)
{
    int tmp;
    while(b!= 0)
    {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}


int
main()
{
    printf("Modulus GCD(10, 4) = %d\n", gcd_mod(10, 4));
    printf("Iterative Modulus GCD(10, 4) = %d\n", gcd_imod(10, 4));
    printf("Modulus GCD(10, 4) = %d\n", gcd_mod(4, 10));
    printf("Iterative Modulus GCD(10, 4) = %d\n", gcd_imod(4, 10));

    return 0;
}
