/* Given 3 strings, check wether 3rd one is an interleaving string of I two.
 * C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.
 */

/* Solution :
 * This is an iterative solution.
 *
 * Limitation:
 * It does not work if there are some characters which are present in both A and B
 * Example : XY XZ  XZXY
 *
 * Time complexity  :
 * O(n) 
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 1
#define debug(fmt, ...)\
    do{\
	if(DEBUG)\
	    fprintf(stdout, "%s(%d):	" fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__);\
    }while(0)


bool
is_interleaving(char *str1, char *str2, char *str3)
{
    int i = 0, j=0, k=0;
    int s1 = strlen(str1);
    int s2 = strlen(str2);
    int s3 = strlen(str3);

    if((s1+s2) != s3)
       return false;

    while(k < s3)
    {
	if(str1[i] == str3[k])
	{
	    i++;
	    k++;
	}
	else if(str2[j] == str3[k])
	{
	    j++;
	    k++;
	}
	else
	{
	    return false;
	}
    }

    return true;
}



int
main()
{
    bool ret;
    char str1[100], str2[100], str3[100];
    while(1)
    {
	printf("Str1	str2	str3	: ");
	scanf("%s%s%s", str1, str2, str3);

	ret = is_interleaving(str1, str2, str3);
	if(ret)
	    printf("[%s] and [%s] are interleaving of [%s]\n", str1, str2, str3);
	else
	    printf("NOT interleaving\n");
    }

    return 0;
}
