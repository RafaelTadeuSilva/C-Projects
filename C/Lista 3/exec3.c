#include <stdio.h>

int main()
{
    int opcao = 0;
    int ponderada[4];
    int pesos[4];

    while (opcao != 3)
    {
        printf("Menu\n");
        printf("1- Média Aritmética\n");
        printf("2- Média Ponderada\n");
        printf("3- Sair\n");
        printf("Digite a opção desejada-> ");
        scanf("%d",&opcao);
        
        if (opcao == 1)
        {
            float media = 0;
            float nota = 0;

            for (int i = 0; i < 3; i++)
            {
                printf("Digite uma nota: ");
                scanf("%f",&nota);
                media += nota;
            }
            printf("A média aritmética é: %d\n\n", media/3);
        }
    }

    return 0;
}