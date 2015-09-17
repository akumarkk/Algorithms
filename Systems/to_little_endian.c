#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

uint32_t
to_little_endian(uint32_t num)
{
    return ((num<<24)& 0xff000000) |
	((num<<8)& 0x00ff0000) |
	((num>>24)& 0xff) |
	((num>>8)& 0xff00);
}

int
main()
{
    uint32_t num = 0x44778899;
    printf("Given number	    :	%x\n",num);
    printf("Converted number	    :	%x\n", to_little_endian(num));
   return 0;
} 
