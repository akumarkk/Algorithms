#include <iostream>
using namespace std;


class mypair
{
    int *array;
    int  n;
    int value;

    public:
	mypair(int x=5)
	{
	    n = x;
	    array = new int[n];
	    value = 7;
	}

	~mypair()
	{
	    delete []array;
	}

	void print_pair();

	void set_value(int *a);
};

void mypair::print_pair()
{
    int i;
    int first = 0, last = n-1;
    long sum = 0;
    
    while(first < last)
    {
	sum = array[first] + array[last];
	if(sum == value)
	{
	    cout<< "Value1 = " << array[first] << "     Value2 = " << array[last] << endl;
	}

	if(sum > value)
	    last--; // We need a sum slittle smaller, So decrement last
	else 
	    first++; // We need sum to be litter bigger so increment first
    }

    cout << "END" << endl;
}

void mypair::set_value(int *a)
{
    for(int i=0; i<n; i++)
	array[i] = a[i];
}

int
main()
{
    int a[100];

    cout<< "Items : " ;
    for(int i=0; i<10; i++)
	cin>>a[i];

    mypair p(10);
    p.set_value(a);

    p.print_pair();
    
    return 0;
}

