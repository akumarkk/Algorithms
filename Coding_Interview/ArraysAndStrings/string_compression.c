#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
string_compress(char *str)
{
    int	    len  = strlen(str);
    char    *buf = malloc(len * 2 + 1);
    int	    k=0, i,count;
    char    ch;

    memset(buf, 0, 2*len+1);

    ch = str[0];
    count = 1;
    buf[k++] = str[0];

    for(i=1; i<len; i++)
    {
	if(ch == str[i])
	{
	    count++;
	}
	else
	{
	    /* Warning : Don't forget to add 48. */
	    buf[k++] = 48 + count;
	    ch = str[i];
	    buf[k++] = str[i];
	    count = 1;
	}
    }
    /* Warning : Don't forget to add count of last char */
    buf[k] = 48 + count;

    printf("String [%s]	    Compressed string [%s]\n", str, buf);

    if(strlen(buf) < strlen(str))
	return buf;
    else
	return str;
}

int
main()
{
    char str[256] = {0};

    printf("String  :	");
    scanf("%s", str);
    printf("Compressed string	:   %s\n", string_compress(str));
    return 0;
}
