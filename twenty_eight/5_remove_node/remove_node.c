/* Time Complexity  :	O(n)
 * Space Complexity :	O(1)
 */
#include <stdio.h>
#include <stdlib.h>

/* Caution : Be causious while implementing this
 * It is easy to leave bugs
 */

typedef struct node_
{
    int		 data;
    struct node_ *next;
}node_t;

node_t *
remove_node(node_t *head, int rem)
{
    node_t	*tmp, *curr, *prev;

    printf("Node to remove = %d\n", rem);

    if(head == NULL)
	return head;

    prev = head;
    tmp = head->next;

    while(tmp != NULL)
    {
	curr = tmp;
	tmp = tmp->next;
	if(curr->data == rem)
	{
	    free(curr);
	    prev->next = tmp;
	}
	else
	{
	    /* Warning : prev is advanced only in case of non-deletion */
	    prev = curr;
	}
    }

    if(head->data == rem)
    {
	tmp = head;
	head = head->next;
	free(tmp);
    }

    return head;
}

node_t *
get_node(int data)
{
    node_t  *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

void
print_list(node_t *list)
{
    while(list != NULL)
    {
	printf("[%d]-->", list->data);
	list = list->next;
    }

    printf("[NULL]\n\n");
}



int
main()
{
    node_t *head = get_node(10);
    
    print_list(head);
    head = remove_node(head, 20);
    print_list(head);

    head = get_node(20);
    print_list(head);
    head = remove_node(head, 20);
    print_list(head);
    
    head = get_node(1);
    head->next = get_node(2);
    head->next->next = get_node(5);
    head->next->next->next = get_node(5);
    print_list(head);
    head = remove_node(head, 5);
    print_list(head);
   
    head = get_node(5);
    head->next = get_node(5);
    head->next->next = get_node(5);
    head->next->next->next = get_node(5);
    head->next->next->next->next = get_node(30);
    print_list(head);
    head = remove_node(head, 5);
    print_list(head); 

    return 0;
}    
