#include <stdio.h>

int main()
{
    float tempo, vel_med, rendimento, consumo;
    printf("Exercicio 5\n");

    printf("Informe o tempo da viagem em horas: ");
    scanf("%f", &tempo);
    
    printf("Informe a velocidade media em km/h: ");
    scanf("%f", &vel_med);

    printf("Informe o rendimento do carro em km/l: ");
    scanf("%f", &rendimento);

    consumo = (vel_med * tempo) / rendimento;

    printf("O consumo sera de : %.2f litros", consumo);

    return 0;
}