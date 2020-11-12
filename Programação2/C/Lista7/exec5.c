#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lin, col;
    float **M, **N;

    printf("Digite o numero de linhas: ");
    scanf("%d",&lin);
    printf("Digite o numero de colunas: ");
    scanf("%d",&col);

    M = malloc(lin*sizeof(float*));
    N = malloc(lin*sizeof(float*));

    for (int i = 0; i < lin; i++){
        M[i] = malloc(col*sizeof(int));
        N[i] = malloc(col*sizeof(int));
    }
    
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Digite o valor da posicao %d,%d da matriz M: ", i, j);
            scanf("%f", &M[i][j]);
        }
    }
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Digite o valor da posicao %d,%d da matriz N: ", i, j);
            scanf("%f", &N[i][j]);
        }
    }
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%.2f    ", M[i][j] + N[i][j]);
        }
        free(M[i]);
        free(N[i]);

        printf("\n");
    }
    
    free(M);
    free(N);

    return 0;
}
