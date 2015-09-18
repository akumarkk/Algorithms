#include <stdio.h>
#include <arpa/inet.h>

int
main()
{
    uint16_t	num = 0x4455;

    if(htons(num) == num)
	printf("Big Endian machine %x->%x\n", num, htons(num));
    else
	printf("Little Endian Machine %x->%x\n", num, htons(num));

    return 0;
}
