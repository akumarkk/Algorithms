#include <iostream>
using namespace std;

template <class T>
class Largest
{
    T a;
    T b;
    T largest; //Cant return private member value to non-member functions
    public:
    //T largest;
	Largest(T x, T y)
	{
	    a = x;
	    b = y;
	    cout <<"Initialized (" << a << ", )" << b << endl;
	}

	T sign(T );
	T get_largest();
	void set(T x, T y)
	{
	    a = x;
	    b = y;
	}
};

template <class U>
U Largest<U>::get_largest()
{
    int sa, sb, sc;
    int use_sign_of_a, use_sign_of_c, k, q;

    sa = sign(a);
    sb = sign(b);
    sc = sign(a - b);

    use_sign_of_a = sa ^ sb;
    use_sign_of_c = (sa^sb) ^ 1; // Flip the bit

    k = use_sign_of_a * sa + use_sign_of_c * sc;
    q = k ^ 1; //Flip this bit

    largest = (k*a + q*b);
    return largest;
}

template <class K>
K Largest<K>::sign(K x)
{
    K size;
    size = sizeof(K) * 8;

    size = (x >> (size-1)) & 0x1;
    size = size ^ 1;
   
    return size;
}

int
main()
{
    int a, b;
    
    Largest<int> l1(20, 30);
    cout << "Largest among (20, 30) = " << l1.get_largest() << endl;

    cout<< "Value of a and b: ";
    cin >> a >> b;

    l1.set(a, b);
    cout << "Largest  = " << l1.get_largest() << endl;

    return 0;
}
    


