#include <iostream>
#include <sstream>
#include <stack>
using namespace std;


#define apply() \
	do{\
            {\
                val2 = value_stack.top(); value_stack.pop();\
                val1 = value_stack.top(); value_stack.pop();\
                opr = opr_stack.top(); opr_stack.pop();\
                res = get_result(opr, val1, val2);\
                value_stack.push(res);\
            }\
	}while(0)

long
get_result(char opr, long val1, long val2)
{
    switch(opr)
    {
	case '+': return (val1 + val2);
	case '-': return (val1 - val2);
	case '*': return (val1 * val2);
	case '/': return (val1 / val2);
	case '%': return (val1 % val2);
	default: printf("Invalid case\n");
		 return 0;
    }
}

int
priority(char ch)
{
    switch(ch)
    {
	case '(':
	case ')':
	    return 0;
	case '+':
	case '-':
	    return 1;
	case '*':
	case '/':
	case '%':
	    return 2;
	default :
	    return 3;
    }
}

int
is_operator(char ch)
{
    switch(ch)
    {   
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            return 1;
        default :
            return 0;
    }
}


long 
evaluate_infix(char *infix)
{
    stack<char> opr_stack;
    stack<long> value_stack;

    int len = strlen(infix);
    int i=0, k=0;
    long val1, val2, res, value =0;
    char token, opr, buf[256] = "";

    cout<< infix << " with len " << len << endl;

    while( i<len && (token=infix[i++]) != '\0')
    {
	printf("Processing  %c\n", token);

	if(token == ' ')
	    continue;
	
	while(i<=len && (token >= '0' && token <= '9'))
	{
	    buf[k++] = token;
	    token = infix[i++];
	}

	if(k)
	{
	    buf[k] = '\0';
	    value = atoi(buf);
	    value_stack.push(value);
	    cout << "Parsed value = " << value << endl;
	    k = 0;
	}

	if(token == ' ')
	    continue;
	else if(token == '(')
	    opr_stack.push(token);
	else if(token == ')')
	{
	    while(!opr_stack.empty() && (opr_stack.top() != '('))
	    {
		cout<<"Operator : " << token << endl;
		apply();
	    }

	    if(opr_stack.top() == '(')
		opr_stack.pop();
	}
	else if(is_operator(token))
	{
	    while(!opr_stack.empty() && (priority(token) <= priority(opr_stack.top())))
	    {
		apply();
	    }
	    opr_stack.push(token);
	}
	else
	{
	    while(!opr_stack.empty())
		apply();
	}
    }

    while(!opr_stack.empty())
	apply();
    
    return value_stack.top();
}


int
main()
{
    char infix[256] = "";

    while(1)
    {
	cout<< "Infix expression : ";
	cin.getline( infix, 256);

	long res = evaluate_infix(infix);
	cout<< infix << " = " << res << endl;
    }
    return 0;
}

