#include <stdio.h>

int
main()
{
    int a=100, b=200;
    int *p[2] ;

    p[0] = &a;
    p[1] = &b;

    int **ptr;
    ptr = &p[0];

    printf("%d   %d\n", **ptr, **(ptr+1));
    
    ptr = &p;
    printf("%d   %d\n", **ptr, **(ptr+1));
    return 0;
}
