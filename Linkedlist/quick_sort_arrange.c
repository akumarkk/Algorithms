#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int	    data;
    struct node_    *next;
}node_t;


node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

node_t *
quick_sort_arrange(node_t *head, int x)
{
    node_t *tmp,*new_head, *tail;
    new_head = tail = head;

    head = head->next;
    while(head != NULL)
    {
	tmp = head;
	head = head->next;
	if(tmp->data < x)
	{
	    tmp->next = new_head;
	    new_head = tmp;
	}
	else
	{
	    tail->next = tmp;
	    tail = tail->next;
	}
    }
    /* Warning: set terminal NUll pointer */
    tail->next = NULL;

    return new_head;
}

void
print_list(node_t *head)
{
    while(head != NULL)
    {
	printf("[%d]->", head->data);
	head = head->next;
    }
    printf("[NULL]\n");
}

int
main()
{
    int count=0;
    node_t *root = get_node(10);
    root->next = get_node(20);
    root->next->next = get_node(230);
    root->next->next->next = get_node(110);
    root->next->next->next->next = get_node(50);
    root->next->next->next->next->next = get_node(60);
    root->next->next->next->next->next->next = get_node(70);
    root->next->next->next->next->next->next->next = get_node(80);

    print_list(root);
    node_t *tmp = quick_sort_arrange(root, 145);

    print_list(tmp);
    return 0;
}
