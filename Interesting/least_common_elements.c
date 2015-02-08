#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
compare(void const *a, void const *b)
{
    if(*(int *)a > *(int *)b)
	return 1;
    else if(*(int *)a < *(int *)b)
	return -1;

    return 0;
}



int
least_common_elements(int *a, int n,
       	int *b, int m, int **comm)
{
    int *common=NULL, k=0, i=0, j=0;

    if(m==0 || n==0)
	return -1;

    if(m > n)
	common = malloc(sizeof(int) * m);
    else
	common = malloc(sizeof(int) * n);

    qsort(a, n, sizeof(int), compare);
    qsort(b, m, sizeof(int), compare);
    printf("Successfully sorted all the elements ...\n");

    while(i<n && j<m)
    {
	if(a[i] == b[j])
	{
	    common[k++] = a[i];
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

    printf("# of common items = %d\n", k);
    *comm = common;

    return k;
}


int
main()
{
    int m, n, a[100], b[100];
    int *common = NULL;

    while(1)
    {
	printf("# of items array1 ");
	scanf("%d", &n);

	printf("Items : ");
	for(int i=0; i<n; i++)
	    scanf("%d", &a[i]);

	printf("# of items array1 ");
	scanf("%d", &m);


	printf("Items : ");
	for(int i=0; i<m; i++)
	    scanf("%d", &b[i]);

	int k = least_common_elements(a, n, b, m, &common);

	printf("LEAST COMMON ELEMENTS : ");
	for(int i=0; i<k; i++)
	    printf("%d  ", common[i]);
	printf("\n");
    }

    return 0;
}
