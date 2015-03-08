#include <iostream>
#include <stack>
using namespace std;


bool
is_match(char token, char match)
{
    switch(token)
    {
	case ')':
	   if(match == '(') 
	   {
	       return true;
	   }
	   else
	   {
	       return false;
	   }
	case '}':
	   if(match == '{')
	       return true;
	   else
	       return false;

	case ']':
	   if(match == '[')
            return true;
           else
             return false;

	default :
		cout<< "DEFAULT CASE" << endl;
		  return false;
    }
}

bool
is_valid(char *value)
{
    char token, match;
    int i =0;
    stack<char> value_stack;

    while( (token=value[i++]) != '\0')
    {
	if( (token == '(') || 
	       (token == '{') ||
	    (token == '['))
	{
	    value_stack.push(token);
	}
	else
	{
	    if(value_stack.empty())
		return false;

	    match = value_stack.top();
	    if(is_match(token, match) == false)
		return false;

	    value_stack.pop();
	}
    }

    if(!value_stack.empty())
	return false;
    else
	return true;
}


int
main()
{
    char value[256] = "";

    while(1)
    {
	cout<< "Input value : ";
	cin.getline(value, 256);
	
	int ret = is_valid(value);
	if(ret == true)
	{
	    cout<< "VALID"<< endl;
	}
	else
	    cout << "INVALID" << endl;
    }
    return 0;
}

	    	    
