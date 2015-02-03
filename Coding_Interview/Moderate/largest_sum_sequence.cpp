#include <iostream>
using namespace std;


// Given a sequence of integers, return the maximum sum 
// obtained from contiguous sequence of numbers


//technique :
//	    - Add a number if it increases the sum_so_far or do not decrease it < 0
//	    - If it decrease it to < 0, then reset it. As there is no value in adding it.
int
max_sum(int *a, int n)
{
    int i=0;
    long sum = 0, max_sum=0; // Shall I assume max_sum to be 0 in case of negative numbers.

    for(i=0; i<n; i++)
    {
	sum = a[i];
	if(sum > max_sum)
	    max_sum = sum;
	if(sum < 0)
	    sum = 0;  // Need to reset as it has to be contiguous sum
    }

    return max_sum;
}


int
main()
{
    int n, a[100];

    cout<< "# of items : ";
    cin>> n;

    cout<< "Items : ";
    for(int i=0;i<n; i++)
    {
	cin>>a[i];
    }

    cout<< " Maximum Sum = " << max_sum(a, n) << endl;

    return 0;
}
