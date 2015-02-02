#include <iostream>
using namespace std;


#define PRECISION(uintmax_t) pop_count(uintmax_t)

int pop_count(uintmax_t a)
{
    int count = 0;
    while(a != 0) 
    {
	if(a%2 == 1) 
	    count++; 
	a = a/2; 
    }
    return count;
}



int
addition_overflow(int a, int b)
{
    if( (b>0 && a> INT_MAX-b) ||
	    (b<0 && a< INT_MIN-b))
    {
	return -1;
    }
    return 0;

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
		return -1;
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
    int count=0;

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


int
main()
{
    int a, b;
    // Testing integer overflow
    // Addition
    a = INT_MAX -3;
    b = 10;
    if(addition_overflow(a, b) == -1)
	cout<< "Addition Integer Overflow" << endl;
    else
	cout <<"No overflow" << endl;

    b = -10;
    if(substraction_overflow(a, b) == -1)
	cout << "Substraction Integer overflow" << endl;
    else
	cout << "Substraction no overflow" << endl;

    b = 2;
    if(multiplication_overflow(a, b) == -1)
	cout << "Multiplication overflow" << endl;
    else
	cout << "* No overflow" << endl;

    return 0;
}
