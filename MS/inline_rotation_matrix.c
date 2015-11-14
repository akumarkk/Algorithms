#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void
print_matrix(int **a, int m, int n)
{
    int i, j;
    
    printf("\n");
    
    for(i=0; i<m; i++)
    {
	for(j=0; j<n; j++)
	{
	    printf("%d ", a[i][j]);
	}
	printf("\n");
    }
}


void
inline_rotation(int **a, int rows, int cols)
{
    int temp;
    int i, j;
    int n = rows;

    //Inline rotation can be performed only on square matrices
    if(rows != cols)
	return;

    // Rotate top row,  navigation = [i, j]
    // Rotate leftmost column, navigation = [n-j-1][i]
    // Rotate bottom row, navigation = [n-i-1][n-j-1]
    // Rotate rightmost column, navigation = [n-j-1][n-i-1]
    // n-i-1 = Last row/column

    // # of rotations = n/2
    for(i=0; i<rows/2; i++)
    {
	print_matrix(a, n, n);
	// Navigate from i to n/2
	for(j=0; j<(n+1)/2; j++)
	{
	    printf("Value of j = %d  i = %i\n", j, i);
	    printf("[i, j] = [%d, %d]\n", i, j);
	    printf("[n-j-1, i] = [%d, %d]\n", n-j-1, i);
	    printf("[n-i-1, n-j-1] = [%d, %d]\n", n-i-1, n-j-1);
	    printf("[j, n-i-1] = [%d, %d]\n", j, n-i-1);

	    temp = a[i][j];
	    a[i][j] = a[n-j-1][i];
	    a[n-j-1][i] = a[n-i-1][n-j-1];
	    a[n-i-1][n-j-1] = a[j][n-i-1];
	    a[j][n-i-1] = temp;
	    print_matrix(a, n, n);
	}
    }

    print_matrix(a, rows, cols);
}

int
main()
{
    int i,j;
    int **a;
    int n = 4;

    printf("<# of rows>  : ");
    scanf("%d", &n);

    a = malloc(sizeof(int *) * n);

    for(i=0; i<n; i++)
	a[i] = malloc(sizeof(int ) * n);

    for(i=0; i<n; i++)
	for(j=0; j<n; j++)
	    a[i][j] = i+j;

    print_matrix(a, n, n);
    inline_rotation((int **)a, n, n);

    return 0;
}
