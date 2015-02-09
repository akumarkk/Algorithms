#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
compress(char *str)
{
    int count = 1, i=0, k=0;
    char *buff=NULL;
    int len = strlen(str);

    if(str == NULL || len ==0)
	return;

    buff = malloc(2*len);

    buff[0] = str[0];
    k = 1;
    for(int i=1; i<len; i++)
    {
	if(str[i] == str[i-1])
	    count++;
	else
	{
	    buff[k++] = 48 + count;
	    buff[k++] = str[i];
	    count = 1;
	}
    }

    buff[k++] = 48 + count;

    if(k < len)
	strcpy(str, buff);

    printf("Compressed string : %s\n", buff);
}

int
main()
{
    char str[100] = "";

    while(1)
    {
	printf("String : ");
	scanf("%s", str);

	compress(str);
	printf("Compressed string : %s\n", str);
    }

    return 0;
}

