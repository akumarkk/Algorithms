#include <iostream>
#include <string>

using namespace std;

string digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string teens[]  = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[]   = {"ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninty"};
string bigs[]   = {" ", "Thousands", "Million", "Billion"};


string num100tostring(int num);

    
string 
number_to_string(int num)
{
    int count = 0;
    string str(" ");

    if(num == 0)
	return "Zero";
    else if(num < 0)
    {
	str = "Negative " + number_to_string(-num);
	return str;
    }


    while(num > 0)
    {
	if(num % 1000 != 0)
	{
	    str = num100tostring(num % 1000) + " " + bigs[count] + " " + str + " ";
	}
	num = num/1000;

	count++;
    }

    return str;
}

string num100tostring(int num)
{
    string str(" ");

    // Hundrads case
    if(num >= 100)
    {
	str = digits[num/100 -1] + "hundrads" + " ";
	num = num % 100;
    }

    // Tens
    if(num == 10 || (num >= 20))
    {
	str = str + tens[num/10 - 1] + " ";
	num = num % 10;
    }
    else if(num >= 11 && num <= 19)
    {
	str = str + teens[num - 11] + " ";
    }

    //Digits
    if(num < 10)
    {
	str = str + digits[num-1] ;
    }

    return str;
}


int
main()
{
    string str(" ");

    for(int i=-1; i<1001; i++)
    {
	//str = " ";
	string str = number_to_string(i);
	cout << "Number (" << i << " ) = " << str << endl;
    }

    return 0;
}
