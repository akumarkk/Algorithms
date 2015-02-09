#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_
{
    int	    size;
    int	    top;
    char    *items;
}mystack_t;

mystack_t stack;

void
init_stack(int size)
{
    stack.top = -1;
    stack.items = malloc(size);
    stack.size = size;
}


bool
is_alpnum(char token)
{
    if( (token>= 48 && token<=57) ||
	    (token >=65 && token<= 87) ||
	    (token >=97 && token <= 122))
	return true;
    return false;
}


int
push(char item)
{
    if(stack.top == stack.size)
    {
	printf("Stack overflow!\n");
	return -1;
    }

    stack.items[++stack.top] = item;
    return stack.items[stack.top];
}

int
pop()
{
    if(stack.top == -1)
	return -1;

    return stack.items[stack.top--];
}

int
priority(char token)
{
    switch(token)
    {
	case '(': 
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
is_empty()
{
    if(stack.top == -1)
	return true;
    return false;
}

char
peek()
{
    return stack.items[stack.top];
}


void
reverse(char *str)
{
    int i=0;
    int j= strlen(str) -1;

    while(i < j)
    {
	str[i] = str[i] ^ str[j];
	str[j] = str[i] ^ str[j];
	str[i] = str[i] ^ str[j];
	i++;
	j--;
    }
}

/* Algorithm:
 *	1. If operand, add as as part of postfix
 *	2. If operator, if priority of operator on top is greater than that of curr one, pop from stack and add
 *	    the current operator onto stack
 *	3. If '(', push it onto stack
 *	4. If ')', pop all the items till corresponding '(' is found
 */
void
infix_to_postfix(char *infix, char *postfix)
{
    char    token, tmp;
    int	    i=0, k=0;

    init_stack(100);

    printf("INFIX EXPRESSION = %s\n", infix);
    
    reverse(infix);

    while(i<strlen(infix))
    {
	if(infix[i] == '(')
	    infix[i] = ')';
	else if(infix[i] == ')')
	    infix[i] = '(';

	i++;
    }
    i=0;

    printf("INFIX EXPRESSION = %s\n", infix);
    while((token = infix[i++]) != '\0')
    {
	if(is_alpnum(token))
	    postfix[k++] = token;
	else if(token == '(')
	    push(token);
	else if(token == ')')
	    {
		tmp = pop();
		while(tmp != '(')
		{
		    postfix[k++] = tmp;
		    tmp = pop();
		}
	    }
	else
	{
	    while(priority(token) <= priority(peek()) && !is_empty())
	    {
		tmp = pop();
		postfix[k++] = tmp;
	    }
	    push(token);
	}
    }

    while(!is_empty())
    {
	tmp = pop();
	postfix[k++] = tmp;
    }

    postfix[k] = '\0';
    reverse(postfix);
}


int
main()
{
    char infix[512] = "", postfix[512] = "";

    while(1)
    {
	printf("INFIX EXPRESSION : ");
	scanf("%s", infix);

	infix_to_postfix(infix, postfix);
	printf("POSTFIX EXPRESSION : %s\n", postfix);
    }

    return 0;
}
