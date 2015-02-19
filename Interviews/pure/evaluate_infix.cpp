#include <iostream>
#include <stack>
using namespace std;


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
	default:
	    return 3;
    }
}


long get_value(char opr, long val1, long val2)
{
    switch(opr)
    {
	case '+': return val1 + val2;
	case '-': return (val1 - val2);
	case '*': return (val1 * val2);
	case '/': return (val1 / val2);
	case '%': return (val1 % val2);
	default : printf("Invalid case\n");
		  return 0;
    }
}


int
is_operator(char token)
{
    switch(token)
    {
	case '+':
	case '-':
	case '*':
	case '/':
	case '%': return 1;
	default : return 0;
    }
}

int
evaluate_infix(char *infix)
{
    stack<long> value_stack;
    stack<char> opr_stack;

    long val1, val2;
    long res, value=0;
    int  i=0;
    int	    k=0;
    char    token, opr;
    char    buf[128] = "";
    int len = strlen(infix);

    cout << "Infix expression : " << infix << len << endl;

    while((token = infix[i++]) != '\0')
    {
	cout<<"Processing " << token << endl;

	if(token == ' ')
	{
	    cout<< "Encountered a white space " << endl;
	    continue;
	}

	k=0;
	cout<< "i = " << i << "len = " << len << "token = " << token << endl;

	while((i<= len) && (token >= '0' && token <= '9'))
	{
	    cout << "Parsing operands : " << token << endl;
	    buf[k++] = token;
	    token = infix[i++];
	    cout<< "Value of k = " << k << endl;
	}
	printf("buf :	%s k= %d\n", buf, k);

	if(k)
	{
	    buf[k] = '\0';
	    value = atoi(buf);
	    value_stack.push(value);
	    cout<< "Value = " << value << endl;
	}

	if(token == ' ')
	{
	    continue;
	}
	else if(token == '(')
	    opr_stack.push(token);
	else if(token == ')')
	{
	    while(!opr_stack.empty() && opr_stack.top() != '(')
	    {
		val2 = (long)value_stack.top(); value_stack.pop();
		val1 = (long)value_stack.top(); value_stack.pop();
		opr = (char)opr_stack.top();	opr_stack.pop();

		res = get_value(opr, val1,val2);
		cout<< "Pushing result " << val1 << " " << opr << " " << val2 << " = " << res << endl;

		value_stack.push(res);
	    }

	    if(!opr_stack.empty() && opr_stack.top() == '(')
		opr_stack.pop();
	}
	else if(is_operator(token))
	{
	    cout<< "Operator : " << token << endl;

	    while(!opr_stack.empty() && priority(token)<= priority(opr_stack.top()))
	    {
		val2 = (long)value_stack.top();	value_stack.pop();
		val1 = (long)value_stack.top(); value_stack.pop();
		opr = (char)opr_stack.top();	opr_stack.pop();

		res = get_value(opr, val1,val2);
		value_stack.push(res);
		cout<< "Pushing result " << val1 << " " << opr << " " << val2 << " = " << res << endl;
	    }

	    opr_stack.push(token);
	}
	else
	{
	    while(!opr_stack.empty())
	    {
		cout<< " Final value computation " << endl;
		val2 = (long)value_stack.top(); value_stack.pop();
		val1 = (long)value_stack.top(); value_stack.pop();
		opr = (char)opr_stack.top();	opr_stack.pop();

    		res = get_value(opr, val1,val2);
		value_stack.push(res);
		cout<< "Final result " << val1 << " " << opr << " " << val2 << " = " << res << endl;
	    }
	}
    }

            while(!opr_stack.empty())
            {
                cout<< " **** Final value computation " << endl;
                val2 = (long)value_stack.top(); value_stack.pop();
                val1 = (long)value_stack.top(); value_stack.pop();
                opr = (char)opr_stack.top();    opr_stack.pop();

                res = get_value(opr, val1,val2);
                value_stack.push(res);
                cout<< "Final result " << val1 << " " << opr << " " << val2 << " = " << res << endl;
            }


    cout << "FINAL RESULT : " << res << endl;
    return value_stack.top();
}

int
main()
{
    char infix[256] = "";
    long result = 0;
    int flag = 1;

    while(flag)
    {
	cout<< "Infix expression : ";
	//cin>>infix;
	strcpy(infix, "3+3");

	result = evaluate_infix(infix);
	cout<< infix << " = " << result << endl;
	flag = 0;
    }
    
    memset(infix, 0, sizeof(infix));
    strcpy(infix, "(10 + 20)");
    result = evaluate_infix(infix);
    cout<< infix << " = " << result << endl;

    strcpy(infix, "(10 + 20) * (10 /2)");
    result = evaluate_infix(infix);
    cout<< infix << " = " << result << endl;

    strcpy(infix, "(10 + 20) * (10 /2)+100");
    result = evaluate_infix(infix);
    cout<< infix << " = " << result << endl;

    return 0;
}
