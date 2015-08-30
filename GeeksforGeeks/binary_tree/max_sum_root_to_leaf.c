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

int
max(int a, int b)
{
    return a>b?a:b;
}

int
get_max_sum(node_t *root)
{
    if(root == NULL)
	return 0;

    if(root->left == NULL && root->right == NULL)
	return root->data;

    int left = get_max_sum(root->left);
    int right = get_max_sum(root->right);

    return root->data + max(left, right);
}



int
main()
{
    node_t *root = get_node(10);
    root->left = get_node(30);
    root->right = get_node(40);
    root->right->left = get_node(100);
    root->left->left = get_node(50);
    root->left->right = get_node(60);

    printf("Maximum sum is %d\n", get_max_sum(root));
    printf("\n\n");

    return 0;
}

