/* Given an array of integers of the size of n, it contains zeros in random positions, we need to move all zeros to end of the array in a single scan without extra space. 
 */

#include <stdio.h>
#include <stdlib.h>

void
print_array(int *a, int n)
{
    int i;
    for(i=0; i<n; i++)
	printf("%d ", a[i]);
    printf(" END\n");
}


void
move_zero_to_end(int *a, int n)
{
    int	i;
    int	k = 0;
    int	count = 0;

    for(i=0; i<n; i++)
    {
	if(a[i])
	    a[k++] = a[i];
	else
	    count++;
    }

    for(i=n-1; count>0; count--, i--)
	a[i] = 0;
}

int
main()
{
    int n;
    int a[] = {1, 2, 3, 0, 0, 12, 34, 0 , 34, 11, 0, 56, 0};
    
    n = sizeof(a)/sizeof(int);
    print_array(a, n);
    move_zero_to_end(a, sizeof(a)/sizeof(int));
    print_array(a, n);

    return 0;
}
