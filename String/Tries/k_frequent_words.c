#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define DEBUG 1
#define debug(fmt,...)\
    do{\
	if(DEBUG)\
	    fprintf(stdout, "%s(%d) :	" fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__);\
    }while(0)

// Number of child nodes each node in trie can have
#define MAX 26
#define MAX_SIZE 256

#define swap1(a, b)\
    do{\
	if(a != b){\
	    a = a ^ b;\
	    b = a ^ b;\
	    a = a ^ b;\
	}\
    }while(0)

int
get_index(char ch)
{
    return tolower(ch) - 'a';
}


typedef struct trie_
{
    int	    freq;
    int	    heap_index;
    struct  trie_   *child[MAX];
}trie_t;

typedef struct heap_
{
    char    word[MAX_SIZE];
    int	    freq;
    trie_t  *trie_node;
}heap_t;

typedef struct heap_tree_
{
    // # of nodes in the tree
    int	    count;
    int	    capacity;
    heap_t  **node_list;
}heap_tree_t;

heap_tree_t *
heapify(heap_tree_t *heap, int start, int end);

void
dump_heap(heap_tree_t    *heap);

void
dump_heap_node(heap_t	*node)
{
    if(node == NULL)
    {
	debug("heap node is empty %s", "");
	return;
    }

    debug("word	= %s	freq = %d", node->word, node->freq);
    trie_t  *trie_node = node->trie_node;
    if(trie_node)
    {
	debug("trie frequencey = %d heap_index = %d", trie_node->freq, trie_node->heap_index);
    }
    else
	debug("trie_node is empty %s", "");

}

void
swap(heap_t *a, heap_t *b)
{
    heap_t  tmp = *a;
    *a = *b;
    *b = tmp;
}

heap_tree_t*
init_heap(int k)
{
    int		    i;
    heap_tree_t	    *tmp = malloc(sizeof(heap_tree_t));

    tmp->count = 0;
    tmp->capacity = k;
    //tmp->node_list = malloc(sizeof(heap_t ) * k);
    //memset((tmp->node_list), 0, sizeof(heap_t ) * k);

    //Lets allocate memory in such a way that array subscript notation can be used 
    // to access elements
    tmp->node_list = malloc(sizeof(heap_t *) * k);
    for(i=0; i<k; i++)
    {
	tmp->node_list[i] = malloc(sizeof(heap_t));
	memset(tmp->node_list[i], 0, sizeof(heap_t));
    }

    return tmp;
}


trie_t *
get_trie_node()
{
    int i;
    trie_t  *tmp = malloc(sizeof(trie_t));
    tmp->freq = 0;
    tmp->heap_index = -1;
    for(i=0; i<MAX; i++)
	tmp->child[i] = NULL;

    return tmp;
}

trie_t *
trie_insert(trie_t  *root, char *word)
{
    int i  = 0;
    int index;
    int len = strlen(word);

    for(i=0; i<len; i++)
    {
	index = get_index(word[i]);

	if(root->child[index] == NULL)
	{
	    root->child[index] = get_trie_node();
	}
	root = root->child[index];
    }

    (root->freq)++;
    debug("addes word = %s  frequency = %d", word, root->freq);

    return root;
}

heap_tree_t *
build_min_heap(heap_tree_t *heap)
{
    int i;
    int n = heap->count - 1;
    
    for(i=(n-1)/2; i>=0; i--)
	heap = heapify(heap, 0, i);

    
    debug("******* Build MinHeap ********%s", "");
    dump_heap(heap);
    return heap;
}

