#include <stdio.h>
 
#define CACHE 256
enum { h_unknown = 0, h_yes, h_no };
unsigned char buf[CACHE] = {0, h_yes, 0};
 
int happy(int n)
{
	int sum = 0, x, nn;

	//printf("Number - %d\n", n);

	if (n < CACHE) {
		if (buf[n])
		{
		  //  printf("n=%d    value= %d\n", n, 2 - buf[n]);
		    return 2 - buf[n];
		}
		buf[n] = h_no;
		//printf("Initialized buf[%d] = %d\n", n, h_no);
	}
 
	for (nn = n; nn; nn /= 10) x = nn % 10, sum += x * x;
 
	x = happy(sum);
	if (n < CACHE) 
	{
	    //printf("n = %d	This is HIT\n", n);
	    buf[n] = 2 - x;
	}
	return x;
}
 
int main()
{
	int i, cnt = 8;
#if 0
	for (i = 1; cnt || !printf("\n"); i++)
		if (happy(i)) --cnt, printf("%d ", i);
 
	printf("The %dth happy number: ", cnt = 1000000);
	for (i = 1; cnt; i++)
		if (happy(i)) --cnt || printf("%d\n", i);
#endif
	for(i=0; i<50000; i++)
	{
	    printf("---------------- ------------\n");
	    if(happy(i) == 1)
		printf("i=%d    happy_number = %d\n", i, happy(i));
	}
	//happy(50);
	printf("i=%d    happy_number = %d\n", 287, happy(287));
	printf("i=%d    happy_number = %d\n", 48, happy(48));
	printf("i=%d    happy_number = %d\n", 1016, happy(1016));

	return 0;
}
