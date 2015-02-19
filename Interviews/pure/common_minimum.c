#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int
compare(const void *a, const void *b)
{
    return (*(int*)a - *(int *)b);
}

int 
common_minimum(int *a, int m, 
	       int *b, int n)
{
    int i=0, j=0, k=0;

    qsort(a, m, sizeof(int), compare);
    qsort(b, n, sizeof(int), compare);

    while(i<m && j<n)
    {
	if(a[i] == b[j])
	{
	    k++;
	    printf("%d ", a[i]);
	    i++;
	    j++;
	}
	else if(a[i] < b[j])
	{
	    i++;
	}
	else
	{
	    j++;
	}
    }
    printf("\n");

    return k;
}

int
main()
{

    int a[] = {23, 34, 12, 32, 90};
    int b[] = {90, 23, 12, 34, 89, 78, 03};

    common_minimum(a, 5, b, 7);

    int a1[] = {90, 34, 12, 56, 1};
    int b1[] = {89, 23, 45, 0, 11, 67};
    common_minimum(a1, 5, b1, 6);

    return 0;
}
