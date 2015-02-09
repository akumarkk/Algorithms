#include <stdio.h>
#include <limits.h>

int
main()
{
    printf("MAX SIZE of INT = %lu\n", INT_MAX);
    printf("MAX SIZE of LONG INT = %lu\n", LONG_MAX);

    printf("TWICE INT = %lu\n", (2*INT_MAX));
    printf("HALF LONG INT = %lu\n", (LONG_MAX/2));


    printf("(int)   = %lu\n", sizeof(int));
    printf("(long)  = %lu\n", sizeof(long));
    printf("(long long) = %lu\n", sizeof(long long));
    printf("(short)	= %lu\n", sizeof(short));
    printf("(Double)	= %lu\n", sizeof(double));
    
    
    long var = INT_MAX * INT_MAX;
    printf("INT multiplication = %ld\n", var);
    printf("INT multiplication = %ld\n", (INT_MAX * INT_MAX));

    unsigned long var1 = INT_MAX * INT_MAX;
    printf("INT multiplication = %lu\n", var1);
    return 0;
}
