#include <stdio.h>

int ehPrimo(int m)
{
    int resultado = m <= 1 ? 0 : 1;
    for (int i = m - 1; i >= 2; i--)
    {
        if (m % i == 0)
        {
            resultado = 0;
            break;
        }
    }
    return resultado;
}

int main()
{
    int numero;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (ehPrimo(numero) == 1)
        printf("O numero %d eh primo!", numero);
    else
        printf("O numero %d nao eh primo!", numero);

    return 0;
}