#include <stdio.h>
#include <stdlib.h>

//1:19 AM
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


node_t *
get_lca(node_t *root, node_t **lca, int key1, int key2)
{
    node_t *left=NULL, *right=NULL;

    //printf("Processing node[%d] \n", root?root->data:-9999);
    if(root == NULL)
	return NULL;

    left = get_lca(root->left, lca, key1, key2);
    if(*lca)
	return *lca;

    right = get_lca(root->right, lca, key1, key2);
    if(*lca)
	return *lca;

    if( (left && right) ||
	    (left && (root->data == key1 || root->data == key2)) ||
	    (right && (root->data == key1 || root->data == key2)))
    {
	*lca = root;
	return root;
    }

    if(root->data == key1 || root->data == key2)
	return root;

    return left?left:right;
}

int
main()
{
    node_t *lca = NULL;
    node_t *root = get_node(3);
    root->left = get_node(1);
    root->right = get_node(5);
    root->right->right = get_node(8);

    node_t *tmp = get_lca(root, &lca, 1, 8);
    printf("LCA[1, 8] = %d\n", lca?lca->data:-8989);

    lca = NULL;
    get_lca(root, &lca, 1, 5);
    printf("LCA[1, 5] = %d\n", lca?lca->data:-8989);

    lca = NULL;
    get_lca(root, &lca, 1, 3);
    printf("LCA[1, 3] = %d\n", lca?lca->data:-8989);

    lca = NULL;
    get_lca(root, &lca, 8, 5);
    printf("LCA[8, 5] = %d\n", lca?lca->data:-8989);

    return 0;
}
