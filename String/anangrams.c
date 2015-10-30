#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 50
typedef struct words_
{
    char    *word;
    int	    index;
}words_t;

typedef struct word_array_
{
    words_t	*warray;
    int		size;
}word_array_t;

int
char_compare(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

int
str_compare(const void *a, const void *b)
{
    return strcmp( (char *)(((words_t *)a)->word), ( (char *)(((words_t *)b)->word)));
}


void
print_anagrams(char *words[], int size)
{
    int i;
    word_array_t *word_array = malloc(sizeof(word_array_t));
    word_array->size = size;
    // Alloc mem for size # of words
    word_array->warray = malloc(sizeof(words_t) * size);

    words_t	 *warray = word_array->warray;

    for(i=0; i<size; i++)
    {
	printf("processing word	    :	%s\n", words[i]);
	// 1. Allocing mem here
	warray[i].word = strdup(words[i]);
	warray[i].index = i;
    }

    for(i=0; i<size; i++)
    {
	printf("sorting word = %s   len = %d\n", warray[i].word, strlen(warray[i].word));
	qsort(warray[i].word, strlen(warray[i].word), sizeof(char), char_compare);
    }

    qsort(warray, word_array->size, sizeof(warray[0]), &str_compare);

    for(i=0; i<size; i++)
    {
        printf("word = %s    Index = %d\n", warray[i].word, warray[i].index);
    }

    for(i=0; i<size; i++)
    {
	printf("%s	", words[warray[i].index]);
    }

}

int
main()
{
    char *words[] = {"Anil", "lnAi", "cat", "dog", "tac", "god", "act", "nil", "ac", "go" };

    print_anagrams(words, 10);

    return 0;
}
