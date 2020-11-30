#include "biblioteca.h"

void imprimeMenu(){
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
    FILE *fCliente;
    FILE *fAluguel;
    FILE *fCarro;
    FILE *fMarca;

    struct Cliente clientes[10];
    struct Aluguel alugueis[10];
    struct Carro carros[10];
    struct Marca marcas[10];

    int contClientes = 0;
    int contAlugueis = 0;
    int contCarros = 0;
    int contMarcas = 0;

    int opcao = 0;

    do
    {
        system("clear");
        imprimeMenu();
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            opcoesCliente(clientes, &contClientes, fCliente);
            break;
        case 2:
            opcoesMarca(marcas, &contMarcas, fMarca);
            break;
        case 3:
            opcoesCarro(carros, &contCarros, marcas, contMarcas, fCarro);  
            break;
        case 4:
            opcoesAluguel(alugueis, &contAlugueis, clientes, contClientes, carros, contCarros, fAluguel);  
            break;
        default:
            break;
        }
    } while (opcao != 0);
    printf("Fim da Execucao!");
    return 0;
}