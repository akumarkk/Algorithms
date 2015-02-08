#include <stdlib.h>
#include <stdio.h>

int
comp(void const *a, void const *b)
{
    if(*(int *)a > *(int *)b)
	return 1;
    else if(*(int *)a < *(int *)b)
	return -1;
}


int
main()
{
    int min, tmp;
    int array[10] = {78, 34, 12, 90, 13, 34, 23, 67, 1, 10};

    qsort(array, sizeof(array)/sizeof(array[0]), sizeof(array[0]), comp);
    for(int i=0; i<10; i++)
	printf("%d   ", array[i]);

    printf("\n");

    int a[] = {78, 34, 12, 90, 13, 34, 23, 67, 1, 10};
    int n = 10;

    for(int i=0; i<n-1; i++)
    {
	min = i;
	for(int j=i+1; j<n; j++)
	{
	    if(a[min] > a[j])
		min = j;
	}
	printf("i=%d  min = %d\n", i, a[min]);

	tmp = a[min];
	a[min] = a[i];
	a[i] = tmp;
    }

    for(int i=0; i<10; i++)
	 printf("%d   ", a[i]);

    printf("\n");
    return 0;
}