heap_tree_t *
heap_insert(
	heap_tree_t	*heap, 
	trie_t		*trie_root, 
	trie_t		*trie_node, 
	char		*word)
{
    debug("Adding word [%s]", word);
    //Check if trie_node exists or not
    if(trie_node->heap_index >= 0)
    {
	debug("[%s] already exist in minHeap", word);
	//Node already exists in heap tree
	(heap->node_list[trie_node->heap_index]->freq)++;
	debug("heap node frequency = %d", heap->node_list[trie_node->heap_index]->freq);
	heap = heapify(heap, 0, heap->count);
	debug("******* Modified existing heap node *******%s", ""); 
	dump_heap(heap);
    }
    else
    {
	//Node does not exist in heap tree
	if(heap->count < heap->capacity)
	{
	    debug("Adding heap node [%s]", word);
	    heap->node_list[heap->count]->trie_node = trie_node;
	    heap->node_list[heap->count]->freq = trie_node->freq;
	    strcpy(heap->node_list[heap->count]->word, word);

	    // update heap_index of trie_node
	    trie_node->heap_index = heap->count;
	    (heap->count)++;
	    build_min_heap(heap);
	}
	else
	{
	    if(heap->node_list[0]->freq < trie_node->freq)
	    {
		debug("Replacing root [%s] with trie_node [%s]", 
			heap->node_list[0]->word,
			word);
		//Warning : unlink the heap index in trie
		dump_heap_node(heap->node_list[0]);
		heap->node_list[0]->trie_node->heap_index = -1;
		heap->node_list[0]->trie_node = trie_node;
		heap->node_list[0]->freq = trie_node->freq;
		strcpy(heap->node_list[0]->word, word);
		
		heap = heapify(heap, 0, heap->count);
		debug("******* Exchanged root heap node *******%s", "");
		dump_heap(heap);
	    }
	}
    }

    return heap;
}

heap_tree_t *
heapify(heap_tree_t *heap, int start, int end)
{
    int	    min;
    int	    lchild = 2*start + 1;
    int	    rchild = 2*start + 2;
    heap_t  **node_list = heap->node_list;

    debug("heapify  start = %d	end = %d", start, end);

    while(start < end && (((2*start)+1) < end))
    {
	lchild = 2*start + 1;
	rchild = 2*start + 2;

	debug("lchild = %d  rchild = %d", lchild, rchild);

	//Warning : careful while comparing; compare frequencies not nodes
	if(rchild < end && (node_list[rchild]->freq < node_list[lchild]->freq))
	{
	    min = rchild;
	}
	else
	    min = lchild;

	debug("min = %d", min);
	if(node_list[start]->freq > node_list[min]->freq)
	{
	    //update the index on trie
	    node_list[start]->trie_node->heap_index = min;
	    node_list[min]->trie_node->heap_index = start;
	    swap(node_list[start], node_list[min]);
	    start = min;
	}
	else
	    break;
    }

    return heap;
}

void
dump_heap(heap_tree_t    *heap)
{
    int     count = heap->count;
    int     i;
    heap_t  **node_list = heap->node_list;

    debug("\n----------------- MIN HEAP ----------------- %s\n", "");
    for(i=0; (i<count) && (node_list[i]); i++)
    {
        debug("word = %s       frequency = [%d]\n", node_list[i]->word, node_list[i]->freq);
    }
    debug("----------------- MIN HEAP -----------------%s\n", "");
    return;
}

void
display_heap(heap_tree_t    *heap)
{
    int	    count = heap->count;
    int	    i;
    heap_t  **node_list = heap->node_list;

    printf("\n----------------- MIN HEAP -----------------\n");
    for(i=0; i<count; i++)
    {
	printf("word = %s	frequency = [%d]\n", node_list[i]->word, node_list[i]->freq);
    }
    printf("----------------- MIN HEAP -----------------\n");
    return;
}

int
main()
{
    char *words[] = {"Anil", "Utah", "uvce", "university", "Anil","utah", "anil", "uve", "university", "uve", "uve", "kodagu", "Slc"};
    
    int  n = 13, i;
    heap_tree_t	    *heap;
    trie_t	    *trie_node, *trie_root;

    // Dummy node designated as root
    trie_root = get_trie_node();
    heap = init_heap(3);

    for(i=0; i<n; i++)
    {
	debug("processing word = %s", words[i]);

	trie_node = trie_insert(trie_root, words[i]);
	heap = heap_insert(heap, trie_root, trie_node, words[i]);
    }

    display_heap(heap);

    return 0;
}
