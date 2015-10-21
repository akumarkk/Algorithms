#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define DEBUG 1

#define debug(fmt, ...)\
    do{\
        if(DEBUG)\
            fprintf(stdout, "%s(%d) :   " fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__);\
    }while(0)

#define swap(a, b)\
    do{\
        if(a != b) {\
            a = a ^ b;\
            b = a ^ b;\
            a = a ^ b;\
        }\
    }while(0)

int
quick_select(int *a, int start, int end, int k);

void
print_array(int *a, int start, int end)
{
    int i = start;

    printf("\n start = %d   end = %d\n", start, end);
    while(i <= end)
    {
	printf("%d ", a[i]);
	i++;
    }
    printf("\n\n");
}


int
partition(int *a, int low, int high, int median)
{
    int i = low, j = high;

    for(j =low; j<high; j++)
    {
	if(a[j] == median)
	    break;
    }
    swap(a[low], a[j]);

    i = low; 
    j = high;
    int pivot = a[i];

    //print_array(a, low, high);
    while(i < j)
    {
	while((i<=j) && a[i] <= pivot)
	    i++;
	while ( (j>=0) && a[j] > pivot)
	    j--;
	if(i < j)
	    swap(a[i], a[j]);
    }

    swap(a[low], a[j]);
    //print_array(a, low, high);
    printf("pivot index	= %d\n", j);

    return j;
}

int
compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}


int findMedian(int arr[], int n)
{
    qsort(arr, n, sizeof(int), compare);  // Sort the array
    debug("qsort ret = %d", arr[n/2]);
    return arr[n/2];   // Return middle element
}

int
get_median(int *arr, int n)
{
    return quick_select(arr, 0, n-1, n/2);
}

int
quick_select(int *a, int start, int end, int k)
{
    int n = end - start + 1; 
    int i, median[(n+4)/5];

    debug("start = %d	end = %d    k = %d", start, end, k);

    if(start > end || (k > end) || (k < start) || (k <= 0))
	return INT_MAX;

    for (i=0; i<n/5; i++)
	median[i] = findMedian(a + start + i*5, 5);

    if (i*5 < n)
    {
	median[i] = findMedian(a + start + i*5, n%5); 
	i++;
    }

    int medOfMed = get_median(median, i);
    int pivot = partition(a, start, end, medOfMed);

    //if(k < (pivot - start + 1))
#if 0
    if(k < pivot )
       return quick_select(a, start, pivot-1, k);
    else if( k > pivot)
       return quick_select(a, pivot+1, end, k);
    else
	return a[pivot];
#endif

    printf("*** Pivot = [%d]	k = [%d]   pivot - start + 1 = [%d]\n", pivot, k, pivot - start + 1);
	//if(k < (pivot - start + 1))
	if(k < (pivot + 1))
            return quick_select(a, start, pivot-1, k);
        else if( k > (pivot + 1))
            return quick_select(a, pivot+1, end, k);
        else
            return a[pivot];
}

int
main()
{
    int a[100], k, n;
    int ret, i, j;

    while(1)
    {
#if 0
	printf("# of items  :	");
	scanf("%d", &n);

	printf("Items	:   ");
	for(i = 0; i<n; i++)
	    scanf("%d", &a[i]);

	printf("<k>	:   ");
	scanf("%d", &k);

	ret = quick_select(a, 0, n-1, k);
	printf("[%d] smallest element = [%d]\n", k, ret);
#endif
//#if 0
	for(i=1; i<=10; i++)
	{
	    for(j=0; j<10; j++)
	    {
		a[j] = random() % 1000000;
	    }
	    print_array(a, 0, 9);
	    ret = quick_select(a, 0, 9, i);
	    print_array(a, 0, 9);
	    printf("[%d] smallest element = [%d]\n", i, ret);
	}
	break;
//#endif
    }

    return 0;
}
