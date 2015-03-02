#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long
power(int x1, int y)
{
    long given = x1;
    long x = x1;
    int i=0;

    if(y == 0)
	return 1;

    for(i=1; ( i<<1 <=y || i+1<=y); )
    {
	if(i<<1 <= y)
	{
	    x = x*x;
	    i= i<<1;
	}
	else
	{
	    x = x * given;
	    i++;
	}
    }

    return x;
}

int
main()
{
    int i;
    long ret;

    for(i=0; i<30; i++)
    {
	ret = power(3, i);

	if(ret == pow(3, i))
	{
	    printf("Correct (3, %d)- %ld\n",i,  ret);
	}
	else
	{
	    printf("INCORRECT - (3, %d)  ret = %ld    pow = %ld\n",i, ret, pow(3, i));
	}
    }

    return 0;
}
