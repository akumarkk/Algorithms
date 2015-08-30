#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node_
{
    int	    data;
    struct node_ *left;
    struct node_ *right;
}node_t;

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}


void
get_max_leaf(node_t *root, int sum, node_t **max_leaf, int *max_sum)
{
    if(root == NULL)
	return;

    /* pass the values to descendants */
    sum = sum + root->data;

    /*If leaf, check for max value and update accordingly */
    if(root->left == NULL && root->right == NULL)
    {
	if(sum > *max_sum)
	{
	    *max_sum = sum;
	    *max_leaf = root;
	}
    }

    get_max_leaf(root->left, sum, max_leaf, max_sum);
    get_max_leaf(root->right, sum, max_leaf, max_sum);
}

int
print_path(node_t *root, node_t *leaf)
{
    if(root == NULL)
	return false;

    if(root == leaf || print_path(root->left, leaf) || print_path(root->right, leaf))
    {
	printf("[%d]	", root->data);
	/* true will be returned for all the nodes in the path from root to leaf */
	return true;
    }

    return false;
}

int
main()
{
    node_t  *max_leaf = NULL;
    int	    max_sum = 0;

    node_t *root = get_node(10);
    root->left = get_node(30);
    root->right = get_node(40);
    root->right->left = get_node(100);
    root->left->left = get_node(50);
    root->left->right = get_node(60);

    get_max_leaf(root, 0, &max_leaf, &max_sum);
    print_path(root, max_leaf);
    printf("\n\n");

    return 0;
}

