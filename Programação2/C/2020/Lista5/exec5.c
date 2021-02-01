#include <stdio.h>
#include <string.h>

float conversor(float temperatura, char tipoDestino)
{
    if (tipoDestino == 'F')
        temperatura = (temperatura * 9 / 5) + 32;
    else
        temperatura = (temperatura - 32) / 9 * 5;
    return temperatura;
}
int main()
{
    int opcao;
    float temperatura;
    char tipo;
    do
    {
        printf("1-Converter para Farenheit\n2-Converter para Celsius\n0-Sair\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("Digite uma temperatura em Celsius: ");
            scanf("%f", &temperatura);
            printf("Temperatura em Farenheit: %0.2f \n\n", conversor(temperatura, 'F'));
            system("pause");
        }
        else if (opcao == 2)
        {
            printf("Digite uma temperatura em Farenheit: ");
            scanf("%f", &temperatura);
            printf("Temperatura em Celsius: %0.2f \n\n", conversor(temperatura, 'C'));
            system("pause");
        }
        else if (opcao != 0)
        {
            printf("Opcao digitada eh invalida\n\n");
            system("pause");
        }
        system("cls");

    } while (opcao != 0);
    printf("Fim da execucao.\n\n");
}