#include <stdio.h>

int main()
{
    int opcao = 0;
    float notas[4];
    float pesos[4];
    float peso;
    float media;

    while (opcao != 3)
    {
        printf("Menu\n");
        printf("1- Media Aritmetica\n");
        printf("2- Media Ponderada\n");
        printf("3- Sair\n");
        printf("Digite a opcao desejada-> ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            media = 0;
            for (int i = 0; i < 3; i++)
            {
                printf("Digite uma nota: ");
                scanf("%f", &notas[i]);
                media += notas[i];
            }
            printf("A media aritmetica e: %.2f\n\n", media / 3);
        }
        else if (opcao == 2)
        {
            media = 0;
            peso = 0;
            for (int i = 0; i < 4; i++)
            {
                printf("Digite uma nota: ");
                scanf("%f", &notas[i]);
                printf("Digite o peso desta nota: ");
                scanf("%f", &pesos[i]);
                media += notas[i] * pesos[i];
                peso += pesos[i];
            }

            printf("A media ponderada e: %.2f\n\n", media / peso);
        }
        else if (opcao == 3)
        {
            printf("\nFim da Execucao\n");
            break;
        }
        else
        {
            printf("\nOpção digitada é inválida!\n");
        }
    }

    return 0;
}