#include <stdio.h>
#include <stdlib.h>


typedef struct node_
{
    int		    data;
    struct node_    *left;
    struct node_    *right;
}node_t;

int
max(int a, int b)
{
    return a>b?a:b;
}

#define maximum(a, b)\
    do{\
	if(a > b)\
	    return a;\
	else\
	    return b;\
    }while(0)


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
get_max_path_sum(node_t *root, int *max_path_sum)
{
    int left, right, max_path;

    if(root == NULL)
	return 0;
    left  = get_max_path_sum(root->left, max_path_sum);
    right = get_max_path_sum(root->right, max_path_sum);

    max_path = max(root->data, root->data + max(left, right));
    *max_path_sum = max(*max_path_sum, root->data + left + right);

    return max_path;
}

int
main()
{
    node_t *root = get_node(1);
    root->left        = get_node(2);
    root->right       = get_node(10);
    root->left->left  = get_node(3);
    root->left->right = get_node(4);
    root->right->right = get_node(40);
    root->right->right->left   = get_node(100);
    root->right->left = get_node(30);
    root->right->left->right  = get_node(60);
    root->right->left->left  = get_node(50);    

    int max_path_sum = 0;
    int ret = get_max_path_sum(root, &max_path_sum);
    printf("MAX path sum = %d	    ret = %d\n", max_path_sum, ret);

    return 0;
}
