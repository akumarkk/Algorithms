#include <stdio.h>
#include <string.h>

int table[100];

int
max(int a, int b)
{
    if(a > b)
	return a;
    else
	return b;
}


void
preprocess(char *pat, int *table)
{
    int i;
    for(i=0; i<strlen(pat); i++)
    {
	table[pat[i]] = i;
    }
}


int
boyer_moor(char *text, char *pat, int *index)
{
    int	k = 0;
    int i = 0;
    int j = 0;

    int tlen = strlen(text);
    int plen = strlen(pat);

    if(plen > tlen)
	return k;

    preprocess(pat, table);

    while(i+ plen <= tlen)
    {
	j = plen - 1;

	// compare char from end
	while(j>=0 && text[i+j] == pat[j])
	    j--;

	// All the chars have been matched
	if(j < 0)
	{
	    index[k++] = i;
	    // Align window so that next char is aligned with correct position w.r.t pattern
	    i = i + max(1, plen - table[text[i+plen]]);
	}
	else
	{
	    // All char have not been matched
	    // So align in such a way that this mis-matched char should correct align
	    i = i + max(1, j - table[text[i+j]]);
	}

    }
    
    return k;
}

int
main()
{
    char text[1024] = "", pat[256] = "";
    int  i, k, index[100];

    while(1)
    {
	printf("<text> <pat>	:   \n");
	scanf("%s%s", text, pat);
	k = boyer_moor(text, pat, index);

	for(i=0; i<k; i++)
	{
	    printf("%s found at index(%d) = %s\n", pat, index[i], text + index[i]);
	}
    }

    return 0;
}
