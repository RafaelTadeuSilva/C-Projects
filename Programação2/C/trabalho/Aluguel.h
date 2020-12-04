#include "Carro.h"
#include "Cliente.h"

struct Aluguel
{
    struct Carro *carro;
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
    printf("\n|  5 - Fim do Aluguel - Totalizar  |");
    printf("\n|  0 - Voltar                      |");
    printf("\n------------------------------------");
    printf("\nDigite sua opcao: ");
}

//Solicita dados para criação de um novo Aluguel
int cadastraAluguel(struct Aluguel *alugueis, int *tamanho, struct Cliente *clientes, int tamClientes, struct Carro *carros, int tamCarros)
{
    int result = 0;
    int carroIndex = -1;
    char carroPlaca[8];
    long int clienteCPF = -1;
    int clienteIndex = -1;
    if (tamCarros == 0)
        printf("\nCadastre um Carro antes do Aluguel!\n");
    else if (tamClientes == 0)
        printf("\nFaça o cadastro do Cliente antes do Aluguel!\n");
    else if (verificaCarrosDisponiveis(carros, tamCarros, 0) == 0)
        printf("\nTodos os carros já foram alugados!\n");
    else
    {
        do
        {
            printf("\nInforme a placa do Carro (-1 para listar carros disponiveis): ");
            scanf("%s", carroPlaca);
            if (strcmp(carroPlaca, "-1") == 0)
                verificaCarrosDisponiveis(carros, tamCarros, 1);
            else
            {
                carroIndex = buscaCarroPlaca(carros, tamCarros, carroPlaca);
                if (carroIndex == -1)
                    printf("\nPlaca não encontrada!");
                else if (carros[carroIndex].estaAlugado == 1)
                {
                    printf("\nCarro já foi alugado!\nEscolha outro.");
                    carroIndex = -1;
                }
                else
                    alugueis[*tamanho].carro = &carros[carroIndex];
                /* code */
            }
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
                printf("\nCliente não encontrado!");
                if (clienteIndex != -1)
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
        (*alugueis[*tamanho].carro).estaAlugado = 1;
        result = 1;
    }
    return result;
}
//Funcao para mostrar dados de um carro específico
void imprimeDetalhesAluguel(struct Aluguel aluguel)
{
    printf("\nData do Aluguel: %s\nCliente: %s\nDetalhes do Carro:\n   Placa: %s\n   Marca: %s\n", aluguel.data, aluguel.cliente.nome, (*aluguel.carro).placa, (*aluguel.carro).marca.nome);

    //Carro foi devolvido e
    if (aluguel.total != 0)
    {
        printf("KM Rodados: %d\nDias Alugados: %d\nTotal Pago: %.2f\n", aluguel.kmRodados, aluguel.diasAlugados, aluguel.total);
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
            printf("\nCodigo Aluguel: %d", i);
            imprimeDetalhesAluguel(alugueis[i]);
        }
}

void gravarAluguelArquivo(struct Aluguel aluguel)
{
    FILE *fp = abrirArquivo("alugueis.txt");

    if (fp != NULL)
    {
        fprintf(fp, "%ld\n", aluguel.cliente.cpf);
        fprintf(fp, "%s\n", aluguel.cliente.nome);
        // fprintf(fp, "%s\n", aluguel.carro.placa);
        fprintf(fp, "%s\n", (*aluguel.carro).marca.nome);
        fprintf(fp, "%s\n\n", aluguel.data);

        printf("Aluguel gravado com Sucesso!");
        fclose(fp);
    }
}

void fimAluguel(struct Aluguel *alugueis, int tamanho)
{
    int index = 0;
    index = buscaAluguelCodigo(alugueis, tamanho);
    if (index != -1)
    {
        if (alugueis[index].total > 0)
        {
            printf("\n\nAluguel já finalizado!\n\n");
        }
        else
        {
            printf("\nInforme a quantidade de Dias Alugados: ");
            scanf("%d", &alugueis[index].diasAlugados);
            printf("Informe a quantidade de KM Rodados: ");
            scanf("%d", &alugueis[index].kmRodados);
            alugueis[index].total = alugueis[index].diasAlugados * (*alugueis[index].carro).marca.valDiaria;
            alugueis[index].total += alugueis[index].kmRodados * (*alugueis[index].carro).valorKm;
            printf("\nValor Total do Aluguel: R$ %.2f\n\n", alugueis[index].total);
            (*alugueis[index].carro).kmAtual += alugueis[index].kmRodados;
            (*alugueis[index].carro).estaAlugado = 0;
        }
    }
}
//Funcao para gerenciar opção escolhida
void opcoesAluguel(struct Aluguel *alugueis, int *tamanho, struct Cliente *clientes, int tamClientes, struct Carro *carros, int tamCarros)
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
            if (cadastraAluguel(alugueis, tamanho, clientes, tamClientes, carros, tamCarros) == 1)
            {
                gravarAluguelArquivo(alugueis[*tamanho]);
                (*tamanho)++;
            }
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
        case 5:
            fimAluguel(alugueis, *tamanho);
        default:
            break;
        }
        //Pausa o programa até o usuário teclar enter
        //Não mostra se a opção escolhida foi 0 - Voltar
        if (opcao != 0)
        {
            imprimePause();
        }
    } while (opcao != 0);
}
