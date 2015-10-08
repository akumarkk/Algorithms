/* If current digit is smaller than right, find a smallest digit that is greater than current
 *  and append that first 
 *  append rest of the digits in sorted order
 */

#include <stdio.h>
#include <string.h>

#define MAX 256

#define swap(a, b) \
    do{\
	if(a != b){\
	    a = a ^ b;\
	    b = a ^ b;\
	    a = a^ b;\
	}\
    }while(0)

#define DEBUG 1
#define debug(fmt, ...)\
    do{\
	if(DEBUG)\
	    fprintf(stdout, "%s(%d) :	" fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__);\
    }while(0)


void
print_array(char *array, int n)
{
    int i;
    
    for(i=0; i<n; i++)
	printf("%d ", array[i]);
    printf("\n");
}


int
sort(char *array, int n)
{
    int count[10] = {0}, cnt, k=0, i = 0;

    for(i=0; i<n; i++)
    {
	count[array[i] - '0']++;
    }

    for(i=0; i<n; i++)
    {
	cnt = count[i];
	while(cnt)
	{
	    array[k++] = '0' + i;
	    cnt--;
	}
    }

    return 0;
}

int
next_higher_num(int num)
{
    char digit[MAX] = "";
    int  min = 0, k, curr, right, i;
    int  small, smallest;

    digit[0] = num % 10;
    num = num / 10;
    k = 1;

    while(num)
    {
	right = digit[k-1];
	curr = num % 10;
	digit[k++] = curr;
	num  = num / 10;

	debug("processing digit [%d]	min = [%d]", curr, digit[min]);
	if(right > curr)
	{
	    break;
	}
    }

    if(num == 0 && k == 1)
	return 0;

    debug("# items to sort = %d", k);
    debug("curr = %d", curr);

    // Increasing order
    sort(digit, k);
    printf("Sorted array    :	\n");
    print_array(digit, k);

    // Find a number that is greater than curr, but smallest among all
    smallest = k-1;
    for(i=k-1; i>=0; i--)
    {
	if(digit[i] > curr && digit[i] <= digit[smallest])
	    smallest = i;
    }

    small = digit[smallest];
    debug("small item = %d", small);

    for(i=smallest; i<k-1; i++)
	digit[i] = digit[i+1];

    debug("num is %d", num);
    debug("Sorted array : %s", "");
    
    for(i=0; i<k; i++)
    {
	printf("%d ", digit[i]);
    }

    num = num * 10;
    num = num + small;

    for(i=0; i<k-1; i++)
    {
	debug("num = %d", num);
	num = num * 10;
	num = num + (digit[i]);
    }

    return num;
}

int
main()
{
    int num, high;

    while(1)
    {
	printf("Number	:   ");
	scanf("%d", &num);

	high = next_higher_num(num);
	printf("Next higher number  :	%d\n", high);
    }

    return 0;
}
