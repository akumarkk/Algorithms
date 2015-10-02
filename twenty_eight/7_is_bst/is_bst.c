/* Warning  :	Directly checking left and right nodes results in incorrect result.
 *		because this approach does not verify for the grand parents and ancestors
 */

/* Solution :
 * Do in-order traversal of all the nodes
 * Check if they are in ascending order. If not in order, it is **NOT** a BST
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct node_
{
    int	    data;
    struct node_    *left;
    struct node_    *right;
}node_t;

bool
is_bst(node_t *root, int min, int max)
{
    //printf("processing [%d]	min = %d	max = %d\n", root?root->data:-999999, min, max);

    if(root == NULL) 
	    // Warning : Checking for leaf node is not required.
	    // If we do this here, it will miss verifying leaf for BST
	    //|| (root->left == NULL && root->right == NULL))
	return true;

    if(root->data < min || root->data > max)
    {
	printf("data = %d   min = %d	max = %d\n", root->data, min, max);
	return false;
    }

    return (is_bst(root->left, min, root->data) &&
	    is_bst(root->right, root->data, max));
}

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

int
main()
{
    node_t *root = get_node(3);
    root->left = get_node(2);
    root->left->left = get_node(1);
    root->left->right = get_node(4);
    root->right = get_node(5);

    bool ret = is_bst(root, INT_MIN, INT_MAX);
    if(ret)
	printf("BST\n");
    else
	printf("NOT A BST\n");

    root->data = 5;
    root->right->data = 50;
    ret = is_bst(root, INT_MIN, INT_MAX);
    if(ret)
        printf("BST\n");
    else
        printf("NOT A BST\n");
 
    return 0;
}

