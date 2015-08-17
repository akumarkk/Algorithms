#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) \
    do{\
        if(a != b)\
        {\
            a = a ^ b;\
            b = a ^ b;\
            a = a ^ b;\
        }\
    }while(0)


int partition(int *a, int low, int high)
{
    int     pivot = a[low];
    int     i = low, j=high;

    while(i < j)
    {
        while(a[i] <= pivot)
            i++;
        while(a[j] > pivot)
            j--;

        if(i < j)
            swap(a[i], a[j]);
    }

    swap(a[j], a[low]);
    return j;
}

int
quick_sort(int *a, int low, int high)
{
    int j=0;

    if(low < high)
    {
        j = partition(a, low, high);
        quick_sort(a, low, j-1);
        quick_sort(a, j+1, high);
    }
    return 0;
}

void
print_array(int *a, int n)
{
    for(int i=0; i<n; i++)
        printf("%d  ", a[i]);
    printf("    END\n");
}

int
main()
{
    int a[100], n;
    printf("# of items  :   ");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    print_array(a, n);
    quick_sort(a, 0, n-1);
    print_array(a, n);
    
    return 0;
}
