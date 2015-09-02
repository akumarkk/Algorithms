#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG 1
#define debug(fmt,...)\
    do{\
	if(DEBUG){\
	    fprintf(stdout, "%s(%d): " fmt, __FUNCTION__, __LINE__, __VA_ARGS__);\
	}\
    }while(0)

typedef struct node_
{
    int	data;
    struct node_ *next;
}node_t;

void
print_list(node_t *head);

node_t * 
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

node_t *
reverse_list(node_t *head)
{
    node_t *prev, *root, *tmp;

    printf("Given list	:   ");
    print_list(head);

    if(head == NULL || head->next == NULL)
    {
	printf("Head is empty!\n");
	return NULL;
    }

    prev = root = head;
    head = head->next;
    root->next = NULL;
    while(head != NULL)
    {
	tmp = head;
	head = head->next;
	tmp->next = prev;
	prev = tmp;
    }

    printf("Reversed list   :");
    print_list(tmp);
    return tmp;
}

bool
is_palindrome(node_t *head)
{
    node_t *prev, *slow, *fast, *slow_root;
    if(head == NULL)
	return true;

    printf("%s	:   given list ::\n", __FUNCTION__);
    print_list(head);

    slow = fast = head;
    while(fast != NULL && fast->next != NULL)
    {
	prev = slow;
	slow = slow->next;
	fast = fast->next->next;
    }
    if(fast && fast->next == NULL)
    {
	/* Odd number of nodes */
	prev = slow;
	slow = slow->next;
    }

    slow = slow_root = reverse_list(slow);
    while(slow != NULL)
    {
	if(slow->data != head->data)
	{
	    prev->next = reverse_list(slow_root);
	    return false;
	}
	slow = slow->next;
	head = head->next;
    }

    prev->next = reverse_list(slow_root);
    return true;
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
    root->next->next = get_node(330);
    root->next->next->next = get_node(110);
    root->next->next->next->next = get_node(110);
    root->next->next->next->next->next = get_node(230);
    root->next->next->next->next->next->next = get_node(220);
    root->next->next->next->next->next->next->next = get_node(10);

    print_list(root);
    node_t *tmp = reverse_list(root);
    print_list(tmp);

    int ret = is_palindrome(tmp);
    printf("Given list palindrome test   :	%d\n", ret);
    print_list(tmp);
    return 0;
}
