#include <stdio.h>

typedef struct test_
{
    char name[10];
    int  id;
}test_t;

int
main()
{
    test_t *ptr;

    void **dptr;
    dptr = (test_t **)&ptr;

    printf("Diff = %d\n", (int)(dptr) - (int)(dptr+1));

    //dptr = (test_t [5] *) ptr;
    test_t t[5];
    dptr = (test_t (*)[2]) &t;

    printf("dptr = %lx\n", dptr);
    dptr = ((test_t (*)[2])dptr) + 1;
    printf("dptr = %lx\n", dptr);

    printf("Sizeof t = %d\n", sizeof(t));
    printf("Diff = %d\n", (int)(dptr) - (int)(dptr+1));

    return 0;
}
