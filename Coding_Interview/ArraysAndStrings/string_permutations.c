#include <stdio.h>
#include <string.h>

int count;

#define swap(a, b)\
    do{\
	if(a != b)\
	{\
	    a = a ^ b;\
	    b = a ^ b;\
	    a = a ^ b;\
	}\
    }while(0)

/* str = abcd
 *
 * Step1 :  swap(a, a)	    swap(a, b),	    swap(a, c)	    swap(a, d)
 * Step2 :  permute(bcd)    permute(acd)    permute(abd)    permute(abc)
 *
 */
void
permutate(char *str, int index, int end)
{
    int i;
    if(index == end)
    {
	printf("[%d]	%s\n", count, str);
       count++;
       return;
    }


    for(i=index; i<=end; i++)
    {
	swap(str[i], str[index]);
	/* Warning : Next index needs to be passed 
	 * Warning : Permute rest of the characters starting index=1
	 */
	permutate(str, index+1, end);
	swap(str[i], str[index]);
    }
}

int
main()
{
    char str[512] = {0};

    printf("String	:   ");
    scanf("%s", str);

    permutate(str, 0, strlen(str)-1);
    return 0;
}
