#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct mystack_
{
    int top;
    int max;
    int *list;
}mystack_t;


void
init_stack(mystack_t **st, int max)
{
    mystack_t *tmp = malloc(sizeof(mystack_t));
    tmp->top = -1;
    tmp->max = max;
    tmp->list = malloc(sizeof(int) * max);

    *st = tmp;
}

int
push(mystack_t *st, int data)
{
    if(st->top == st->max -1)
	return -1;

    st->list[++(st->top)] = data;
    return 0;
}

int
pop(mystack_t *st)
{
    if(st->top < 0)
	return -1;

    return st->list[(st->top)--];
}


int
peek(mystack_t *st)
{
    return st->list[(st->top)];
}

bool
is_empty(mystack_t *st)
{
    if(st->top < 0)
	return true;
    return false;
}

void
insert(mystack_t *st, int data)
{
    if(is_empty(st))
    {
	push(st, data);
	return;
    }

    if(data < peek(st))
	push(st, data);
    else
    {
	int item = pop(st);
	insert(st, data);
	push(st, item);
    }
}

void
sort_stack(mystack_t *st)
{
    if(is_empty(st))
	return;

    int item = pop(st);
    sort_stack(st);
    insert(st, item);
}

void
print_stack(mystack_t *st)
{
    int i = 0;
    for(i=0; i<=st->top; i++)
	printf("[%d ] ", st->list[i]);
    printf("\n");
}

int
main()
{
    mystack_t *st;

    init_stack(&st, 10);
    push(st, 2);
    push(st, 40);
    push(st, 8);
    push(st, 10);
    push(st, 1);

    print_stack(st);
    sort_stack(st);
    print_stack(st);

    return 0;
}
