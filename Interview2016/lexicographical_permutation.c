#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define swap(a, b)\
    do{\
	if(a != b) {\
	    a = a ^ b;\
	    b = a ^ b;\
	    a = a ^ b;\
	}\
    }while(0)

int
compare(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}



// returns first char which is greater than first, but smallest among all
int
get_ceil(char *str, int start, int end, char first)
{
    int i, min_index, min;
    
    min = str[start];
    min_index = start;
    for(i=start+1; i<=end; i++)
    {
	if(str[i] > first && (str[i]<min))
	{
	    min_index = i;
	    min = str[i];
	}
    }

    return min_index;
}


void
lexicographical_permutation(char *str)
{
    bool    is_finished = false;
    int	    len = strlen(str);
    int	    count = 0, index, i;

    // get first lexicographical string
    qsort(str, len, sizeof(char ), compare);

    count = 1;

    // Get next permutation till we reach the last permutation
    while(is_finished == false)
    {
	printf("count = %d	str  = %s\n", count, str);
	count++;

	// Find the right most char which is greater than next char
	for(i=len-2; i>=0; i--)
	    if(str[i] < str[i+1])
		break;

	if(i < 0)
	    is_finished = true;


	index = get_ceil(str, i+1, len-1, str[i]);
	swap(str[i], str[index]);

	qsort(str+i+1, len-(i+1), sizeof(char), compare);
    }

}

int
main()
{
    char str[1024];

    while(1)
    {
	printf("<str>	    :	    ");
	scanf("%s", str);
	lexicographical_permutation(str);
    }

    return 0;
}

