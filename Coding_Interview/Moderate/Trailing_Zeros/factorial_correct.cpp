/* Number of trailing zeros in a factorial(num) can be found by :
 *  1. Finding the factorial first and diving the number by 10 to find the number of 0
 *  2. Each 0 is constitueted by a pair of multiple of 5 and 2. 
 *	Example : 5 * 2 = 10
 *		5*3  * 2 = 30
 *		5*3 *  2*2 =  60 
 *		5^2 *  2*2 = (5*2) *(5*2) = 100 
 *
 *		So pairs of multiples of 2 and 5 constituete one 0.
 *		As # of 2 are more than # of 5, its good enough to count # of factors of 5 to compute #of 0.
 *
 */

#include <iostream>
using namespace std;

int
number_of_trailing_zeros(int num)
{
    int count = 0, i;

    for(i=5; num/i > 0; i*=5)
    {
	count = count + (num/i);
    }
    return count;
}


int
main()
{
    int i;

    for(i=0; i<100; i++)
    {
	int ret = number_of_trailing_zeros(i);
	cout << "Number of trailing zeros (" << i << "!) = " << ret << endl;
    }

    return 0;
}
