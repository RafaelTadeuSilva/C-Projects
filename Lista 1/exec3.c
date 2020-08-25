#include <stdio.h>

int main()
{
    float custoFab, custoCons;
    printf("Exercicio 3\n");

    printf("Digite o custo de fabrica do carro: ");
    scanf("%f", &custoFab);

    custoCons = custoFab * 1.28 + custoFab * 1.45;

    printf("Custo ao consumidor: R$ %.2f", custoCons);

    return 0;
}