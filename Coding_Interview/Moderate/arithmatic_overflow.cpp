#include <iostream>
using namespace std;


#define PRECISION(a, count) \
do{\
    while(a != 0) \
    {\
	if(a%2 == 1) \
	    count++; \
	a = a/2; \
    }\
}while(0)



template <class T>
int
addition_overflow(T a, T b)
{
    if( (b>0 && a> INT_MAX-b) ||
	    (b<0 && a< INT_MIN-b))
    {
	return -1;
    }

    cout << "No overflow" << endl;
}

int
substraction_overflow(int a, int b)
{
    //Overflow happens only when a and b have different signs
    if( (b<0 && a>INT_MAX+b) ||
	    (b>0 && a<INT_MIN+b))
	return -1;

    return 0;
}


int
multiplication_overflow(int a, int b)
{
    if(a > 0)
    {
	if(b > 0)
	{
	    if(a > INT_MAX/b)
		return -1
	}
	else if(b < 0)
	{
	    if (b < INT_MIN/a)
		return -1;
	}
    }
    else
    {
	if(b > 0)
	{
	    if(a < INT_MIN/b)
		return -1;
	}
	else
	{
	    if(b != 0 && b < INT_MAX/a)
	       return -1;
	}
    }
return 0;
}

int
division(int a, int b)
{
    if(b==0 || (a == INT_MIN && b == -1))
	return -1;

    return 0;
}

int 
modulo(int a, int b)
{
    if(b == 0 && (a == INT_MIN && b == -1))
	return -1;

    return 0;
}

int
shift(int a, int b)
{
    if(a<0 || b<0 || 
	    b >= PRECISION(INT_MAX) || a > PRECISION(INT_MAX) >> b)
	return -1;

    return 0;
}

int
unary_negation(int a)
{
    if(a == INT_MIN)
	return -1;
    return 0;
}
