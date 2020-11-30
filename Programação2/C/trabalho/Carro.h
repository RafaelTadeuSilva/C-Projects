#include "Marca.h"

struct Carro
{
    struct Marca marca;
    int ano;
    char cor[20];
    int kmAtual;
    int estaAlugado;
    float valorKm;
};

//Funcao para mostrar dados de um carro específico
void imprimeDetalhesCarro(struct Carro carro)
{
    printf("\nMarca: %s\nAno: %d\nCor: %s\nKM Atual: %d\nEsta Alugado: %s\nValor por Diaria: %.2f\nValor por KM rodado: %.2f\n", carro.marca.nome, carro.ano, carro.cor, carro.kmAtual, carro.estaAlugado == 0 ? "Nao" : "Sim", carro.marca.valDiaria, carro.valorKm);
};

//Funcao para listar todos os carros cadastrados
void listaCarros(struct Carro *carros, int tamanho)
{
    if (tamanho == 0)
        printf("\nLista de Carros Vazia!");
    else
        for (int i = 0; i < tamanho; i++)
        {
            imprimeDetalhesCarro(carros[i]);
        }
}

//Solicita dados para criação de um novo Carro
void cadastraCarro(struct Carro *carros, int *tamanho, struct Marca *marcas, int tamMarcas)
{
    char marca[20];
    int marcaIndex = -1;
    if (tamMarcas == 0)
        printf("\nCadastre uma Marca antes de cadastrar um Carro!\n");
    else
    {
        do
        {
            printf("\nInforme o nome da Marca do carro (-1 para listar marcas): ");
            scanf("%s", marca);
            if (strcmp(marca, "-1") == 0)
                listaMarcas(marcas, tamMarcas);
            else
            {
                marcaIndex = buscaMarcaNome(marcas, tamMarcas, marca);
                if (marcaIndex == -1)
                    printf("\nMarca não encontrada!");
                else
                    carros[*tamanho].marca = marcas[marcaIndex];
            }
        } while (marcaIndex == -1);

        printf("Digite o Ano de Fabricação: ");
        scanf("%d", &carros[*tamanho].ano);
        printf("Digite a Cor do Carro: ");
        scanf("%s", carros[*tamanho].cor);
        printf("Digite a KM Atual do Carro: ");
        scanf("%d", &carros[*tamanho].kmAtual);
        printf("Digite o Valor por KM Rodado: ");
        scanf("%f", &carros[*tamanho].valorKm);
        carros[*tamanho].estaAlugado = 0;
        (*tamanho)++;
    }
}

//Solicita o indice para imprimir seus dados
int buscaCarroCodigo(struct Carro *carros, int tamanho)
{
    int index = 0;
    printf("Digite o Codigo do Carro: ");
    scanf("%d", &index);
    if (index < 0 || index > tamanho - 1)
    {
        printf("Valor fora do intervalo!");
        return -1;
    }
    imprimeDetalhesCarro(carros[index]);
    return index;
}

// //Funcao para mudar endereco do carro
// void mudaEndereco(struct Carro *carro)
// {
//     int cpf = 0;

//     printf("Digite o novo Endereco: ");
//     scanf("%s", carro->endereco);
//     printf("\nEndereco alterado com sucesso!\n");
// }

//Mostra Opções que o usuário pode escolher
void imprimeMenuCarro()
{
    system("clear");

    printf("-----------Menu Carros-----------");
    printf("\n|  1 - Cadastrar Novo Carro      |");
    printf("\n|  2 - Buscar Carro por Codigo   |");
    // printf("\n|  3 - Alterar Endereco         |");
    printf("\n|  4 - Listar Todos os Carros    |");
    printf("\n|  0 - Voltar                    |");
    printf("\n----------------------------------");
    printf("\nDigite sua opcao: ");
}

//Funcao para gerenciar opção escolhida
void opcoesCarro(struct Carro *carros, int *tamanho, struct Marca *marcas, int tamMarcas, FILE *fp)
{
    int opcao = 0;

    //Mostra o Menu, espera a entrada da opção
    //até que seja digitado 0 para voltar ao Menu Principal
    do
    {
        system("clear");
        imprimeMenuCarro();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastraCarro(carros, tamanho, marcas, tamMarcas);
            break;
        case 2:
            buscaCarroCodigo(carros, *tamanho);
            break;
        // case 3:
        //     mudaEndereco(carros);
        //     break;
        case 4:
            listaCarros(carros, *tamanho);
            break;
        default:
            break;
        }
        //Pausa o programa até o usuário teclar enter
        //Não mostra se a opção escolhida foi 0 - Voltar 
        if(opcao!=0){
            imprimePause();
        }
    } while (opcao != 0);
}
