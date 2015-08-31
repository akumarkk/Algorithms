/* Given substring() : Checks wether one is substring of other;
 * Check if s1 is rotation of s2 by calling is_substring() only once
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* Checks if s2 is a sub-string of s1 */
bool
is_sub_string(char *s1, char *s2)
{
    int i=0, j=0, k=0;

   for(k=0; k<strlen(s1); k++)
   {
	while(s1[k] != s2[0] && k<strlen(s1))
	    k++;

        i=k;
	for(j=0; i<strlen(s1) && j<strlen(s2); j++, i++)
	{
	    if(s2[j] != s1[i])
	    {
		printf("s2[%d]=%c is not equal s1[%d]=%c\n", j, s2[j], i, s1[i]);
		break;
	    }
	}

	if(j == strlen(s2))
	    return true;

	/* test sub-string starting next character of s1 */
	k++;
   }

	/* Not all the characters of s2 are part of s1 */
	if(j < strlen(s2))
	{
	    printf("Error ***NOT*** all characters of [%s] are part of [%s] (%d)\n", s2, s1, j);
	    return false;
	}

    return false;
}

bool
is_rotation(char *s1, char *s2)
{
    char *s1s1 = malloc((strlen(s1) * 2) + 1);
    memset(s1s1, 0, (strlen(s1) * 2) + 1);
    strncpy(s1s1, s1, strlen(s1));
    strncat(s1s1, s1, strlen(s1));

    if(strlen(s1) != strlen(s2))
    {
	printf("Two strings should be have equal lengths to be rotations of each other\n");
	return false;
    }
    return is_sub_string(s1s1, s2);
}

int
main()
{
    char s1[512], s2[512];

    printf("s1	:   ");
    scanf("%s", s1);

    printf("s2	:   ");
    scanf("%s", s2);

    if(is_rotation(s1, s2))
	printf("[%s] is a rotation of [%s]\n", s1, s2);
    else
	printf("[%s] is ***NOT*** a rotation of [%s]\n", s1, s2);

    return 0;
}
