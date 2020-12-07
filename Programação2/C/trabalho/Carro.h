#include "Marca.h"

struct Carro
{
    char placa[8];
    struct Marca marca;
    int ano;
    char cor[20];
    int kmAtual;
    int estaAlugado; // 0 - Não Alugado, 1 - Alugado
    float valorKm;
};

//Funcao para mostrar dados de um carro específico
void imprimeDetalhesCarro(struct Carro carro)
{
    printf("\nPlaca: %s\nMarca: %s\nAno: %d\nCor: %s\nKM Atual: %d\nEsta Alugado: %s\nValor por Diaria: R$ %.2f\nValor por KM rodado: R$ %.2f\n", carro.placa, carro.marca.nome, carro.ano, carro.cor, carro.kmAtual, carro.estaAlugado == 0 ? "Nao" : "Sim", carro.marca.valDiaria, carro.valorKm);
};

//Funcao para listar todos os carros cadastrados
void listaCarros(struct Carro *carros, int tamanho)
{
    //Se a lista não estiver vazia, mostra todos os detalhes dos clientes
    if (tamanho == 0)
        printf("\nLista de Carros Vazia!");
    else
        for (int i = 0; i < tamanho; i++)
        {
            imprimeDetalhesCarro(carros[i]);
        }
}

//Funcao para verificar quantidade de carros não alugados
//Variável imprimeDetalhes 0 - Não imprimir, 1 - Imprimir
int verificaCarrosDisponiveis(struct Carro *carros, int tamanho, int imprimeDetalhes)
{
    int numDisponiveis = 0;
    for (int i = 0; i < tamanho; i++)
    {
        //Verifica se o carro não esta alugado
        if (carros[i].estaAlugado == 0)
        {
            //se imprimeDetalhes = 1, imprime os detalhes do carro
            if (imprimeDetalhes == 1)
                imprimeDetalhesCarro(carros[i]);
            
            //Incrementa a variável
            numDisponiveis++;
        }
    }
    //retorna o número de carros disponiveis
    return numDisponiveis;
}

//Funcao para escrever no arquivo carros.txt os dados informados
void gravarCarroArquivo(struct Carro carro)
{
    FILE *fp = abrirArquivo("carros.txt");

    //verifica se o arquivo foi aberto e grava os dados
    if (fp != NULL)
    {
        fprintf(fp, "Placa: %s\n", carro.placa);
        fprintf(fp, "Marca: %s\n", carro.marca.nome);
        fprintf(fp, "Ano fabricação: %d\n", carro.ano);
        fprintf(fp, "Cor: %s\n", carro.cor);
        fprintf(fp, "Km Atual: %d\n", carro.kmAtual);
        fprintf(fp, "Valor km rodado: R$ %.2f\n\n", carro.valorKm);

        printf("Carro gravado com Sucesso!");
        fclose(fp);
    }
}

//Solicita a Placa para efetuar a busca de um carro
//retorna o indice do carro encontrado ou -1 se não encontrar
int buscaCarroPlaca(struct Carro *carros, int tamanho, char *busca)
{
    for (int i = 0; i < tamanho; i++)
    {
        //Compara a placa informado com todos os carros
        if (strcasecmp(carros[i].placa, busca) == 0)
        {
            return i;
        }
    }
    return -1;
}

//Solicita dados para criação de um novo Carro
int cadastraCarro(struct Carro *carros, int tamanho, struct Marca *marcas, int tamMarcas)
{
    int result = 0;
    char placa[8];
    char marca[20];
    int marcaIndex = -1;

    //Se não existirem marcas cadastradas, não permite cadastrar um carro
    if (tamMarcas == 0)
        printf("\nCadastre uma Marca antes de cadastrar um Carro!\n");
    else
    {
        do
        {
            printf("\nInforme a Placa do Carro:");
            scanf("%s", placa);
            
            //Se existir um carro com a placa informada não permite o cadastro
            if (buscaCarroPlaca(carros, tamanho, placa) == -1)
                strcpy(carros[tamanho].placa, placa);
            else
                printf("\nJá existe um carro cadastrado com esta placa!\n");
        
        //enquanto não for digitada uma placa válida, pede nova placa
        } while (strcmp(carros[tamanho].placa, "") == 0);

        do
        {
            printf("\nInforme o nome da Marca do carro (-1 para listar marcas): ");
            scanf("%s", marca);
            
            //Se for digitado -1, lista todas as marcas cadastradas
            if (strcmp(marca, "-1") == 0)
                listaMarcas(marcas, tamMarcas);
            else
            {
                marcaIndex = buscaMarcaNome(marcas, tamMarcas, marca);
                
                //Verifica se a marca digitada existe
                if (marcaIndex == -1)
                    printf("\nMarca não encontrada!");
                else
                    carros[tamanho].marca = marcas[marcaIndex];
            }

        //enquanto não for digitada uma marca válida, pede nova marca
        } while (marcaIndex == -1);

        printf("Digite o Ano de Fabricação: ");
        scanf("%d", &carros[tamanho].ano);
        printf("Digite a Cor do Carro: ");
        scanf("%s", carros[tamanho].cor);
        printf("Digite a KM Atual do Carro: ");
        scanf("%d", &carros[tamanho].kmAtual);
        printf("Digite o Valor por KM Rodado: ");
        scanf("%f", &carros[tamanho].valorKm);
        carros[tamanho].estaAlugado = 0;
        result = 1;
    }
    return result;
}

//Mostra Opções que o usuário pode escolher
void imprimeMenuCarro()
{
    system("cls");

    printf("-----------Menu Carros-----------");
    printf("\n|  1 - Cadastrar Novo Carro      |");
    printf("\n|  2 - Buscar Carro por Placa    |");
    printf("\n|  3 - Listar Todos os Carros    |");
    printf("\n|  0 - Voltar                    |");
    printf("\n----------------------------------");
    printf("\nDigite sua opcao: ");
}

//Funcao para gerenciar opção escolhida
void opcoesCarro(struct Carro *carros, int *tamanho, struct Marca *marcas, int tamMarcas)
{
    int opcao = 0;
    int index = 0;
    char placa[8];
    //Mostra o Menu, espera a entrada da opção
    //até que seja digitado 0 para voltar ao Menu Principal
    do
    {
        imprimeMenuCarro();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            //se o cadastro for concluído com sucesso, grava os dados no arquivo
            if (cadastraCarro(carros, *tamanho, marcas, tamMarcas) == 1)
            {
                gravarCarroArquivo(carros[*tamanho]);
                (*tamanho)++;
            }
            break;
        case 2:
            printf("Digite a Placa do Carro: ");
            scanf("%s", placa);
            index = buscaCarroPlaca(carros, *tamanho, placa);
            
            //verifica se o carro foi encontrado
            if (index == -1)
                printf("\nPlaca não encontrada!");
            else
                imprimeDetalhesCarro(carros[index]);
            break;
        case 3:
            listaCarros(carros, *tamanho);
            break;
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
