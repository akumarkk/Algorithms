#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
set_row(int col, int mat[][col], int row)
{
    int i=0;

    for(i=0; i<col; i++)
	mat[row][i] = 0;
}


void 
set_col(int col, int mat[][4], int row)
{
    int i=0;
    
    printf("column = %d\n", col);
    printf("# of rows = %d\n", row);

    for(i=0; i<row; i++)
    {
	printf("Setting mat[%d][%d] = %d   to 0\n", i, col, mat[i][col]);
	mat[i][col] = 0;
    }
}

void
set_zero(int n, int mat[][n], int m)
{
    int *row, *col;

    int i=0, j=0;

    row = malloc(sizeof(int) * m);
    col = malloc(sizeof(int) * n);

    memset(row, '\0', sizeof(int)*m);
    memset(col, '\0', sizeof(int)*n);

    for(i=0; i<m; i++)
    {
	for(j=0; j<n; j++)
	{
	    if(mat[i][j] == 0)
	    {
		row[i] = 1;
		col[j] = 1;
	    }
	}
    }

    for(i=0; i<m; i++)
    {
	if(row[i])
	{
	    printf("Setting row = %d\n", i);
	    set_row(n, mat, i);
	}
    }

    for(j=0; j<n; j++)
    {
	if(col[j])
	{
	    printf("Setting column = %d\n", j);
	    set_col(j, mat, m);
	}
    }
    
        for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            printf("%d  ", mat[i][j]);
        printf("\n");
    }
        printf("\n");

}

void
print_matrix(int n, int mat[][n], int m)
{
    for(int i=0; i<m; i++)
    {
	for(int j=0; j<n; j++)
	{
	    printf("%d  ", mat[i][j]);
	}
	printf("\n");
    }
    printf("------ END ------\n");
}

int
main()
{
    int matrix[][4] = { {1, 2, 3, 4},
	{0, 1, 3, 4},
	{3, 5, 0, 10},
	{34, 56, 12, 56}};

    print_matrix(4, matrix, 4);
    set_zero(4, matrix, 4);

    for(int i=0; i<4; i++)
    {
	for(int j=0; j<4; j++)
	    printf("%d  ", matrix[i][j]);
	printf("\n");
    }

    print_matrix(4, matrix, 4);

    return 0;
}
