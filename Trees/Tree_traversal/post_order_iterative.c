#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG 0

#define debug(fmt, ...)\
do{\
    if(DEBUG)\
	fprintf(stderr, "%s(%d):	"fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__);\
}while(0)


typedef struct node_
{
    int	    data;
    struct node_    *left;
    struct node_    *right;
}node_t;


typedef struct stack_
{
    node_t	**list;
    int		top;
    int		max_size;
}mystack_t;

mystack_t	*stack;

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = data;
    return tmp;
}

void
init_stack(mystack_t **stack)
{
    *stack  = malloc(sizeof(mystack_t));
    mystack_t *tmp = *stack;
    tmp->top = -1;
    tmp->list = malloc(20 *sizeof(node_t *));
    tmp->max_size = 20;
    debug("Initialized teh stack successfully %s", "");

}

void
push(mystack_t *stack, node_t *node)
{
    if(stack->top == stack->max_size)
    {
	printf("Stack overflow\n");
	return;
    }

    stack->list[++(stack->top)] = node;
    debug("Pushed [%d] into stack", node->data);
}

node_t *
peek(mystack_t *st)
{
    if(stack->top == -1)
	return NULL;
    debug("Peek [%d]", (stack->list[stack->top])->data);
    return stack->list[stack->top];
}

node_t *
pop(mystack_t *stack)
{
    if(stack->top == -1)
    {
	printf("Stack empty\n");
	return NULL;
    }

    debug("Popped [%d]", (stack->list[stack->top])->data);
    return stack->list[(stack->top)--];
}

bool
is_empty(mystack_t *st)
{
    if(stack->top < 0)
	return true;
    return false;
}

/* Idea :
 * 1. push root onto stack
 * 2. Now in while loop until stack is empty
 *	a. peek an item
 *	b. If left and right is not visited, push node->left onto stack
 *	c. Else if node->right is not visited, push node->right onto stack
 *	d. If both of them are visited, print the node, pop it from stack, store this pointer as visited_node
 *
 * KEY IDEA :
 *  To store the context of previously visited node, previously visited node is stored in "visited_node".
 *  If left node is visited, visited_node will have left node pointer
 *  If right is visited, it will have right node pointer. It indicates that both left and right are visited
 */

void
postorder_traversal(node_t *root)
{
    node_t	*visited_node = NULL, *node;
    
    init_stack(&stack);

    if(root == NULL)
	return;


    push(stack, root);
    while(!is_empty(stack))
    {
	node = peek(stack);
	debug("Processing node [%d]", node->data);

	if(node->left && (visited_node != node->left) &&  (visited_node != node->right ))
	{
	    debug("pushing [%d]", node->left->data);
	    push(stack, node->left);
	    continue;
	}

	if(node->right && visited_node != node->right)
	{
	    debug("pushing right child [%d]", node->right->data);
	    push(stack, node->right);
	    continue;
	}
	printf("--------[%d] ---------\n", node->data);
	pop(stack);
	visited_node = node;
	
    }
}

int
main()
{
    node_t  *root = get_node(1);
    root->left = get_node(2);
    root->right = get_node(3);
    root->left->left = get_node(4);
    root->left->right = get_node(5);
    root->right->left = get_node(6);
    root->right->right = get_node(7);

    postorder_traversal(root);
    return 0;
}



