struct Cliente
{
    int cpf;
    char nome[30];
    char endereco[40];
};

//Funcao para mostrar dados de um cliente específico
void imprimeDetalhesCliente(struct Cliente cliente)
{
    printf("\nCPF: %d\nNome: %s\nEndereco: %s\n", cliente.cpf, cliente.nome, cliente.endereco);
};

//Funcao para listar todos os clientes cadastrados
void listaClientes(struct Cliente *clientes, int tamanho)
{

    if (tamanho == 0)
        printf("\nLista de Marcas Vazia!");
    else
        for (int i = 0; i < tamanho; i++)
        {
            imprimeDetalhesCliente(clientes[i]);
        }
}

//Solicita dados para criação de um novo Cliente
void cadastraCliente(struct Cliente *clientes, int *tamanho)
{
    printf("Digite o cpf: ");
    scanf("%d", &clientes[*tamanho].cpf);
    printf("Digite o nome: ");
    scanf("%s", clientes[*tamanho].nome);
    printf("Digite o endereco residencial: ");
    scanf("%s", clientes[*tamanho].endereco);
    (*tamanho)++;
}

//Solicita o CPF para efetuar a busca de um cliente e imprime seus dados
//retorna o indice do cliente encontrado ou -1 se não encontrar
int buscaClienteCPF(struct Cliente *clientes, int tamanho)
{
    int cpf = 0;
    printf("Digite o CPF do Cliente: ");
    scanf("%d", &cpf);
    for (int i = 0; i < tamanho; i++)
    {
        if (clientes[i].cpf == cpf)
        {
            imprimeDetalhesCliente(clientes[i]);
            return i;
        }
    }
    printf("\nCliente nao encontrado!\n");
    return -1;
}

// //Funcao para mudar endereco do cliente
// void mudaEndereco(struct Cliente *cliente)
// {
//     int cpf = 0;

//     printf("Digite o novo Endereco: ");
//     scanf("%s", cliente->endereco);
//     printf("\nEndereco alterado com sucesso!\n");
// }

//Mostra Opções que o usuário pode escolher
void imprimeMenuCliente()
{
    printf("--------Menu Clientes-----------");
    printf("\n|  1 - Cadastrar Novo Cliente   |");
    printf("\n|  2 - Buscar Cliente por CPF   |");
    // printf("\n|  3 - Alterar Endereco         |");
    printf("\n|  4 - Listar Todos os Clientes |");
    printf("\n|  0 - Voltar                   |");
    printf("\n---------------------------------");
    printf("\nDigite sua opcao: ");
}

//Funcao para gerenciar opção escolhida
void opcoesCliente(struct Cliente *clientes, int *tamanho)
{
    int opcao = 0;

    //Mostra o Menu, espera a entrada da opção
    //até que seja digitado 0 para voltar ao Menu Principal
    do
    {
        imprimeMenuCliente();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastraCliente(clientes, tamanho);
            break;
        case 2:
            buscaClienteCPF(clientes, *tamanho);
            break;
        // case 3:
        //     mudaEndereco(clientes);
        //     break;
        case 4:
            listaClientes(clientes, *tamanho);
            break;
        default:
            break;
        }

    } while (opcao != 0);
}
