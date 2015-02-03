#include <iostream>
using namespace std;

class myaddition
{
    int a;
    int b;
    int sum;
    public:
	myaddition(int x=-5, int y=-8)
	{
	    a = x;
	    b = y;
	}

	void set_values(int x, int y)
	{
	    a = x;
	    b= y;
	}

	int addition_helper(int a, int b);
	int addition();
	int substraction();
};

int myaddition::substraction()
{
    int y = -b;
    int subs = 0;

    subs = addition_helper(a, y);
    return subs;
}


int myaddition::addition_helper(int a, int b)
{
    int sum = 0;
    int carry = 0;
    if(b == 0)
	return a;

    sum = a ^ b;
    carry = (a & b) << 1;
    return addition_helper(sum, carry);
}

int myaddition::addition()
{
    sum= addition_helper(a, b);
    return sum;
}

int
main()
{
    int a, b;
    myaddition add;

    while(1)
    {
	cout<< "Value to be summed up : ";
	cin>>a >> b;
	add.set_values(a, b);

	cout << "Sum of (" << a<< "," << b <<" ) = " << add.addition() << endl;
	cout << "Diff of (" << a<< "," << b <<" ) = " << add.substraction() << endl;
    }

    return 0;
}
