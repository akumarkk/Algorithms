/* Transform One String to Another using Minimum Number of Given Operation
 * Given two strings A and B, the task is to convert A to B if possible. The only operation allowed is to put any character from A and insert it at front. Find if it’s possible to convert the string. If yes, then output minimum no. of operations required for transformation.
 *
 * Input:  A = "ABD", B = "BAD"
 * Output: 1
 * Explanation: Pick B and insert it at front.
 *
 * Input:  A = "EACBD", B = "EABCD"
 * Output: 3
 * Explanation: Pick B and insert at front, EACBD => BEACD
 *              Pick A and insert at front, BEACD => ABECD
 *                           Pick E and insert at front, ABECD => EABCD
 *
 */

/* Solution :
 * 1. Atmost we need strlen(str1) operations to convert one string into another
 * 2. If the curr character in B does not match, increment "res" till it matches
 * 3. "res" indicates number of characters that needs to be moved to front of current char in 'A'
 */
#include <stdio.h>
#include <string.h>

int
min_op_convert_string(char *str1, char *str2)
{
    int	res = 0, j, i;
    int	count[256] = {0};
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for(i=0; i<len1; i++)
	count[str1[i]]++;

    for(i=0; i<len2; i++)
	count[str2[i]]--;

    for(i=0; i<256; i++)
	if(count[i])
	    return -1;

    for(i=len1-1, j=len2-1; i>=0; )
    {
	while(i>=0 && str1[i] != str2[j])
	{
	    res++;
	    i--;
	}

	// We found a match
	if(i>=0)
	{
	    i--;
	    j--;
	}
    }

    return res;
}

int
main()
{
    char str1[100], str2[100];

    while(1)
    {
	printf("STR1	STR2	:   ");
	scanf("%s%s", str1, str2);
	int res = min_op_convert_string(str1, str2);
	printf("Min # of operations  = %d\n", res);
    }
    return 0;
}
