#include <stdio.h>

void imprimeVetor(int *result)
{
    for (int i = 0; i < 5; i++)
    {
        if (i > 0)
            printf(", ");
        printf("%d", result[i]);
    }
}

int *multiplicacao(int *x, int *y)
{
    static int result[5] = {0};
    for (int i = 0; i < 5; i++)
    {
        result[i] = x[i] * y[i];
    }

    return result;
}

int *soma(int *x, int *y)
{
    static int result[5] = {0};
    for (int i = 0; i < 5; i++)
    {
        result[i] = x[i] + y[i];
    }

    return result;
}

int diferenca(int *x, int *y)
{
    int cont = 0;
    for (int i = 0; i < 5; i++)
    {
        int exist = 0;
        for (int j = 0; j < 5; j++)
        {
            if (x[i] == y[j])
            {
                exist = 1;
                break;
            }
        }
        if (exist == 0)
        {
            if (cont > 0)
                printf(", ");
            printf("%d", x[i]);
            cont++;
        }
    }
    return cont;
}

int main()
{
    int x[5] = {0};
    int y[5] = {0};
    int *result;
    int qtDif = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Digite um valor para o array X: ");
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Digite um valor para o array Y: ");
        scanf("%d", &y[i]);
    }
    printf("\nSoma entre x e y: ");
    imprimeVetor(soma(x, y));

    printf("\n\nMultiplicacao entre x e y: ");
    imprimeVetor(multiplicacao(x, y));

    printf("\n\nDiferenca entre x e y: ");
    qtDif = diferenca(x, y);
    if (qtDif == 0)
    {
        printf("Nenhum numero encontrado");
    }

    printf("\n\nUniao entre x e y: ");
    imprimeVetor(x);
    if (qtDif > 0)
    {
        printf(", ");
        diferenca(y, x);
    }

    return 0;
}