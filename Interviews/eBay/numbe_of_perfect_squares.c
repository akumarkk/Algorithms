#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int
number_of_perfect_squares(long a, long b)
{
    return (sqrt(b) - sqrt(a) + 1);
}

int
main()
{
    long a, b;
    printf("Range : ");
    scanf("%ld%ld", &a, &b);

    int n = number_of_perfect_squares(a, b);
    printf("Number of perfect squares = %d\n", n);
    return 0;
}
