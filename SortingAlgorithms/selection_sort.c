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

int
selection_sort(int *a, int n)
{
    int i, j, min;

    for(i=0; i<n-1; i++)
    {
	min = i;
	for(j=i+1; j<n; j++)
	{
	    if(a[j] < a[min])
		min = j;
	}
	swap(a[min], a[i]);
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
    
    selection_sort(a, n);

    print_array(a, n);
    return 0;
}
	
