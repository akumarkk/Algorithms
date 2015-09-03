#include <stdio.h>
#include <stdlib.h>

typedef struct stack_
{
    int *data;
    int top;
    int max_size;
}mystack_t;

/* stack to keep track of min elements */
mystack_t min_stack;

void
init_stack(mystack_t  *stack)
{
    //stack = malloc(sizeof(mystack_t));
    stack->data = malloc(sizeof(int) *100);
    stack->max_size = 100;
    stack->top = -1;
}

int
push(mystack_t *stack, int data)
{
    if(stack->top == stack->max_size)
	return -1;

    stack->data[++stack->top] = data;
    if(min_stack.top < 0)
    {
	min_stack.data[++min_stack.top] = data;
    }
    else if(data <= min_stack.data[min_stack.top])
    {
	min_stack.data[++min_stack.top] = data;
    }

    return 0;
}


int
pop(mystack_t *stack)
{
    if(stack->top < 0)
    {
	printf("Stack underflow\n");
	return -1;
    }

    if(stack->data[stack->top] == min_stack.data[min_stack.top])
	min_stack.top--;

    stack->top--;
    return 0;
}


void
print_stack(mystack_t *stack)
{
    int i;
    for(i=stack->top; i>=0; i--)
	printf("[%d]	", stack->data[i]);
    printf("\n");
}

void
print_min()
{
    //printf("Original Stack : ");
    
    printf("Min item is :   [%d]\n", min_stack.data[min_stack.top]);
}


int
main()
{
    int opcode, data;
    mystack_t *stack;

    stack = malloc(sizeof(stack_t));
    init_stack(stack);
    init_stack(&min_stack);
    
    while(1)
    {
	printf("1. Push	    2. Pop  3.Exit\n");
	scanf("%d", &opcode);

	switch(opcode)
	{
	    case 1: 
		printf("Item to push : ");
		scanf("%d", &data);
		push(stack, data);
		    print_stack(stack);
		    print_min();
		    break;

	    case 2: pop(stack);
		    print_stack(stack);
		    print_min();
		    break;

	    default:
		    exit(0);
	}
    }

    return 0;
}

