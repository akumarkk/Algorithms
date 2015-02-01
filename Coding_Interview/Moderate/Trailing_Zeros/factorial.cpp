#include <iostream>
#include <math.h>
using namespace std;

int
factorial(int n)
{
    if(n == 0 || n==1)
	return 1;

    return factorial(n-1) * n;
}


int
main()
{
    int i=0;
    int ret;
    int size = 4 * sizeof(int);
    unsigned long max = 0;
    
    printf("size of int = %d\n", sizeof(int));
    printf("MAX VALUE = %d\n", INT_MAX);

    max = sizeof(int) * 8;
    max = pow(2, max)- 1;
    printf("MAX value = %u\n",max); 

    max = sizeof(int) * 8;
    max = pow(2, max-1) -1;
    printf("Signed max value = %u\n", max);

    size = pow(2, size -1);

    printf("Max integer value = %d\n", size);

    for(i=0; i<=100; i++)
    {
	ret = factorial(i);
	printf("Factorial(%d) = %d\n", i, ret);
    }

    return 0;
}
