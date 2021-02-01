#include <stdio.h>
int main()
{
  int matriz[5][5], linha =0, coluna = 0;
    for ( linha = 0; linha < 5; linha++)
    {
        for ( coluna = 0; coluna < 5; coluna++)
        {
            matriz[linha][coluna] = 0;
            if(linha == coluna)
                scanf("%d",&matriz[linha][coluna]);
        }
    }

    for ( linha = 0; linha < 5; linha++)
    {
        for ( coluna = 0; coluna < 5; coluna++)
        {
            printf("[ %d ] ", matriz[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}