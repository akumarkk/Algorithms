#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
private static int[][] rotateMatrixBy90Degree(int[][] matrix, int n) {
		for (int layer = 0; layer < n / 2; layer++) {
			int first = layer;
			int last = n - 1 - layer;
			for (int i = first; i < last; i++) {
				int offset = i - first;
				int top = matrix[first][i];
				matrix[first][i] = matrix[last - offset][first];
				matrix[last - offset][first] = matrix[last][last - offset];
				matrix[last - offset][last] = matrix[i][last];
				matrix[i][last] = top;
			}
		}
		System.out.println("Matrix After Rotating 90 degree:-");
		printMatrix(matrix, n);
		return matrix;

	}
*/


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

/* In each rotation, 
 * - it is rotating 4 items
 * - so it needs n/4 iterations 
 * - It does it for n/2 rows in each iteration
 * For 5x5 Matrix
 *  0,0	    0,1	    0,2
 *  1,0	    1,1	    1,2
 *  2,0	    2,1	    2,2
 */
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
