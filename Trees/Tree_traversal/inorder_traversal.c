#include <stdio.h>
#include <stdlib.h>
// 5:41 PM

typedef struct node_
{
    int		data;
    struct node_    *left;
    struct node_    *right;
}node_t;


void
inorder_traversal(node_t *root)
{
    node_t *tmp, *curr, *prev;

    if(root == NULL)
	return;

    while(root != NULL)
    {
	if(root->left == NULL)
	{
	    printf("[%d]->", root->data);
	    root = root->right;
	}
	else
	{
	    prev = root->left;
	    /* Find inorder predecessor */
	    while(prev->right != NULL && prev->right!= root)
		prev = prev->right;
	    if(prev->right == NULL)
	    {
		prev->right = root;
		root = root->left;
	    }
	    else
	    {
		prev->right = NULL;
		printf("[%d]-->", root->data);
		root = root->right;
	    }
	}
    }
    return;
}

node_t *get_node(int data)
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
    node_t *root = get_node(4);
    root->left = get_node(2);
    root->left->left = get_node(1);
    root->left->right = get_node(3);
    root->right = get_node(6);
    root->right->left = get_node(5);
    root->right->right = get_node(7);

    inorder_traversal(root);
    printf("\n	END	\n");

    return 0;
}

