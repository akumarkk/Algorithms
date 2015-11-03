#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int
kadane(int *a, int n)
{
    int i, sum, max_sum, max_sum2;
    int j, start = 0, end = 0;

    sum = max_sum = a[0];
    for(i=1; i<n; i++)
    {
	sum += a[i];
	if(sum < 0)
	{
	    if(i+1 < n)
		start = i+1;
	    sum = 0;
	}

	if(max_sum < sum)
	{
	    end = i;
	    max_sum = sum;
	}
    }

    printf("max sum = %d    startIndex = %d	endIndex = %d\n", max_sum, start, end);

    i = 0;
    j = start = end + 1;
    end = j;
    max_sum2 = 0;
    while(i < n)
    {
	sum += a[j];
	if(sum < 0)
	{
	    if(i+1 < n)
		start = j;
	    sum = 0;
	}

	if(max_sum2 < sum)
	{
	    end = j;
	    max_sum2 = sum;
	}
	i++;
	j = (j+1)%n;
    }
    printf("max sum = %d    startIndex = %d	endIndex = %d\n", max_sum2, start, end);

    return max_sum2;
}


int
main()
{
    int a[] =  {11, 10, -20, 5, -3, -5, 8, -13, 10};
    int n = sizeof(a)/sizeof(a[0]);
    
    kadane(a, n);
    return 0;
}
