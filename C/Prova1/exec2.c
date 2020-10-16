#include <stdio.h>

int main()
{
    float vetor[20];
    float maior = 0;
    int posicao = 0;

    for (int i = 0; i < 20; i++)
    {
        printf("Digite um valor: ");
        scanf("%f", &vetor[i]);
    }

    for (int i = 0; i < 20; i++)
    {
        if(i == 0 || maior <= vetor[i]){
            maior = vetor[i];
            posicao = i;
        }
    }

    printf("Maior Elemento do Array: %.2f\n", maior);
    printf("Posicao: %d\n", posicao);

    return 0;
}