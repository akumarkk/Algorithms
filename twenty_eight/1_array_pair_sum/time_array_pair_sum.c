/* Time complexity  =	O(n logn)
 * Space complexity =	O(1)
 */
#include <stdio.h>
#include <stdlib.h>

int
compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void
array_pair_sum(int *a, int n, int k)
{
    int	    i, j;

    qsort(a, n, sizeof(int), &compare);
    for(i=0, j=n-1; i<j; )
    {
	if(a[i] + a[j] == k)
	{
	    printf("(%d, %d)	=   %d\n", a[i], a[j], k);
	    i++;
	    j--;
	}
	else if((a[i] + a[j]) < k)
	    i++;
	else
	    j--;
    }
}

int
main()
{
    int a[] = {32, 45, 12, 9, 12, 8, 11, 14, 6, 10, 15, 5, 16, 0, 4};
    int n = sizeof(a)/sizeof(int);
    array_pair_sum(a, n, 20);

    return 0;
}

