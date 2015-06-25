#include <stdio.h>
#include <stdlib.h>


#define swap(a, b) \
    do{\
	if(a != b) \
	{\
	    a = a ^ b;\
	    b = a ^ b;\
	    a = a ^ b;\
	}\
    }while(0)

void
arrange_even_at_even(int *a, int n)
{
    int	    even_idx=0, odd_idx=1;

    if(n %2 != 0)
    {
	printf("# of odds are not equal to evens\n");
	return;
    }

    while(odd_idx <n && even_idx < n)
    {
	while(odd_idx < n && a[odd_idx]%2 != 0)
	    odd_idx+=2;
	while(even_idx < n && a[even_idx] %2 ==0)
	   even_idx+=2;
	swap(a[even_idx],  a[odd_idx]);
    }
}

void
print_array(int *a, int n)
{
    int i=0;
    for(i=0; i<n; i++)
	printf("%d  ", a[i]);

    printf("\n");
}


int
main()
{
    int a[100], n, i;

    printf("# of items : ");
    scanf("%d", &n);

    printf("Items : ");
    for(i=0; i<n; i++)
	scanf("%d", &a[i]);

    printf("Before arrangement : ");
    print_array(a, n);

    arrange_even_at_even(a, n);

    printf("After Arrangement : ");
    print_array(a, n);

    return 0;
}
