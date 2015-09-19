#include <stdio.h>
#include <stdlib.h>

int **
rotate_matrix(int m, int n, int mat[][n])
{
    int **new_mat;
    int new_rows = n, new_cols = m;
    int n_row, n_col, row, col, i;

    new_mat = malloc(sizeof(int *) * new_rows);
    for(i=0; i<m; i++)
	new_mat[i] = malloc(sizeof(int) * new_cols);

    for(col=0, n_row=0; col < n; col++, n_row++)
    {
	for(row = m-1, n_col=0; row >= 0; row--, n_col++)
	{
	    new_mat[n_row][n_col] = mat[row][col];
	}
    }	

    return new_mat;
}

void
print_matrix_alloc(int m, int n, int **mat)
{
    int i, j;
    printf("\n\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void
print_matrix(int m, int n, int mat[][n])
{
    int i, j;
    printf("\n\n");
    for(i=0; i<m; i++)
    {
	for(j=0; j<n; j++)
	{
	    printf("%d ", mat[i][j]);
	}
	printf("\n");
    }
}

int
main()
{
    int mat[][3] = {{1, 2, 3}, {4, 5, 6}};
    int **new_matrix;

    printf("Original matrix :	");
    print_matrix(2, 3, mat);

    new_matrix = rotate_matrix(2, 3, mat);
    print_matrix_alloc(3, 2, new_matrix);

    return 0;
}
