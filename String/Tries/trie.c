#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

/* Algorithm:
 *  Each node can have 26 different alphabet. 
 *  freq indicates # of times each word appeared in the given text
 */
#define DEBUG 1
#define debug(fmt,...)\
    do{\
	if(DEBUG)\
	    fprintf(stdout, "%s(%d) :	" fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__);\
    }while(0)

#define MAX 26

typedef struct trie_
{
    int	    freq;
    struct  trie_ *child[MAX];
}trie_t;


int 
get_index(char ch)
{
    // Convert it into tolower() as we have only 26 children
    return tolower(ch) - 'a';
}


trie_t * 
get_trie_node(void)
{
    int	    i	 = 0;
    trie_t  *tmp = malloc(sizeof(trie_t));
    tmp->freq = 0;

    for(i = 0; i< MAX; i++)
	tmp->child[i] = NULL;
    return tmp;
}


trie_t *
insert_trie(trie_t *root, char *word)
{
    int	    i = 0, index;
    int	    len = strlen(word);
    trie_t  *org_root = root;

    debug("Inserting [%s] into trie", word);

    for(i = 0; i < len; i++)
    {
	index = get_index(word[i]);
	debug("processing char [%c] [%d]", word[i], index);

	if(root->child[index] == NULL)
	{
	    root->child[index] = get_trie_node();
	}
	root = root->child[index];
    }

    (root->freq)++;

    return org_root;
}

int 
search(trie_t *root, char *word)
{
    int i = 0;
    int index;
    int len = strlen(word);

    for(i = 0; i < len; i++)
    {
	index = get_index(word[i]);
	if(root->child[index] == NULL)
	    return -1;
	root = root->child[index];
    }

    return root->freq;
}


int
main()
{
    int ret = 0;
    // Dummy node to hold root
    trie_t *root = get_trie_node();

    char *words[] = {"Utah", "university", "anil", "uvce", "Utah", "welcome", "utah"};
    int  i;

    int n = 7;
    for(i=0; i< n; i++)
	root = insert_trie(root, words[i]);

    for(i = n-1; i>=0; i--)
    {
	printf("Checking for the word : %s\n", words[i]);
	ret = search(root, words[i]);
	printf("Word = %s	frequency = %d\n", words[i], ret);
    }

    char *s[] = {"UVCE", "California", "Bang", "uta"};
    n = 4;
    for(i = n-1; i>=0; i--)
    {
        printf("\nNew Checking for the word : %s\n", s[i]);
        ret = search(root, s[i]);
        printf("Word = %s       frequency = %d\n", s[i], ret);
    }

    return 0;
}



