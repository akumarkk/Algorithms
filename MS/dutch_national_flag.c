#include <stdio.h>
#include <string.h>

// Given an array and in index i, rearrange the array in such a way that all the elements
// that are less than a[i] should appear before items that are equal to a[i] and all the
// items that are greater than a[i] should appear right after a[i]
//

#define swap(a, b)\
    do{\
	if(a != b){\
	    a = a ^ b;\
	    b = a ^ b;\
	    a = a ^ b;\
	}\
    }while(0)

void
print_array(int *a, int n)
{
    int i;
    for(i=0; i<n; i++)
	printf("%d ", a[i]);
    printf("\n");
}

void
dutch_national_flag(int *a, int n, int mid)
{
    int smaller = 0, larger = n-1, curr = 0;
    int pivot = a[mid];

    while(curr <= larger)
    {
	if(a[curr] < pivot)
	{
	    swap(a[curr], a[smaller]);
	    smaller++;
	    curr++;
	}
	else if(a[curr] > pivot)
	{
	    swap(a[curr], a[larger]);
	    larger -= 1;
	}
	else
	{
	    // equals, move to the next element
	    curr++;
	}
    }

    printf("Dutch National Flag :   ");
    print_array(a, n);
}

int
main()
{
    int a[256], n;
    int i;

    while(1)
    {
	printf("# of items : ");
	scanf("%d", &n);

	for(i=0; i<n; i++)
	    scanf("%d", &a[i]);

	print_array(a, n);
	dutch_national_flag(a, n, 3);
    }

    return 0;
}
