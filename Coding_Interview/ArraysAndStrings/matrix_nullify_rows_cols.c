#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void
nullify_rows_cols(int **m, int n_rows, int n_cols)
{
    int i, j;
    int *rows = malloc(sizeof(int) * n_rows);
    int *cols = malloc(sizeof(int) * n_cols);

    memset(rows, 0, sizeof(int) * n_rows);
    memset(cols, 0, sizeof(int) * n_cols);

    for(i=0; i<n_rows; i++)
    {
	for(j=0; j<n_cols; j++)
	{
	    if(m[i][j] == 0)
	    {
		rows[i] = true;
		cols[j] = true;
	    }
	}
    }

    for(i=0; i<n_rows; i++)
    {
	if(rows[i] == true)
	{
	    for(j=0; j<n_cols; j++)
		m[i][j] = 0;
	}
    }

    for(j=0; j<n_cols; j++)
    {
	if(cols[j] == true)
	{
	    for(i=0; i<n_rows; i++)
		m[i][j] = 0;
	}
    }
    return;
}

#define ROWS 3
#define COLS 4

void
print_matrix(int **m, int n_rows, int n_cols)
{
    int i, j;

    printf("Printing matrix ...\n");
    for(i=0; i<n_rows; i++)
    {
	for(j=0; j<n_cols; j++)
	{
	    printf("%d	", m[i][j]);
	}
	printf("\n");
    }
}


int
main()
{
    int i, j;

    /* Make sure that memory is allocated for pointer, not for just integer
     * In some machines, pointers are 8 bytes where as integers are 4 bytes
     */
    int **matrix = malloc(sizeof(int *) * ROWS);
    
    for(i=0; i<ROWS; i++)
    {
	matrix[i] = malloc(sizeof(int) * COLS);
	printf("Creating n_row = %d	matrix[%d] = %x\n", i, i, matrix[i]);
	printf("Matrix(%x) = %x\n", &matrix[i], matrix[i]);

	printf("Acccessing matrix[%d][0]  Addr(%p) = Value(%d)\n", i, &matrix[i][0], matrix[i][0]);
	printf("Acccessing matrix[%d][1]  Addr(%p) = Value(%d)\n", i,&matrix[i][1], matrix[i][1]);
    }

    printf("Matrix construction in progress ...\n");

    for(i=0; i<ROWS; i++)
	for(j=0; j<COLS; j++)
	{
	    printf("Storing value [%d] at %x(matrix[%d][%d])\n", i*j, &matrix[i][j], i, j);
	    matrix[i][j] = i*j+1;
	}

    printf("Matrix construction successful!\n");

    matrix[1][1] = 0;
    matrix[1][2] = 0;
    print_matrix(matrix, ROWS, COLS);
    nullify_rows_cols(matrix, ROWS, COLS);
    print_matrix(matrix, ROWS, COLS);

    return 0;
}
