/* Return index of all the anagrams in a text string */

/* Solution :
 * Modified version of Robin-Karp algorithm 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

int
compare(int *count1, int *count2)
{
    int i;
    for(i=0; i<MAX; i++)
    {
	if(count1[i] != count2[i])
	    return -1;
    }

    return 0;
}

int
index_of_anagrams(char *str, char *pat, int *index)
{
    int i=0, k=0;
    int pcount[MAX] = {0};
    int scount[MAX] = {0};
    int slen = strlen(str);
    int plen = strlen(pat);

    if(plen > slen)
	return -1;

    for(i=0; i<plen; i++)
    {
	pcount[pat[i]]++;
	scount[str[i]]++;
    }

    for(i=plen; i<slen; i++)
    {
	//printf("processing str[%d] = %c\n", i, str[i]);
	if(compare(pcount, scount) == 0)
	{
	    index[k++] = i - plen;
	    printf("Added str[%d] = %c\n", i, str[i]);
	}

	scount[str[i]]++;
	scount[str[i-plen]]--;
    }

    /* Warning : Check for the last window also */
    if(compare(pcount, scount) == 0)
	index[k++] = i;

    return k;
}

int
main()
{
    int i=0, k=0;
    int index[MAX];
    char str[256], pat[256];

    while(1)
    {
	printf("<str> <pat> : ");
	scanf("%s%s", str, pat);
	k = index_of_anagrams(str, pat, index);

	printf("Index of all the anagrams (%d): \n", k);
	for(i=0; i<k; i++)
	    printf("%d  ", index[i]);
	printf("\n");
    }

    return 0;
}
