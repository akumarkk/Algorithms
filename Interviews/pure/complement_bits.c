#include <stdio.h>
#include <stdlib.h>

int
complement_bit(int n)
{
    int flag = 0;

    int size = 8 * sizeof(int);

    for(int i=size-1; i>=0; i--)
    {
	if( (flag == 0) && ((n>>i)&1) == 1)
	   flag = 1;

	if(flag)
	    n = n ^ (1<<i);
    }

    return n;
}


int
main()
{
    int n;

    while(1)
    {

	printf("Input number : ");
	scanf("%d", &n);

	int m = complement_bit(n);

	printf("Complemented number of %d = %d\n", n, m);
    }
    return 0;
}
