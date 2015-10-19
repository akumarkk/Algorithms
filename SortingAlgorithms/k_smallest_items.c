/* use max-heap to return kth smallest item
 *  1. Build Max-heap with k elements
 *  2. if k+i th item is smaller than root of MH. Replace MH root with (k+i)th element
 *
 *  Root of the MH is the kth smallest item
 *
 *  Complexity :
 *	- For constructing Heap Tree for the first time, it takes O(n)
 *	- For Heapifycation, it takes O(log n)
 */
#include <stdio.h>
#include <stdlib.h>


#define DEBUG 1

#define debug(fmt, ...)\
    do{\
	if(DEBUG)\
	    fprintf(stdout, "%s(%d) :	" fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__);\
    }while(0)

#define swap(a, b)\
    do{\
	if(a != b) {\
	    a = a ^ b;\
	    b = a ^ b;\
	    a = a ^ b;\
	}\
    }while(0)

void
print_array(int *a, int n);

int
heapify(int *a, int start, int end);

int
build_heap_tree(int *a, int start, int end)
{
    int i;
    debug("Before heap_tree :	%s", "");
    print_array(a, end);
    for(i=(end-1)/2; i>=0; i--)
    {
	debug("Heapify with parent [%d]", i);
	heapify(a, i, end);
    }
    debug("After heap_tree :	%s", "");
    print_array(a, end);

    return 0;
}

int
heapify(int *a, int start, int end)
{
    int max_child;
    int lchild, rchild;

    /* Warning : check for left child 2*start + 1 < end condition */
    while(( (2*start) + 1) < end)
    {
	lchild = 2 * start + 1;
	rchild = 2 * start + 2;

	if(rchild < end && (a[rchild] > a[lchild]))
	    max_child = rchild;
	else
	    max_child = lchild;

	if(a[max_child] > a[start])
	{
	    swap(a[max_child], a[start]);
	    start = max_child;
	}
	else
	    break;
    }
    return 0;
}

void
print_array(int *a, int n)
{
    int i = 0;

    while(i < n)
	printf("%d ", a[i++]);
    printf("-------    END    ---------\n\n");
}

int
k_select(int *a, int n, int k)
{
    int tmp;

    build_heap_tree(a, 0, k);
    print_array(a, k);

    tmp = k;
    while(tmp < n)
    {
	debug("processing [%d]", a[tmp]);
	if(a[0] > a[tmp])
	{
	    debug("root = %d	curr = %d", a[0], a[tmp]);
	    swap(a[0], a[tmp]);
	    debug("Swapped root = [%d] and curr = [%d]", a[0], a[tmp]);
	    heapify(a, 0, k);
	}
	print_array(a, k);
	tmp++;
    }

    print_array(a, k);
    /* Warning : Kth smallest element is always the root in Max heap of k elements */
    return a[0];
}

int
main()
{
    int i;
    int ret = 0;
    int a[100], n , k;

    while(1)
    {
	printf("# of items  :	");
	scanf("%d", &n);

	printf("Items	:   ");
	for(i=0; i<n; i++)
	    scanf("%d", &a[i]);

	printf("<k>	:   ");
	scanf("%d", &k);

	printf("Before	;   ");
	print_array(a, n);

	ret = k_select(a, n, k);
	
	printf("kth smallest element = [%d]\n", ret);
    }

    return 0;
}

