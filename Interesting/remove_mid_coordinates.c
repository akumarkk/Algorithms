#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node_
{
    int x,y;
    struct node_ *next;
}node_t;

node_t *
remove_mid_nodes(node_t *root)
{
    node_t *head, *tmp, *prev;

    if(root == NULL || root->next == NULL)
	return root;

    tmp = head = prev = root;
    while(root->next != NULL)
    {
	if(root->x == root->next->x)
	{
	    while(root->next && root->x == root->next->x)
	    {
		prev = root;
		root = root->next;
	    }
	    
	    if(root->next == NULL)
		tmp->next = root;
	    else
		tmp->next = root;
	    tmp = tmp->next;
	    //tmp = prev->next;
	    //prev = tmp;
	}
	else if(root->y == root->next->y)
	{
	    while(root->next && root->y == root->next->y)
	    {
		prev = root;
		root = root->next;
	    }

	    if(root->next == NULL)
		tmp->next = root;
	    else
		tmp->next = root;
	    tmp = tmp->next;
	    //tmp = prev->next;
	    //prev = tmp;
	}
    }

    return head;
}

void
print_list(node_t *root)
{
    while(root != NULL)
    {
	printf("(%d, %d) -->", root->x, root->y);
	root = root->next;
    }
    printf("( )\n");
}

node_t *get_node(int x, int y)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->x = x;
    tmp->y = y;
    tmp->next = NULL;

    return tmp;
}

int
main()
{
    node_t *root = get_node(40, 5);
    root->next = get_node(20, 5);
    root->next->next = get_node(10, 5);
    root->next->next->next = get_node(10, 8);
    root->next->next->next->next  = get_node(10, 10);
    root->next->next->next->next->next  = get_node(3, 10);
    root->next->next->next->next->next->next  = get_node(1, 10);
    root->next->next->next->next->next->next->next  = get_node(0, 10);

    print_list(root);

    root = remove_mid_nodes(root);
    printf("After removing mid nodes...\n");
    print_list(root);

    return 0;
}

