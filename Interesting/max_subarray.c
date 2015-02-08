#include <stdio.h>

int start, end;

int
get_max(int *a, int n)
{
    int i=0, sum=0, maxsum = 0;

    for(i=0; i<n; i++)
    {
	sum = sum + a[i];

	if(maxsum < sum)
	{
	    maxsum = sum;
	    end = i;
	}
	else if(sum < 0)
	{
	    sum = 0;
	    start = i+1;
	}

    }

    return maxsum;
}


int
main()
{
    int a[100], n;
    int flag=1;

    while(flag)
    {
	flag = 0;
	printf("# of items : ");
	scanf("%d", &n);

	printf("ITEMS : ");
	for(int i=0; i<n; i++)
	{
	    scanf("%d", &a[i]);
	}

	int max = get_max(a, n);
	printf("max = %d    start = %d	end = %d\n", max, start, end);
    }
    return 0;
}
