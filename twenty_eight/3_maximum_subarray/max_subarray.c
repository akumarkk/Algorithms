/* Time complexity  :	O(n)
 *  This is an implementation of Kadane's Algorithm
 */
#include <stdio.h>

int start, end;

void
print_array(int *a, int start, int end)
{
    int i;
    for(i=start; i<=end; i++)
	printf("%d  ", a[i]);
    printf("\n");
}


int
max_subarray(int *a, int n)
{
    int	    max_so_far = 0;
    int	    max = 0;
    int	    i;

    for(i = 0; i < n; i++)
    {
	max_so_far = max_so_far + a[i];
	if(a[i] >  max_so_far)
	{
	    max_so_far = a[i];
	    start = i;
	    printf("start = %d	max_so_far = %d\n", start, max_so_far);
	}

	if(max < max_so_far)
	{
	    max = max_so_far;
	    end = i;
	    printf("end = %d max = %d\n", end, max);
	}
    }

    return max;
}

int
main()
{
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, -3, 4, 3};
    int	n = sizeof(a)/sizeof(int);

    print_array(a, 0, n-1);
    int ret = max_subarray(a, n);
    printf("Maximum subarray start = %d	   end = %d	:   %d\n", start, end, ret);
    print_array(a, start, end);

    return 0;
}
