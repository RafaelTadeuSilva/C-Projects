
#include <stdio.h>
#define L 2
#define C 2

int main()
{
    float m[L][C];
    float n[L][C];
    float resultado[L][C];
    float num;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("Digite um numero da matriz M: ");
            scanf("%f", &m[i][j]);
        }
    }
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("Digite um numero: ");
            scanf("%f", &n[i][j]);
            resultado[i][j] = m[i][j] + n[i][j];
        }
    }
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("%.2f    ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
