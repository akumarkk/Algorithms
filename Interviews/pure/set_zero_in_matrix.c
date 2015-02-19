#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int
set_zero(int *mat, int row, int col)
{
    int *rows = malloc(sizeof(int) * row);
    int *cols = malloc(sizeof(int) * col);

    memset(rows, 0, sizeof(int)*row);
    memset(cols, 0, sizeof(int)*col);

    int i=0, j=0;

    for(i=0; i<row; i++)
    {
	for(j=0; j<col; j++)
	{
	    if( *((mat + row*i) +j) == 0)
	    {
		cols[j] = true;
		rows[i] = true;
	    }
	}
    }

    for(i=0; i<row; i++)
    {
	if(rows[i] == true)
	{
	    for(j=0; j<col; j++)
		*((mat + row*i) +j) = 0;
		//mat[i][j] = 0;
	}
    }

    for(i=0; i<col; i++)
    {   
        if(cols[i] == true)
        {   
            for(j=0; j<col; j++)
		*((mat + row*j) +i) = 0;
                //mat[j][i] = 0;
        }   
    }   

    return 0;
}


int
main()
{
    int i=0, j=0;
    int array[][4] = { {1, 2, 0, 4},
		      {2, 0, 8, 9},
		      {23, 56, 34, 23},
		      {12, 34, 56, 21}};


    for(i=0; i<4; i++)
    {
	for(j=0; j<4; j++)
	    printf("%4d ", array[i][j]);
	printf("\n");
    }

    set_zero((int *)array, 4, 4);

    printf("\n After setting zero\n");
    for(i=0; i<4; i++)
    {   
        for(j=0; j<4; j++)
            printf("%4d ", array[i][j]);
        printf("\n");
    }

    return 0;
}
