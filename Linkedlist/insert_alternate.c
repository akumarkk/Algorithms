#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1
#define debug(fmt,...)\
do{\
    if(DEBUG)\
	fprintf(stdout, "%s(%d):    " fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__);\
}while(0)

typedef struct node_
{
    int	    data;
    struct node_ *next;
}node_t;


void
print_list(node_t *list)
{
    while(list != NULL)
    {
	printf("[%d]-->", list->data);
	list = list->next;
    }
    printf("[NULL]\n");
}

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

node_t *
reverse(node_t *list)
{
    node_t	*head = list;
    node_t	*tmp, *prev = NULL;

    debug("Given List %s", "");
    print_list(list);

    while(list != NULL)
    {
	tmp = list;
	list = list->next;
	tmp->next = prev;
	prev = tmp;
    }
    debug("Reversed list    :	%s", "");
    print_list(prev);

    return prev;
}

int
count(node_t *list)
{
    int	    count = 0;

    while(list != NULL)
    {
	count++;
	list = list->next;
    }
    return count;
}

node_t *
rearrange(node_t *list)
{
    node_t  *head, *rev, *tmp, *curr, *prev;
    int	    cnt;

    head = list;
    if(list == NULL)
	return list;

    cnt = count(list);

    if(cnt % 2)
	cnt = (cnt / 2) + 1 ;
    else
	cnt = cnt/2 + 1;

    while (cnt > 0)
    {
	cnt--;
	prev = list;
	list = list->next;
    }

    prev->next = NULL;
    rev = reverse(list);
    curr = head;
    tmp = curr;
    curr = curr->next;
    while(curr != NULL && rev != NULL)
    {
	debug("processing   curr = [%d]	    rev = [%d]", curr->data, rev->data);
        tmp->next = rev;
        tmp = tmp->next;
        rev = rev->next;

	tmp->next = curr;
	tmp = tmp->next;
	curr = curr->next;
	//debug("curr [%d]    curr->next [%d]", tmp->data, tmp->next->data);
    }

    debug("returnign head [%d]", head->data);
    return head;
}
   

void
test()
{
    node_t *head = get_node(10);
    head->next = get_node(20);
    head->next->next = get_node(30);
    head->next->next->next = get_node(40);
    head->next->next->next->next = get_node(50);
    head->next->next->next->next->next = get_node(60);

    print_list(head);
    head = rearrange(head);
    printf("Rearranged list :\n");
    print_list(head);

    head = get_node(10);
    head->next = get_node(20);
    head->next->next = get_node(30);
    head->next->next->next = get_node(40);
    head->next->next->next->next = get_node(50);
    head->next->next->next->next->next = get_node(60);
    head->next->next->next->next->next->next = get_node(70);

    print_list(head);
    head = rearrange(head);
    printf("Rearranged list :\n");
    print_list(head);
}

int
main()
{
    test();
}
