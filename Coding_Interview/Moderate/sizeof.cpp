#include <iostream>
using namespace std;


template <class T>
class sizeOf
{
    T var;
    public:
	sizeOf(char *str)
	{
	    var = strlen(str);
	    cout << "Sizeof " << str << " = " << sizeof(var) << endl;
	}

	void show();

};

template <class U>
void sizeOf<U>::show()
{
    cout<<"Value of var = " << var << endl;
}

int
main()
{
    //char str[100];
    sizeOf<int> a("Integer");
    sizeOf<long> b("Long");
    sizeOf<long long> c("Long Long");
    sizeOf<double> d("Double");
    sizeOf<char> e("Char");
 
   a.show();
   b.show(); 
    return 0;
} 
