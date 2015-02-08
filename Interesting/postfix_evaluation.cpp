#include <iostream>
#include <stack>

using namespace std;

stack<char> mystack;

int
priority(char token)
{
    switch(token)
    {
	case '(' :
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

bool
is_operator(char token)
{
    switch(token)
    {
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	    return true;

	default:
	    return false;
    }
}

void
infix_to_postfix(char *infix, char *postfix)
{
    char token, tmp;
    int  i=0, k=0;

    while((token=infix[i++]) != '\0')
    {
	cout << "Processing " << token << endl;

	if(isalnum(token))
	{
	    postfix[k++] = token;
	}
	else if(token == '(')
	{
	    mystack.push(token);
	}
	else if(token == ')')
	{
	    tmp = mystack.top();
	    mystack.pop();
	    
	    while(tmp != '(' )
	    {
		if(mystack.empty())
		    cout<< "Invalid input it seems " << endl;

		postfix[k++] = tmp;
		tmp = mystack.top();
		mystack.pop();
	    }
	}
	else
	{
	    cout<< "Operator " << token << endl;
	    while((!mystack.empty()) && priority(token) <= priority(mystack.top()) )
	    {
		cout<< "token = " << token << "top of stack = " << mystack.top() << endl;
		postfix[k++] = mystack.top();
		mystack.pop();
	    }

	    mystack.push(token);
	}
    }


    while(!mystack.empty())
    {
	postfix[k++] = mystack.top();
	mystack.pop();
    }
    postfix[k] = '\0';

}

int
evaluate_postfix(char *postfix)
{
    stack<int> st;
    char token;
    int i=0;
    long res, op1, op2;

    while( (token=postfix[i++]) != '\0')
    {
	if(is_operator(token))
	{
	    op2 = st.top(); st.pop();
	    op1 = st.top(); st.pop();

	    cout<< "res = " << op1 << token << op2 << endl;

	    switch(token)
	    {
		case '+' : 
		    res = op1 + op2;
		    break;
		case '-':
		    res = op1 - op2;
		    break;

		case '*':
		    res = op1 * op2;
		    break;

		case '/':
		    res = op1 / op2;
		    break;

		case '%':
		    res = op1 % op2;
		    break;
	    }
	    
	    st.push(res);
	    cout<< res << " = " << op1 << token << op2 << endl;
	}
	else
	{
	    st.push(token);
	}
    }

    printf("%s = %d\n", postfix, st.top());

    return st.top();
}


int
main()
{
    long res = 0;
    char infix[256]= "", postfix[256] = "";

    while(1)
    {
	cout<<("INFIX EXPRESSION : ");
	cin>>infix;

	infix_to_postfix(infix, postfix);

	cout<<"POSTFIX EXPRE : " << postfix << endl;
	res = evaluate_postfix(postfix);

	cout<< "RESULT = " << res << endl;
    }

    return 0;
}




