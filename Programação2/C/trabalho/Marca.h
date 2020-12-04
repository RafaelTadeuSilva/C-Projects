struct Marca
{
    char nome[20];
    float valDiaria;
};

//Funcao para mostrar dados de uma marca específica
void imprimeDetalhesMarca(struct Marca marca)
{
    printf("\nNome: %s\nValor Diaria: R$ %.2f\n", marca.nome, marca.valDiaria);
};

//Funcao para listar todos as marcas cadastradas
void listaMarcas(struct Marca *marcas, int tamanho)
{
    if (tamanho == 0)
        printf("\nLista de Marcas Vazia!");
    else
        for (int i = 0; i < tamanho; i++)
        {
            imprimeDetalhesMarca(marcas[i]);
        }
}

//Solicita dados para criação de uma nova Marca
void cadastraMarca(struct Marca *marcas, int *tamanho)
{
    printf("Digite o nome da Marca: ");
    scanf("%s", marcas[*tamanho].nome);
    printf("Digite o valor da diaria: ");
    scanf("%f", &marcas[*tamanho].valDiaria);
}

//Solicita o Nome para efetuar a busca de uma marca e imprime seus dados
//retorna o indice da marca encontrado ou -1 se não encontrar
int buscaMarcaNome(struct Marca *marcas, int tamanho, char marca[20])
{
    char nome[20];
    if (strcmp(marca, "") == 0)
    {
        printf("Digite o nome da Marca: ");
        scanf("%s", nome);
    }
    else
        strcpy(nome, marca);
    for (int i = 0; i < tamanho; i++)
    {
        if (strcasecmp(marcas[i].nome, nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

// //Funcao para mudar o valor da diaria
// void mudaValDiaria(struct Marca *marca)
// {
//     float valDiaria = 0;

//     printf("Digite o novo Valor da Diaria: ");
//     scanf("%f", marca->valDiaria);
//     printf("\nValor da Diaria alterado com sucesso!\n");
// }

//Mostra Opções que o usuário pode escolher
void imprimeMenuMarca()
{
    system("clear");
    printf("-----------Menu Marcas-----------");
    printf("\n|  1 - Cadastrar Nova Marca     |");
    printf("\n|  2 - Buscar Marca por Nome    |");
    // printf("\n|  3 - Alterar Endereco         |");
    printf("\n|  4 - Listar Todas as Marcas   |");
    printf("\n|  0 - Voltar                   |");
    printf("\n---------------------------------");
    printf("\nDigite sua opcao: ");
}

void gravarMarcaArquivo(struct Marca marca)
{
    FILE *fp = abrirArquivo("marcas.txt");

    if (fp != NULL)
    {
        fprintf(fp, "%s\n", marca.nome);
        fprintf(fp, "%.2f\n\n", marca.valDiaria);
        printf("Marca gravada com Sucesso!");
        fclose(fp);
    }
}

//Funcao para gerenciar opção escolhida
void opcoesMarca(struct Marca *marcas, int *tamanho)
{
    int opcao = 0;
    int index = 0;
    //Mostra o Menu, espera a entrada da opção
    //até que seja digitado 0 para voltar ao Menu Principal
    do
    {
        system("clear");
        imprimeMenuMarca();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastraMarca(marcas, tamanho);
            gravarMarcaArquivo(marcas[*tamanho]);
            (*tamanho)++;
            break;
        case 2:
            index = buscaMarcaNome(marcas, *tamanho, "");
            if (index == -1)
                printf("\nMarca não encontrada!");
            else
                imprimeDetalhesMarca(marcas[index]);

            break;
        // case 3:
        //     mudaValDiaria(marcas);
        //     break;
        case 4:
            listaMarcas(marcas, *tamanho);
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
