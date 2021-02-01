#include<stdio.h>
#include "biblioteca.h"

int main()
{
    int var= 3;
    int v[10];
    printf("Soma: %d\n", soma(5,&var));

    printf("Var = %d\n", var);

    for (int i = 0; i < 10; i++)
    {
        v[i] = i*2;
    }
    
    funcaoTeste(v);
    return 0;
}
