#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long
count_ways(int n)
{
    if(n < 0)
	return 0;
    if(n == 0)
	return 1;
    return count_ways(n-1) + count_ways(n-2) + count_ways(n-3);
}

long
count_dp(int n)
{
    int i;
    int *mem = malloc(sizeof(int ) * n+1);
    mem[0] = 1;
    mem[1] = 1;
    mem[2] = 2;

    for(i=3; i<=n; i++)
	mem[i] = mem[i-1] + mem[i-2] + mem[i-3];

    return mem[n];
}

int
main()
{
    int i;

    for(i=0; i<35; i++)
    {
	printf("Recursion count =   %ld\n", count_ways(i));
	printf("DP count	=   %ld\n", count_dp(i));
    }

    return 0;
}
