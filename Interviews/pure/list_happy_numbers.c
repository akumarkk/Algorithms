#include <stdio.h>

#define MAX 256

enum{
    NOT_HP=1,
    HP
};

int buf[MAX]= {0, HP};

int
is_happy_number(int num)
{
    int n = num;
    int sum = 0, x = 0;

    if(num == 1)
	return HP;

    if(num < MAX)
    {
	if(buf[num])
	    return buf[num];

	buf[num] = NOT_HP;
    }

    while(num > 0)
    {
	x = num % 10;
	sum = sum + (x*x);
	num = num/10;
    }

    x = is_happy_number(sum);
    if(n < MAX)
    {
	 buf[n] = x;
    }

    return x;
}

int
main()
{
    int i=0;

    printf("1015 is %d\n", is_happy_number(1015));
    for(i=0; i<50000; i++)
    {
	if(is_happy_number(i) == HP)
	    printf("%d happy number\n", i);
	else
	    printf("%d NOT HAPPY NUMBER\n", i);
    }
//	is_happy_number(1016);
    printf("tryng for 1016...\n");
    printf("1016 is %d\n", is_happy_number(1016));

    return 0;
}

