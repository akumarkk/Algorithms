/* Given an array that is sorted and then rotated around an unknown point. Find if array has a pair with given sum ‘x’. It may be assumed that all elements in array are distinct.
 *
 */ 
#include <stdio.h>

int given = 16;

void
print_pairs(int *a, int n)
{
    int left, right;

    for(int i=1; i<n; i++)
    {
	if(a[i] < a[i-1])
	{

	    right = i;
	    left = i-1;
	    printf("left = %d	right = %d\n", left, right);
	    break;
	}
    }

    while(left != right)
    {
	//printf("Comparing (%d, %d)...\n", a[left], a[right]);
	if(a[left] + a[right] == given)
	{
	    printf("(%d, %d) = %d\n", a[left], a[right], given);
	    left = ((left + n) - 1) %n;
	    right = (right + 1) %n;
	}
	else if(a[left] + a[right]  < given)
	    right = (right + 1) %n;
	else
	    left = ((left + n) - 1) %n;
    }

    return;
}

int
main()
{
    int a[100], n;

    while(1)
    {
	printf("# of items : ");
	scanf("%d", &n);

	printf("Elements :");
	for(int i=0; i<n; i++)
	    scanf("%d", &a[i]);
	print_pairs(a, n);
    }

    return 0;
}



