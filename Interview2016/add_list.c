#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_
{
    int		    data;
    struct node_    *next;
}node_t;

node_t *
get_node(void)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = 0;
    tmp->next = NULL;
    return tmp;
}

node_t *
get_node_data(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}


node_t *
add_list(node_t *list1, node_t *list2, int *carry)
{
    node_t *root = NULL;

    if(list1 == NULL && list2 == NULL)
	return NULL;

    root = get_node();
    root->next = add_list(list1->next, list2->next, carry);
    root->data = (list1->data + list2->data + *carry)%10;
    *carry = (list1->data + list2->data + *carry)/10;

    return root;
}

node_t *
add_util(node_t *list1, int *carry)
{
    if(list1 == NULL)
	return NULL;

    node_t *node = get_node();
    node->next = add_util(list1->next, carry);

    node->data = (list1->data + *carry) % 10;
    *carry = (list1->data + *carry) / 10;

    return node;
}

void
print_list(node_t *list)
{
    while(list != NULL)
    {
	printf("[%d]->", list->data);
	list = list->next;
    }
    printf("[NULL]\n");
}

node_t *add_two_list(node_t *list1, node_t *list2)
{
    int	    l1=0, l2 = 0, diff = 0, count, carry = 0;
    node_t  *prev, *smaller, *start, *bigger;
    node_t  *root1, *root2, *root, *node;
    node_t  *tmp = list1;

    while(tmp != NULL)
    {
	l1++;
	tmp = tmp->next;
    }

    tmp = list2;
    while(tmp != NULL)
    {
	l2++;
	tmp = tmp->next;
    }

    if(l1 > l2)
    {
	diff = l1 - l2;
	bigger = list1;
	smaller = list2;
    }
    else
    {
	diff = l2 - l1;
	bigger = list2;
	smaller = list1;
    }

    count = 0;
    start = bigger;
    prev = NULL;
    while(count < diff)
    {
	count++;
	prev = bigger;
	bigger = bigger->next;
    }

    root2 = add_list(smaller, bigger, &carry);

    prev->next = NULL;
    root1 = add_util(start, &carry);
    tmp = root1;
    while(tmp->next != NULL)
	tmp = tmp->next;

    tmp->next = root2;
    prev->next = bigger;

    if(carry > 0)
    {
	node = get_node();
	node->data = carry;
	node->next = root2;
	return node;
    }

    return root1;
}


int
main()
{
    node_t *root1 = get_node_data(1);
    root1->next = get_node_data(2);
    root1->next->next = get_node_data(4);
    root1->next->next->next = get_node_data(7);

    node_t *root2 = get_node_data(9);
    root2->next = get_node_data(8);
    root2->next->next = get_node_data(9);

    node_t *root = add_two_list(root1, root2);
    print_list(root);

    root = add_two_list(root2, root1);
    print_list(root);

    return 0;
}
