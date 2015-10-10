#include <iostream>
#include <string>
#include <stack>

using namespace std;

long
apply(char op, long v1, long v2)
{
    switch(op)
    {
	case '+': return v1+v2;
	case '-': return v1 - v2;
	case '*': return v1 * v2;
	case '/': return v1/v2;
	default:
		  printf("Unknown operator %c\n", op);
    }

    return 0;
}

bool
hasprecedence(char op1, char op2)
{
    if((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
	return false;
    if((op2 == '(') || op2 == ')')
	return false;
    return true;
}

bool
is_operator(char ch)
{
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-')
	return true;
    return false;
}

long
infix_evaluation(char *string)
{
    int		    i=0, k=0;
    long	    value, v1, v2;
    char	    buf[256] = ""; 
    stack<long>	    s_value;
    stack<char>	    s_op;

    if(strlen(string) <= 1)
	return atoi(string);

    while(string[i])
    {
	if(isspace(string[i]))
	{
	    i++;
	    continue;
	}

	if(string[i] >= '0' && string[i] <= '9')
	{
	    k = 0;
	    while(string[i] >= '0' && string[i] <= '9')
	    {
		buf[k++] = string[i];
		i++;
	    }
	    buf[k] = '\0';

	    value = atoi(buf);
	    s_value.push(value);
	}

	if(string[i] == '(')
	{
	    s_op.push(string[i]);
	    i++;
	}

	if(string[i] == ')')
	{
	    while(s_op.top() != '(')
	    {
		v2 = s_value.top();
		s_value.pop();
		v1 = s_value.top();
		s_value.pop();

		value = apply(s_op.top(), v1, v2);
		s_op.pop();
		s_value.push(value);
	    }

	    s_op.pop();
	    i++;
	}

	if(is_operator(string[i]))
	{
	    while(!s_op.empty() && hasprecedence(string[i], s_op.top()))
	    {
		v2 = s_value.top();
		s_value.pop();
		v1 = s_value.top();
		s_value.pop();
		value = apply(s_op.top(), v1, v2);
		s_op.pop();
		s_value.push(value);
	    }
	    s_op.push(string[i]);
	    i++;
	}
    }

    while(!s_op.empty() )
    {
	v2 = s_value.top();
	s_value.pop();
	v1 = s_value.top();
	s_value.pop();

	value = apply(s_op.top(), v1, v2);
	s_op.pop();
	s_value.push(value);
    }


    return value;
}


int
main()
{
    char str[256] = "";

    while(1)
    {
	printf("\nInfix expression    :	");
	scanf("%s", str);

	long value = infix_evaluation(str);
	printf("Value(%s)   =	%ld", str, value);
    }
    return 0;
}

