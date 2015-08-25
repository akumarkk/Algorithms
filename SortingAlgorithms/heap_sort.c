#include <stdio.h>
#include <unistd.h>

#define DEBUGS_ENABLED 1
#define debug(fmt,...)\
    do{\
	if(DEBUG_ENABLE)\
	    fprintf(stdout, "%s(%d) : " fmt, __func__, __LINE__, __VA_ARGS__);\
    }while(0)

#define swap(a, b)\
    do{\
	if(a != b) \
	{\
	    a = a ^ b;\
	    b = a ^ b;\
	    a = a ^ b;\
	}\
    }while(0)

void
print_array(int *a, int n)
{
#ifdef DEBUGS_ENABLED
    for(int i=0; i<n; i++)
        printf("%d  ", a[i]);
    printf("    END %s\n", "");
#endif
}

/* Top down algorithm to heapify() */
int 
heapify(int *a, int start, int end)
{
    int root = start;
    int child;

    while(2*root+1 < end)
    {
	if(2*root+2 < end)
	{
	    child = a[2*root+1] > a[2*root+2] ? 2*root+1 : 2*root+2;
	}
	else
	    child = 2*root+1;

	if(a[root] < a[child])
	{
	    swap(a[root], a[child]);	
	    root = child;
	}
	else
	    break;
    }
    return 0;
}

int
heap_sort(int *a, int n)
{
    int i=0, end;

    for(i=(n-1)/2; i>=0; i--)
	heapify(a, i, n);

    for(end=n-1; end>0; end--)
    {
	swap(a[0], a[end]);
	heapify(a, 0, end);
    }
    return 0;
}


int 
main()
{
    int a[100], n;
    printf("# of items  :   ");
    scanf("%d", &n);

    printf("Items   :   ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    print_array(a, n);
    
    heap_sort(a, n);

    print_array(a, n);
    return 0;
}
