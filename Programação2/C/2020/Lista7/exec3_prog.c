#include <stdio.h>

int main()
{
    int i=7, j=5, c=2;
    int *p;
    int **q;
    p=&i;
    q=&p;
    c= **q+j;
    printf("i=%d, j=%d, p=%d, q=%d, c=%d", i, j, *p, **q, c);
    return 0;
}
//result i=7, j=5, p=7, q=7, c=12