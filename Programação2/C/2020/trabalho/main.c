#include "biblioteca.h"

void imprimeMenu(){
    system("cls");

    printf("--------Menu Principal-----------");
    printf("\n|  1 - Clientes                 |");
    printf("\n|  2 - Marcas                   |");
    printf("\n|  3 - Carros                   |");
    printf("\n|  4 - Aluguel                  |");
    printf("\n|  0 - Sair                     |");
    printf("\n---------------------------------");
    printf("\nDigite sua opcao: ");
}

int main()
{
    //Cria vetores para serem utilizados pelo programa
    struct Cliente clientes[30];
    struct Aluguel alugueis[30];
    struct Carro carros[30];
    struct Marca marcas[30];

    //Contadores para auxiliar as operações
    int contClientes = 0;
    int contAlugueis = 0;
    int contCarros = 0;
    int contMarcas = 0;

    int opcao = 0;

    //Mostra o Menu, espera a entrada da opção
    //até que seja digitado 0 para finalizar o programa
    do
    {
        imprimeMenu();
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            //mostra menu de Clientes
            opcoesCliente(clientes, &contClientes);
            break;
        case 2:
            //mostra menu de Marcas
            opcoesMarca(marcas, &contMarcas);
            break;
        case 3:
            //mostra menu de Carros
            opcoesCarro(carros, &contCarros, marcas, contMarcas);  
            break;
        case 4:
            //mostra menu de Algueis
            opcoesAluguel(alugueis, &contAlugueis, clientes, contClientes, carros, contCarros);  
            break;
        default:
            break;
        }
    } while (opcao != 0);
    printf("Fim da Execucao!");
    return 0;
}