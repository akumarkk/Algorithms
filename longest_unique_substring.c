#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void
refresh_visited(int *visited)
{
    int i;
    for(i=0; i<128; i++)
	visited[i] = false;
}

int 
longest_unique_substring(char *str)
{
    int	    i;
    int	    curr_len = 0, max_len = 0;
    int	    len = strlen(str);
    int	    visited[128] = {0};
    int	    start, prev_start;

    for(i=0; i<len; i++)
    {
	printf("\nprocessing char [%c]\n", str[i]);
	if(visited[str[i]] == true)
	{
	    refresh_visited(visited);
	    visited[str[i]] = true;
	    curr_len = 1;
	    printf("already visited. reset count\n");
	}
	else
	{
	    printf("not visited, adding it to list. curr_len = %d max_len = %d\n", curr_len, max_len);
	    visited[str[i]] = true;
	    curr_len++;
	    if(curr_len > max_len)
	    {
		max_len = curr_len;
		start = i - curr_len + 1;
	    }
	}
    }

    printf("start = %d	max_len = %d\n", start, max_len);
    return max_len;
}

int
main()
{
    char str[1024] = {0};
    while(1)
    {
	printf("<str>	:   ");
	scanf("%s", str);
	longest_unique_substring(str);
    }
    return 0;
}
	

