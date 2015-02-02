#include <iostream>
using namespace std;

int
number_of_deletions( char * str)
{
    int i, count=1, total=0;
    int len = strlen(str);

    for(i=1; i<len; i++)
    {
	if(str[i-1] == str[i])
	   count++;
	else
	{
	    total+= count-1;
	    count = 1;
	}
    }
    total += count - 1;
    
    return total;
}


int
main()
{
    int ret=0;
    char str[1024] = "";

    cout<< "String : " << endl;
    cin>> str;

    ret = number_of_deletions(str);
    cout<< " Number of deletions = " << ret << endl;
    return 0;
}
