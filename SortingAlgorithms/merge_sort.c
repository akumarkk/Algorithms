#include <stdio.h>
#include <stdlib.h>

#define DEBUGS_ENABLED 0 

void
print_array_n(int *a, int from, int to);

#define debug(fmt, ...)\
    do{\
	if(DEBUGS_ENABLED)\
	    fprintf(stdout, "%s(%d) : " fmt, __FUNCTION__, __LINE__, __VA_ARGS__);\
    }while(0)


#define swap(a, b) \
    do{\
        if(a != b)\
        {\
            a = a ^ b;\
            b = a ^ b;\
            a = a ^ b;\
        }\
    }while(0)


int merge(int *a, int low, int mid, int high)
{
    int k=0, count=0;
    int i=low, j=mid+1;
    int temp[100];

    debug("BEFORE :	%s", "");
    print_array_n(a,low, high);
    while(i<=mid && j <= high)
    {
	if(a[i] < a[j])
	    temp[k++] = a[i++];
	else
	    temp[k++] = a[j++];
    }

    for(count=i; count<=mid; count++)
	temp[k++] = a[count];

    for(count=j; count<=high; count++)
	temp[k++] = a[count];

    for(i=low, j=0; j<k; i++, j++)
	a[i] = temp[j];

    debug("(%d, %d) and (%d, %d)\n", low, mid, mid+1, high);
    debug("AFTER :	%s", "");
    print_array_n(a,low, high);

    return 0;
}

void
print_array_n(int *a, int from, int to)
{
#ifdef PRINT_DEBUGS_ENABLED
    int i=0;
    for(i=from; i<=to; i++)
    {
	printf("%d  ", a[i]);
    }
    printf("------ END --------%s\n", "");
#endif
}

int
merge_sort(int *a, int low, int high)
{
    if(low < high)
    {
	int mid = (low+high)/2;
	merge_sort(a, low, mid);
	merge_sort(a, mid+1, high);
	merge(a, low, mid, high);
    }

    return 0;
}

void
print_array(int *a, int n)
{
#ifdef DEBUGS_ENABLED
    for(int i=0; i<n; i++)
        printf("%d  ", a[i]);
    printf("    END %s\n", "");
#endif
}

int
main()
{
    int a[100], n;
    printf("# of items  :   ");
    scanf("%d", &n);

    printf("Items   :	");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    print_array(a, n);
    merge_sort(a, 0, n-1);
    print_array(a, n);
    
    return 0;
}
