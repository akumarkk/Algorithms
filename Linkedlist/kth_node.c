/* Returns kth node from the end:
 * There are two ways to do this:
 * 1. Non-recursive solution
 * 2. recusive solution
 *	last node will return NUll
 */

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
kth_node(node_t *root, int k)
{
    int	    count=1;
    node_t  *runner = root, *ptr=root;
    
    if(root == NULL)
	return NULL;

    while(count < k)
    {
	count++;
	runner = runner->next;
    }

    while(runner->next != NULL)
    {
	runner = runner->next;
	ptr = ptr->next;
    }
    return ptr;
}

node_t *
kth_node_recursive(node_t *root, int k, int *count)
{
    if(root == NULL)
	return NULL;
    
    node_t *tmp = kth_node_recursive(root->next,k, count);
    *count = *count + 1;

    if(*count == k)
	return root;
    return tmp;
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
    root->next->next = get_node(30);
    root->next->next->next = get_node(40);
    root->next->next->next->next = get_node(50);
    root->next->next->next->next->next = get_node(60);
    root->next->next->next->next->next->next = get_node(70);
    root->next->next->next->next->next->next->next = get_node(80);

    print_list(root);
    node_t *tmp = kth_node(root, 3);
    printf("Kth node is [%d]\n", tmp->data);

    print_list(root);
    tmp = kth_node_recursive(root, 3, &count);
    printf("Kth node is [%d]\n", tmp->data);
    printf("Expected Kth node is [60]\n");

    return 0;
}
