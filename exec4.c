#include <stdio.h>

int main()
{
    float n1, n2, maior;
    printf("Maior numero\n");
    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    maior = n1;
    if (n1 < n2)
    {
        maior = n2;
    }
    printf("Maior numero: %.3f:", maior);

    return 0;
}