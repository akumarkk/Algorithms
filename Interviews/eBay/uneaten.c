#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


long
uneaten_leaves( )
{
    int *A = NULL;
    bool *leaves = NULL;
    int	  k=0;
    long  N=0;
    long  uneaten=0;
    long i, j;

    printf("# of leaves : ");
    scanf("%ld", &N);
    leaves = malloc(sizeof(bool) * N+1);

    printf("# of caterpillers : ");
    scanf("%d", &k);
    A = malloc(sizeof(int) * k);

    printf("Jump Numbers : ");
    for(i=0; i<k; i++)
	scanf("%d", &A[i]);

    for(i=0; i<N; i++)
	leaves[i] = false;

    for(i=0; i<k; i++)
    {
	for(j=A[i]; j<=N; )
	{
	    leaves[j] = true;
	    j = j + A[i];
	}
    }

    for(i=1; i<=N; i++)
    {
	if(leaves[i] == false)
	    uneaten++;
    }
    return uneaten;
}


int
main()
{
    int ret = uneaten_leaves();
    printf("# of uneaten leaves : %d\n", ret);

    return ret;
}
