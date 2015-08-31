#include <stdio.h>

void
print_matrix(int m[][3], int row, int col)
{
    int i=0, j=0;
    for(i=0; i<row; i++)
    {
	for(j=0; j<col; j++)
	{
	    printf("%d  ", m[i][j]);
	}
	printf("\n");
    }
}

int
main()
{
    int A[3][3]={{1,2,3},{4,5, 6},{7,8,9}};
    print_matrix(A, 3, 3);

    return 0;
}
