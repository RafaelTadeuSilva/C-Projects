#include <stdio.h>

void lerDados(int *vetor)
{
    for (int i = 0; i < 20; i++)
    {
        printf("Digite o numero da posição %d: ", i);
        scanf("%d", &vetor[i]);
    }
}

int main()
{
    int vetor[20];
    lerDados(vetor);

    for (int i = 0; i < 20; i++)
    {
        if (i < 19)
        {
            printf("%d, ", vetor[i]);
        }
        else
        {
            printf("%d\n", vetor[i]);
        }
    }

    return 0;
}
