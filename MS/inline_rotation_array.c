#include <stdio.h>
#include <stdlib.h>

void
reverse(int *a, int start, int end)
{
    int temp;
    int i = start;
    int j = end;
    
    while(i <= j)
    {
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	i++; 
	j--;
    }
}

void
inline_rotation_array(int *a, int n, int k)
{
    reverse(a, 0, n-1);
    reverse(a, 0, k-1);
    reverse(a, k, n-1);
}

void
print_array(int *a, int n)
{
    int i;
    for(i=0; i<n; i++)
	printf("%d ", a[i]);
    printf("\n");
}


int
main()
{
    int k;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    for(k=1; k<6; k++)
    {
	inline_rotation_array(a, 10, k);
	printf("k = %d\n", k);
	print_array(a, 10);
    }

    return 0;
}
