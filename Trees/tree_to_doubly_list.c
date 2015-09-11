#include <stdio.h>
#include <stdlib.h>
// 5:41 PM

typedef struct node_
{
    int		data;
    struct node_    *left;
    struct node_    *right;
}node_t;


node_t *
tree_to_list(node_t *root)
{
    node_t *head = NULL;
    node_t *tmp, *curr, *prev;

    if(root == NULL)
	return NULL;

    while(root != NULL)
    {
	if(root->left == NULL && head == NULL)
	{
	    printf("HEAD [%d]->", root->data);
	    head = root;
	    prev = root;
	    root = root->right;
	}
	else if(root->left == NULL)
	{
	    printf("[%d]->", root->data);
	    root->left = prev;
	    prev = root;
	    root = root->right;
	}
	else
	{
	    prev = root->left;
	    /* Find inorder predecessor */
	    while(prev->right != NULL && prev->right!= root)
		prev = prev->right;
	    if((prev->right == NULL) && prev->right != root)
	    {
		prev->right = root;
		root = root->left;
	    }
	    else if(prev->right == root)
	    {
		root->left = prev;
		printf("[%d]-->", root->data);
		prev = root;
		root = root->right;
	    }
	}
    }
    printf("\n		END of conversion	\n");
    return head;
}

void
print_list(node_t *list)
{
    while(list != NULL)
    {
	printf("[%d]->", list->data);
	list = list->right;
    }
    printf("[NULL]\n");
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
    node_t *head = NULL;
    node_t *root = get_node(4);
    root->left = get_node(2);
    root->left->left = get_node(1);
    //root->left->right = get_node(3);
    root->right = get_node(6);
    //root->right->left = get_node(5);
    root->right->right = get_node(7);

    head = tree_to_list(root);
    print_list(head);
    printf("\n	END	\n");

    return 0;
}

