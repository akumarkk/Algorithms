#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
print_matrix(int *matrix, int m, int n)
{
    for(int i=0; i<m; i++)
    {
	for(int j=0; j<n; j++)
	{
	    printf("%d   ", *((matrix + (i*n)) + j) );
	}
	printf("\n");
    }
    printf("\n");
}


void
print(int **mat, int m, int n)
{
     for(int i=0; i<m; i++)
     {
	  for(int j=0; j<n; j++)
	  {
	      printf("%d ", mat[i][j]);
	  }
	  printf("\n");
     }
     printf("--- END ---\n");
}


int
main()
{
    int array[][4] = {{1, 2, 3, 4},
		    {5, 6, 7, 8},
		    {9, 10, 11, 12}};

    print_matrix((int *)array, 3, 4);

    int **m;
    m = malloc(sizeof(int *) * 3);

    int val = 10;
    for(int i=0; i<3; i++)
    {
	m[i] = malloc(sizeof(int) * 2);
	m[i][0] = val + i;
	m[i][1] = val + i +1;
	val++;
    }

    print(m, 3, 2);
    return 0;
}
