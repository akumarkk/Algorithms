#include <stdio.h>

int
gcd(int a, int b)
{
    if(b == 0)
	return a;
    else
	return gcd(b, a%b);
}

int
gcd_iterative(int a, int b)
{
    while(b != 0)
    {
	int t = a;
	a = b;
	b = t % b;
    }
    return a;
}

int
main()
{
    int a, b;
    printf("Numbers	:   ");
    scanf("%d%d", &a, &b);

    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("gcd(%d, %d) = %d\n", a, b, gcd_iterative(a, b));

    return 0;
}
