#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct mystack_
{
    int top;
    int max;
    int *list;
}mystack_t;

void
init_stack(mystack_t **tmp, int max)
{
    (*tmp) = malloc(sizeof(mystack_t));
    (*tmp)->top = -1;
    (*tmp)->max = max;

    (*tmp)->list = malloc(sizeof(int) * max);
}


int
priority(char ch)
{
    switch(ch)
    {
	case '(':
	case ')': return 0;
	case '+':
	case '-':
		  return 1;
	case '*':
	case '/':
		  return 2;
	default:
		  printf("Unknown case \n");
		  return 3;
    }
}

void
push(mystack_t *st, int value)
{
    printf("stack top = %d\n", st->top);
    if(st->top == st->max-1)
	return;

    st->list[++(st->top)] = value;
    printf("Successfully inserted an element = %d\n", st->list[st->top]);
}

int 
pop(mystack_t *st)
{
    if(st->top < 0)
	return -1;
    
    return st->list[(st->top)--];
}

bool
is_empty(mystack_t *st)
{
    if(st->top < 0)
	return true;
    return false;
}

int
peek(mystack_t *st)
{
    if(!is_empty(st))
	return st->list[st->top];
}


void
infix_to_postfix(char *infix, char *postfix)
{
    int len = strlen(infix);
    int i  = 0;
    int k = 0;

    mystack_t *op_st = NULL;
    init_stack(&op_st, 256);

    printf("Initialized the stack ... %p\n", op_st);

    while(i < len)
    {
	printf("processing %c\n", infix[i]);
	if(isdigit(infix[i]))
	{
	   // Digit 
	   postfix[k++] = infix[i++];
	}
	else if(infix[i] == '(')
	{
	    push(op_st, infix[i]);
	    i++;
	}
	else if(infix[i] == ')')
	{
	    while(!is_empty(op_st) && peek(op_st) != '(')
		postfix[k++] = pop(op_st);
	    pop(op_st);
	    i++;
	}
	else 
	{
	    printf("operator = %c\n", infix[i]);
	    while((!is_empty(op_st)) && priority(peek(op_st)) >= infix[i])
	    {
		printf("STack is not empty...\n");
		postfix[k++] = pop(op_st);
	    }
	    printf("pushing an element into stack ...\n");
	    push(op_st, infix[i]);
	    i++;
	}
    }

    while(!is_empty(op_st))
	postfix[k++] = pop(op_st);

    printf("Infix expression = %s	Postfix expression = %s\n", infix, postfix);
}

int
main()
{
    char infix[256], postfix[256] = "";

    while(1)
    {
	printf("<Infix expression>  :	");
	scanf("%s", infix);
	infix_to_postfix(infix, postfix);
    }

    return 0;
}

