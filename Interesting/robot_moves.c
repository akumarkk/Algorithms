#include <stdio.h>
#include <stdbool.h>

typedef enum {
    EAST, 
    SOUTH, 
    WEST,
    NORTH
}dir_t;

bool
is_circular(char *str)
{
    int i=0;
    int x=0, y=0;
    dir_t   dir;

    while(str[i] != '\0')
    {
	if(str[i] == 'L')
	    dir = (dir - 1) % 4;
	else if(str[i] == 'R')
	    dir = (dir + 1) % 4;
	else if(str[i] == 'G')
	{
	    if(dir == EAST)
		x++;
	    else if(dir == WEST)
		x--;
	    else if(dir == SOUTH)
		y--;
	    else if(dir == NORTH)
		y++;
	}
	i++;
    }

    return (x==0 && y==0);
}


int
main()
{
    char str[100] = "";

    while(1)
    {
	printf("Direction : ");
	scanf("%s", str);

	printf("%s is_circular %d\n", str, is_circular(str));
    }
    return 0;
}

