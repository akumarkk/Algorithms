#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct item_
{
    int	index;
    int	element;
}item_t;


item_t *
get_item(int data)
{
    item_t  *tmp = malloc(sizeof(item_t));
    tmp->index = 0;
    tmp->element = data;
    return tmp;
}

void
print_array(int a[], int n)
{
    int i=0;
    for(i=0; i<n; i++)
	printf("%d ", a[i]);
    printf("\n");
}


typedef struct stack__
{
    int	    top;
    int	    max;
    item_t  **list;
}mystack_t;

mystack_t * 
init_stack(int size)
{
    mystack_t	*tmp = malloc(sizeof(mystack_t));
    tmp->max = size;
    tmp->top = 0;

    tmp->list = malloc(sizeof(item_t *) * size);

    return tmp;
}

item_t *
push(mystack_t *s, item_t *item)
{
    if(s->top >= s->max)
    {
	printf("Stack overflow\n");
	return NULL;
    }

    s->list[s->top] = item;
    (s->top)++;

    return item;
}

item_t *
pop(mystack_t *s)
{
    if(s->top <= 0)
    {
	printf("stack underflow\n");
	return NULL;
    }

    item_t *item = s->list[--(s->top)];
    return item;
}

item_t *
peek(mystack_t *s)
{
    return s->list[(s->top) - 1];
}

bool
is_empty(mystack_t  *st)
{
    if(st->top <= 0)
	return true;
    return false;
}


int *
get_next_greater_elements(int *a, int n)
{
    mystack_t	*st = init_stack(n);
    item_t	*item = get_item(a[0]);
    item_t	*tmp;
    int		i = 1;
    int		next;
    int		*greater = malloc(sizeof(int) * n);

    item->element = a[0];
    item->index = 0;
    push(st, item);

    while(i < n)
    {
	next = a[i];
	printf("processing item    =   %d\n", next);

	if(is_empty(st))
	{
	    printf("pushing item = %d\n", next);
	    tmp = get_item(0);
	    tmp->element = next;
	    tmp->index = i;
	    push(st, tmp);

	    i++;
	    continue;
	}

	tmp = peek(st);
	if(next > tmp->element)
	{
	    greater[tmp->index] = next;
	    printf("Found greater element index = %d	value = %d\n", tmp->index, greater[tmp->index]);
	    pop(st);
	}
	else
	{
	    printf("lesser item. pushing it into stack = %d\n", next);
	    tmp = get_item(0);
	    tmp->element = next;
	    tmp->index = i;
	    push(st, tmp);
	    i++;
	}
    }

    while(!is_empty(st))
    {
	item = pop(st);
	greater[item->index] = -1;
    }

    print_array(a, n);
    print_array(greater, n);
    return greater;
}


int
main()
{
    int n, a[] = {11, 13, 21, 3, 4, 5, 2, 25};
    get_next_greater_elements(a, 8);
    return 0;
}
