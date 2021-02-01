#include <stdio.h>

int main()
{
    int i=34, j;
    int *p;
    p=&i;
    (*p)++;
    j= *p+33;
    printf("i=%d, j=%d, p=%d", i, j, *p);
    return 0;
}
//resultado i=34, j=33, p=0
//