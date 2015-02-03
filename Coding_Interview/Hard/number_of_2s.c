#include <stdio.h>
#include <string.h>
#include <math.h>

int
count2s_util(int num, int d)
{
    int powerof10 = pow(10, d);
    int nextpow = 10 * powerof10;
    int right = num % powerof10;

    int rdown = num - num % nextpow;
    int rup = rdown + nextpow;

    int digit = (num/powerof10) % 10;
    
    printf("\n -----num = %d	digit = %d-----\n", num, d);
    printf("right   :  %d\n", right);
    printf("rdowb   :	%d\n", rdown);
    printf("rup	    :	%d\n", rup);
    printf("nextpow :	%d\n", nextpow);

    if(digit < 2)
    {
	printf("<2  : %d\n",  rdown/10);
	return rdown/10;
    }
    else if(digit == 2)
    {
	printf("=2  : %d\n", rdown/10 + right + 1);
	return rdown/10 + right + 1;
    }
    else
    {
	printf(">2  : %d\n", rup/10);
	return rup/10;
    }
}

    
int
count2s(int num)
{
    int count = 0;
    char str[512];
    int len= 0;
    snprintf(str, sizeof(str), "%d", num);

    len = strlen(str);

    for(int i=0; i<len; i++)
	count+= count2s_util(num, i);

    printf("Number of 2s in (%d) = %d\n", num, count);

    return count;
}

int
main()
{
    int num = 0;

    while(1)
    {
	printf("\n\nNumber : ");
	scanf("%d", &num);
	printf("Count = %d\n", count2s(num));
    }
    return 0;
}
