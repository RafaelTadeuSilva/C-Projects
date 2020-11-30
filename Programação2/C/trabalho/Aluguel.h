#include "Carro.h"
#include "Cliente.h"

struct Aluguel
{
    struct Carro carro;
    struct Cliente cliente;
    char data[10];
    int diasAlugados;
    int kmRodados;
    float total;
};

//Mostra Opções que o usuário pode escolher
void imprimeMenuAluguel()
{
    system("clear");

    printf("------------Menu Alugueis-----------");
    printf("\n|  1 - Cadastrar Novo Aluguel      |");
    printf("\n|  2 - Buscar Aluguel por Codigo   |");
    // printf("\n|  3 - Alterar Endereco         |");
    printf("\n|  4 - Listar Todos os Alugueis    |");
    printf("\n|  0 - Voltar                      |");
    printf("\n------------------------------------");
    printf("\nDigite sua opcao: ");
}

//Solicita dados para criação de um novo Aluguel
void cadastraAluguel(struct Aluguel *alugueis, int *tamanho, struct Cliente *clientes, int tamClientes, struct Carro *carros, int tamCarros)
{
    int carroIndex = -1;
    long int clienteCPF = -1;
    int clienteIndex = -1;
    if (tamCarros == 0)
        printf("\nCadastre um Carro antes do Aluguel!\n");
    else if (tamClientes == 0)
        printf("\nFaça o cadastro do Cliente antes do Aluguel!\n");
    else
    {
        do
        {
            printf("\nInforme o código do Carro (-1 para listar carros): ");
            scanf("%d", &carroIndex);
            if (carroIndex == -1)
                listaCarros(carros, tamCarros);
            else if (carroIndex > tamCarros)
                printf("\nValor fora do intervalo!");
            else if (carros[carroIndex].estaAlugado == 1)
            {
                printf("\nCarro já foi alugado!\nEscolha outro.");
                carroIndex = -1;
            }
            else
                alugueis[*tamanho].carro = carros[carroIndex];
        } while (carroIndex == -1);
        do
        {
            printf("\nInforme o CPF do Cliente (-1 para listar clientes): ");
            scanf("%ld", &clienteCPF);
            if (clienteCPF == -1)
                listaClientes(clientes, tamClientes);
            else
            {
                clienteIndex = buscaClienteCPF(clientes, tamClientes, clienteCPF);
                if(clienteIndex != -1)
                    alugueis[*tamanho].cliente = clientes[clienteIndex];
            }
        } while (clienteIndex == -1);

        printf("Digite a Data do Aluguel: ");
        scanf("%s", alugueis[*tamanho].data);
        alugueis[*tamanho].diasAlugados = 0;
        alugueis[*tamanho].kmRodados = 0;
        alugueis[*tamanho].total = 0;
        // printf("Digite a quantidade de Dias Alugados: ");
        // scanf("%d", &alugueis[*tamanho].diasAlugados);
        // printf("Digite a quantidade KM Rodados: ");
        // scanf("%d", &alugueis[*tamanho].kmRodados);

        //Marca carro como alugado
        carros[*tamanho].estaAlugado = 1;

        (*tamanho)++;
    }
}
//Funcao para mostrar dados de um carro específico
void imprimeDetalhesAluguel(struct Aluguel aluguel)
{
    printf("\nData do Aluguel: %s\nCliente: %s\nDetalhes do Carro: marca: %s - ano fabricacao %d - cor %s", aluguel.data, aluguel.cliente.nome, aluguel.carro.marca.nome, aluguel.carro.ano, aluguel.carro.cor);
    
    //Carro foi devolvido e 
    if(aluguel.total != 0)
    {
        printf("\nKM Rodados: %d\nDias Alugados: %d\nTotal Pago: %.2f", aluguel.kmRodados, aluguel.diasAlugados, aluguel.total);
    }
};

//Solicita o indice para imprimir seus dados
int buscaAluguelCodigo(struct Aluguel *alugueis, int tamanho)
{
    int index = 0;
    printf("Digite o Codigo do Aluguel: ");
    scanf("%d", &index);
    if (index < 0 || index > tamanho - 1)
    {
        printf("Valor fora do intervalo!");
        return -1;
    }
    imprimeDetalhesAluguel(alugueis[index]);
    return index;
}

//Funcao para listar todos os carros cadastrados
void listaAlugueis(struct Aluguel *alugueis, int tamanho)
{
    if (tamanho == 0)
        printf("\nLista de Alugueis Vazia!");
    else
        for (int i = 0; i < tamanho; i++)
        {
            imprimeDetalhesAluguel(alugueis[i]);
        }
}

//Funcao para gerenciar opção escolhida
void opcoesAluguel(struct Aluguel *alugueis, int *tamanho, struct Cliente *clientes, int tamClientes, struct Carro *carros, int tamCarros, FILE *fp)
{
    int opcao = 0;

    //Mostra o Menu, espera a entrada da opção
    //até que seja digitado 0 para voltar ao Menu Principal
    do
    {
        system("clear");
        imprimeMenuAluguel();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastraAluguel(alugueis, tamanho, clientes, tamClientes, carros, tamCarros);
            break;
        case 2:
            buscaAluguelCodigo(alugueis, *tamanho);
            break;
        // case 3:
        //     mudaEndereco(carros);
        //     break;
        case 4:
            listaAlugueis(alugueis, *tamanho);
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
