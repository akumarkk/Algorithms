/* Recursive/DP solution works for overlapping characters also 
 *
 * Matrix[i, j] indicates the string formed by taking 
 *	first 'i' characters from string1 and
 *	first 'j' characters from string2
 *  This is set to "TRUE" if this string is interleaving.
 *
 *  Example : (2, 1) indicates 2 chars from string1 and 1 char from string2 in any order :
 *	o 1(string1), 1(string2) and 1(string1)
 *	o 2(string1) and 1(string1)
 *	o 1(string2) 2(string1)
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool
is_interleaving_recursive(char *str1, char *str2, char *str3)
{
    if(*str1 == '\0' && *str2 == '\0' && *str3 == '\0')
	return true;

    // str3 is shorter than str1 + str2
    if(*str3 == '\0')
	return false;

    return ((*str1 == *str3 && is_interleaving_recursive(str1+1, str2, str3+1)) ||
	    (*str2 == *str3 && is_interleaving_recursive(str1, str2+1, str3+1)));
}

bool matrix[100][100];

void
print_matrix(int s1, int s2, bool *matrix)
{
   int i, j;

  for(i=0; i<s1; i++)
  {
     for(j=0; j<s2; j++)
     {
	printf("%d ", *(matrix + (s2*i) + j));
     }
     printf("\n");
  }
}

void
print_matrix2(int s1, int s2)
{
   int i, j;

  for(i=0; i<=s1; i++)
  {
     for(j=0; j<=s2; j++)
     {
	printf("%d ", matrix[i][j]);
     }
     printf("\n");
  }
}
     
bool
is_interleaving_dp(char *str1, char *str2, char *str3)
{
    int s1 = strlen(str1);
    int s2 = strlen(str2);
    int s3 = strlen(str3);
    //bool matrix[s1+1][s2+1];
    int i, j;

    if(s3 != (s1+s2))
	return false;

    memset(matrix, false, sizeof(int)*(s1+1)*(s2+1));

    for(i=0; i<=s1; i++)
    {
	for(j=0; j<=s2; j++)
	{
	    // both the strings are empty
	    if(i==0 && j==0)
		matrix[i][j] = true;
	    
	    // str1 is empty 
	    else if(i==0 && str2[j-1] == str3[j-1])
		matrix[i][j] = matrix[i][j-1];

	   // str2 is empty
	    else if(j==0 && str1[i-1] == str3[i-1])
	       matrix[i][j] = matrix[i-1][j];

	    // if both curr char of str1 and str2 matches
	    else if(str1[i-1] == str3[i+j-1] && str2[j-1] == str3[i+j-1])
		matrix[i][j] = matrix[i-1][j] || matrix[i][j-1];

	    // If only one matches
	    else if(str1[i-1] == str3[i+j-1])
		matrix[i][j] = matrix[i-1][j];

	    else if(str2[j-1] == str3[i+j-1])
		matrix[i][j] = matrix[i][j-1];

	    if(i==s1 && j==s2)
	    {
		printf("Setting matrix[%d][%d] to %d\n", i, j, matrix[i][j]);
	    }
	}
    }

    print_matrix(s1+1, s2+1, (bool *)matrix);
    print_matrix2(s1, s2);

    printf("matrix[%d][%d] = %d\n", s1, s2, matrix[s1][s2]);
    return matrix[s1][s2];
}

int
main()
{
    bool ret;
    char str1[100], str2[100], str3[100];
    while(1)
    {
        printf("\n\nStr1    str2    str3    : ");
        scanf("%s%s%s", str1, str2, str3);

        ret = is_interleaving_recursive(str1, str2, str3);
        if(ret)
            printf("\n[%s] and [%s] are interleaving of [%s]\n", str1, str2, str3);
        else
            printf("\nNOT interleaving\n");

        ret = is_interleaving_dp(str1, str2, str3);
        if(ret == true)
            printf("[%s] and [%s] are interleaving of [%s]\n", str1, str2, str3);
        else
            printf("NOT interleaving\n");
    }

    return 0;
}
