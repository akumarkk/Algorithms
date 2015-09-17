#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef union test_
{
    uint16_t	idata;
    char	ch[2];
}test_t;

bool
is_little_endian()
{
    uint32_t num = 0x12345678;
    uint8_t  *ptr = &num;
    if(*ptr == 0x78 && *(ptr+1) == 0x56)
	return true;
    else
	return false;
}

int
main()
{
    test_t t;
    t.idata = 0x9988;
    if((uint8_t)t.ch[0] == 0x88 && (uint8_t)t.ch[1] == 0x99)
    {
	printf("Union test  : Little endian machine\n");
    }
    else
    {
	printf("Union test  : Big endian machine\n");
    }

    if(is_little_endian())
    {
	printf("Little endian machine\n");
    }
    else
    {
	printf("Big endian machine \n");
    }

    return 0;
}


