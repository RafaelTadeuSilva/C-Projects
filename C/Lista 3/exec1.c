#include <stdio.h>

int main()
{
    int vetor[3] = {0};
    int matriz[3][3] = {0} ;

    for (int i = 0; i < 3; i++)
    {
        printf("Digite um numero para o vetor: ");
        scanf("%d", &vetor[i]);
    }
    printf("\n");
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite um numero para a matriz: ");
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");
    printf("Matriz resultante:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ", matriz[i][j] * vetor[j]);
        }
        printf("\n");
    }
    return 0;
}