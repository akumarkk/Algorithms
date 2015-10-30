#include <stdio.h>
#include <stdlib.h>

void
print_array(int *a, int n)
{
    int i;
    for(i=0; i<n; i++)
	printf("%d ", a[i]);

    printf("\n");
}


int
maximum_repeating_num(int *a, int n, int k)
{
    int i;
    int max;
    int index;

    for(i=0; i<n; i++)
    {
	a[a[i]%k] += k;
    }

    max = a[0]; index = 0;
    for(i=1; i<n; i++)
    {
	if(a[i] > max)
	{
	    index = i;
	    max = a[i];
	}
    }

    print_array(a, n);

    for(i=0; i<n; i++)
	a[i] = a[i] %k;

    print_array(a, n);
    printf("Index = %d	max = %d    max = %d\n", index, max, max%k);
    return index;
}

int
main()
{
    int a[] = {2, 3, 3, 5, 3, 4, 1, 7};
    int n = sizeof(a)/sizeof(a[0]);
    int ret;
    int k = 8;
    
    ret = maximum_repeating_num(a, n, k);
    printf("Max repeating = %d\n",ret);

    return 0;
}
