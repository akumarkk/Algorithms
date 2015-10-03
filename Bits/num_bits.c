#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Number of bits :
 * F(n) = F(m-1) + F(n-m) + (n-m+1) where m = number such that 2^x < n
 * F(m-1) = x * m/2 = x * 2^x/2 = x * 2^(x-1)
 *
 * http://stackoverflow.com/questions/9812742/finding-the-total-number-of-set-bits-from-1-to-n
 */
#define DEBUG 1
#define debug(fmt, ...)\
    do{\
	if(DEBUG)\
	    fprintf(stdout, "%s(%d): " fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__);\
    }while(0)

/* NumberOfBits(num) = log(num) + 1
 * For our case, we just need log(num);
 */
int bit_count(int num)
{
    int count = 0;
    int num1 = num;

    while(num > 1)
    {
	count++;
	num = num/2;
    }

    debug("# of bits in %d = %d", num1, count);
    return count;
}

int get_number_of_bits(int num)
{
    int term1, term2, term3, m, bits;

    debug("processing %d", num);
    if(num == 0 || num == -1)
	return 0;
    if(num == 1)
	return 1;

    bits = bit_count(num);

    term1 = bits * pow(2, bits - 1);
    m = pow(2, bits);

    debug("m = %d	bits = %d", m, bits);
    term2 = get_number_of_bits(num - m);
    term3 = num - m + 1;

    return (term1 + term2 + term3);
}


int
main()
{
    int total_bits;
    int num;

    while(1)
    {
	printf("Number	:   ");
	scanf("%d", &num);
	total_bits = get_number_of_bits(num);

	printf("# of bits from [0 to %d] = %d\n", num, total_bits);
    }

    return 0;
}
