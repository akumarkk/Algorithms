#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool
is_anagram_string(char *target, char *str)
{
    int scount[128] = {0};
    int tcount[128] = {0};
    int i, j, k;
    int slen = strlen(str);
    int tlen = strlen(target);

    //printf("len of empty string = %d\n", strlen(NULL));

    for(i=0; i<128; i++)
    {
	scount[i] = tcount[i] = 0;
    }

    for(i=0; i<tlen; i++)
    {
	tcount[target[i]]++;
	scount[str[i]]++;
    }

    for(i=tlen; i<=slen;i++ )
    {
	printf("processing char = %c\n", str[i]);
	for(k=0; k<128; k++)
	{
	    if(scount[k] != tcount[k]){
		printf("k = %d	scount = %d  count = %d\n", k, scount[k], tcount[k]);
		break;
	    }
	}
	if(k == 128)
	    return true;

	scount[str[i-tlen]]--;
	scount[str[i]]++;
    }

    return false;
}

int
main()
{
    char target[256], str[256];

    while(1)
    {
	printf("<target>    <str>   :	");
	scanf("%s%s", target, str);

	printf("ret = %d\n", is_anagram_string(target, str));
    }
    return 0;
}
