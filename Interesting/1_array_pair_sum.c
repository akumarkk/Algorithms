/* Given an array and a number, print all pairs of numbers whose sum is equal to 
 *  the given number.
 *
 *  There are two solutions :
 *  1. O(n log n) time complexity
 *	- sort the array. Maintain two pointers : start and end
 *  2. O (n) time but with O(n) space 
 *	- Maintain hash map for seen number 
 *	- Iterate through each number
 *	    * If the given - number is already present in the seen map, print
 *	    * Else add it to the list
 */

#include <stdio.h>
#include <stdlib.h>

int
compare(const void *a, const void *b)
{
    return ( *(int *)a - *(int *)b );
}


/* Khadane's algorithm */
void
array_pair_sum(int *a, int n, int given)
{
    int i, j;

    qsort(a, n, sizeof(int), compare);

    i= 0;
    j = n-1;
    while(i<j)
    {
	if(a[i] + a[j] == given)
	{
	    printf("(%d, %d)\n", a[i], a[j]);
	    i++;
	    j--;
	}
	else if( (a[i] + a[j]) > given)
	    j--;
	else
	    i++;
    }

    return ;
}

int
main()
{
    int given;
    int a[100], n;

    while(1)
    {
	printf("Key : ");
	scanf("%d", &given);

        printf("Size of array : ");
        scanf("%d", &n);

        printf("Items in array : ");
        for(int i=0; i<n; i++)
            scanf("%d", a+i);

         array_pair_sum(a, n, given);

    }

    return 0;
}

