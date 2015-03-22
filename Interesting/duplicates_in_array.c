#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int size;

int *
get_duplicates(int *a, int n)
{
    if(a == NULL || n <= 1)
	return NULL;

   // static int res[n];
   // This is not allowed by C std.
   int *res = malloc(sizeof(int) * n);
    int k =0;
    

    for(int i=0; i<n; i++)
    {
	if(a[ abs(a[i]) ] > 0)
	    a[a[i]] = - a[a[i]];
	else
	    res[k++] = abs(a[i]);
    }
    size = k;

    return res;
}


int
main()
{
    int a[100], n;

    while(1)
    {
	printf("Size of array : ");
	scanf("%d", &n);

	printf("Items in array : ");
	for(int i=0; i<n; i++)
	    scanf("%d", a+i);

	int *res = get_duplicates(a, n);

	printf("Duplicate elements : ");
	for(int i=0; i<size; i++)
	    printf("%d   ", res[i]);

	printf("\n");
    }

    return 0;
}
