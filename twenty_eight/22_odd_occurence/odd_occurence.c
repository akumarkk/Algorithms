#include <stdio.h>
#include <string.h>

int
odd_occurence(int *array, int n)
{
    int i;
    int num = array[0];

    for(i=1; i<n; i++)
	num = num ^ array[i]; 

    return num;
}

int
main()
{
    int num, i;
    int n, array[100];

    while(1)
    {
	printf("<num> <array>	:   ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	    scanf("%d", &array[i]);

	num = odd_occurence(array, n);

	printf("Odd occuring item   :	%d\n", num);
    }
    return 0;
}
