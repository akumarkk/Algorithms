#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
spiral_matrix(int **mat, int row, int col)
{
    int i, j;
    int r_start = 0, r_end = row;
    int c_start = 0, c_end = col;

   while(r_start < r_end && c_start < c_end)
   {
      // print first row
      for(j = c_start; j < c_end; j++)
      {
	 printf("%d ", mat[r_start][j]);
      }
     r_start++;

    // print last column
    for(i=r_start; i<r_end; i++)
    {
	printf("%d ", mat[i][c_end-1]);
    }
    c_end--;

    //Print last row
    // There is no check for r_start and r_end here. So check for r_start and r_end
    if(r_start < r_end)
    {
	for(j = c_end-1; j >= c_start; j--)
	{
	    printf("%d ", mat[r_end-1][j]);
	}
    }
    r_end--;

    //Print first column in reverse direction
    if(c_start < c_end)
    {
	for(i = r_end-1; i>= r_start; i--)
	{
	    printf("%d ", mat[i][c_start]);
	}
    }
    //We printed first column, So increment c_start to indicate that
    c_start++;

   }
}


int
main()
{
    int i, j;
    int r, c;
    int **mat = NULL;

    while(1)
    {
	printf("\n<row> <col>	:   ");
	scanf("%d%d", &r, &c);

	mat = malloc(sizeof(int *) * r);
	for(i=0; i<r; i++)
	{
	    mat[i] = malloc(sizeof(int) * c);
	    printf("<%d row> : ", i);

	    for(j=0; j<c; j++)
		scanf("%d", &mat[i][j]);
	}

	spiral_matrix(mat, r, c);
    }
    return 0;
}


