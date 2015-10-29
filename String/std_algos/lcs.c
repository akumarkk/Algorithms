#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lcs[256][256];

int max(int a, int b)
{
    if(a>b)
	return a;
    else
	return b;
}


int
longest_common_subsequence(char *str1, char *str2)
{
    int i, j;
    
    int m = strlen(str1);
    int n = strlen(str2);

    for(i=0; i<m; i++)
	lcs[i][0] = 0;

    for(j=0; j<n; j++)
	lcs[0][j] = 0;

    for(i=1; i<=m; i++)
    {
	for(j=1; j<=n; j++)
	{
	    if(str1[i-1] == str2[j-1])
		lcs[i][j] = lcs[i-1][j-1] + 1;
	    else 
		lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
	}
    }

    return lcs[m][n];
}

char *
lcs_str(int len, char *str1, char *str2)
{
    int i, j;
    int m, n;
    int index = len;
    static char str[256];
    str[len] = '\0';

    m = strlen(str1);
    n = strlen(str2);

    for(i=m; i>0;)
    {
	for(j=n; j>0;)
	{
	    if(str1[i-1] == str2[j-1])
	    {
		str[index-1] = str1[i-1];
		i--;
		j--;
		index--;
	    }
	    else if(lcs[i-1][j] > lcs[i][j-1])
		i--;
	    else
		j--;
	}
    }

    return str;
}

int
main()
{
    int	    ret;
    char    *str;
    char    str1[256], str2[256];

    while(1)
    {
	printf("<str1>	<str2>	:   ");
	scanf("%s%s", str1, str2);
	printf("Strings	:   %s	%s\n", str1, str2);
	ret = longest_common_subsequence(str1, str2);

	printf("lcs(%s, %s) = %d\n", str1, str2, ret);
	str = lcs_str(ret, str1, str2);
	printf("LCS = %s\n", str);
    }
    return 0;
}

