#include <stdio.h>
#include <stdlib.h>

// 11:38 AM to 12:54AM


typedef struct stack_
{
    int	    top;
    int	    size;
    char    *items;
}mystack_t;

mystack_t *
init_stack(int size)
{
    mystack_t *st = malloc(sizeof(mystack_t));
    st->top = -1;
    st->size = size;
    st->items = malloc(size);

    return st;
}

char
push(mtstack_t *st, char data)
{
    if(st->top == st->size)
	return -1;

    st->items[++(st->top)] = data;
    return data;
}

char pop(mystack_t *st)
{
    if(st->top == -1)
	return -1;

    return st->items[(st->top)--];
}

bool
is_empty(mystack_t *st)
{
    if(st->top == -1)
	return true;
    return false;
}


char
peek(mystack_t *st)
{
    return st->items[st->top];
}


int
evaluate_infix(char *infix)
{
    if(infix == NULL)
	return 0;

    while( (token = infix[i++]) != '\0')
    {
	if(token == '(')
	{
	    push(op_st, token);
	}
	else if(isalnum(token))
	{
	    push(val_st, token);
	}
	else if(token == ')')
	{
	    opr = pop(op_st);
	    op2 = pop(val_st);
	    op1 = pop(val_st);

	    switch(opr)
	    {
		case '+': res = atoi(op1) + atoi(op2); break;
		case '-': res = atoi(op1) - atoi(op2); break;
		case '*': res = atoi(op1) * atoi(op2); break;
		case '/': res = atoi(op1) / atoi(op2); break;
		case '%': res =  atoi(op1) % atoi(op2); break;
	    }
	    push(val_st, res);
	}
	else
	{
	    //It should be operator
	    while(!is_empty(op_st) && priority(token) <= priority(peek(op_st)))
	    {
		op2 =  pop(val_st);
		op1 = pop(val_st);
		switch(token)
		{
		    case '+': res = atoi(op1) + atoi(op2); break;
		    case '-': res = atoi(op1) - atoi(op2); break;
		    case '*': res = atoi(op1) * atoi(op2); break;
		    case '/': res = atoi(op1) / atoi(op2); break;
		    case '%': res =  atoi(op1) % atoi(op2); break;
		}
		push(val_st, res);
		token = pop(op_st);
	    }
	    push(op_st, token);
	}
    }

