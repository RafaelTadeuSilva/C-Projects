#include <stdio.h>
#include <stdio.h>
#include "gado.h"

void imprimeMenu(int contCabecas)
{
    printf("\n\n------------------Menu-------------------");
    printf("\n|  1-Ler Vetor                          |");
    printf("\n|  2-Exibir Producao Leite              |");
    printf("\n|  3-Exibir Consumo Alimento            |");
    printf("\n|  4-Exibir Producao Leite após Abate   |");
    printf("\n|  5-Exibir Consumo Alimento após Abate |");
    printf("\n|  6-Exibir Quant Cabecas para Abate    |");
    printf("\n|  0-Sair                               |");
    printf("\n-----------------------------------------");
    printf("\nQuantidade Cabecas Cadastradas: %d", contCabecas);
    printf("\nDigite a opcao escolhida: ");
}

int main()
{
    int tamanho = 2000;
    int opcao = 0;
    int contCabecas = 0;

    struct Gado cabecas[tamanho];

    //inicia cabecas zeradas - evitar erro nas posicoes mais altas do vetor
    for (int i = 0; i < tamanho; i++)
    {
        cabecas[i].codigo = 0;
        cabecas[i].leite = 0;
        cabecas[i].alimento = 0;
        *cabecas[i].abate = 'N';
    }

    do
    {
        imprimeMenu(contCabecas);
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            lerVetor(cabecas, tamanho, &contCabecas);
            break;
        case 2:
            imprimeProducaoLeite(cabecas, tamanho);
            break;
        case 3:
            imprimeConsumoAlimento(cabecas, tamanho);
            break;
        case 4:
            imprimeProducaoLeiteAbate(cabecas, tamanho);
            break;
        case 5:
            imprimeConsumoAlimentoAbate(cabecas, tamanho);
            break;
        case 6:
            imprimeCabecasParaAbate(cabecas, tamanho);
            break;
        default:
            break;
        }

    } while (opcao != 0);
    printf("Fim da Execucao.");
    return 0;
}