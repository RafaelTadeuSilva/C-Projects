#include <stdio.h>

int qtPares(int *vetor)
{
    int pares = 0;
    for (int i = 0; i < 15; i++)
    {
        if (vetor[i] % 2 == 0)
        {
            pares++;
        }
    }
    return pares;
}

int somaElementos(int *vetor)
{
    int soma = 0;
    for (int i = 0; i < 15; i++)
    {
        soma += vetor[i];
    }
    return soma;
}

int main()
{
    int vetor[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    printf("Quantidade de Pares: %d\n", qtPares(vetor));
    printf("Soma do Vetor: %d\n", somaElementos(vetor));
    return 0;
}