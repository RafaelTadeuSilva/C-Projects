struct Cliente
{
    long int cpf;
    char nome[30];
    char endereco[40];
};

//Funcao para mostrar dados de um cliente específico
void imprimeDetalhesCliente(struct Cliente cliente)
{
    printf("\nCPF: %ld\nNome: %s\nEndereco: %s\n", cliente.cpf, cliente.nome, cliente.endereco);
};

//Funcao para listar todos os clientes cadastrados
void listaClientes(struct Cliente *clientes, int tamanho)
{

    if (tamanho == 0)
        printf("\nLista de Clientes Vazia!");
    else
        for (int i = 0; i < tamanho; i++)
        {
            imprimeDetalhesCliente(clientes[i]);
        }
}

//Solicita dados para criação de um novo Cliente
void cadastraCliente(struct Cliente *clientes, int *tamanho)
{
    printf("Digite o CPF: ");
    scanf("%ld", &clientes[*tamanho].cpf);
    printf("Digite o nome: ");
    scanf("%s", clientes[*tamanho].nome);
    printf("Digite o endereco residencial: ");
    scanf("%s", clientes[*tamanho].endereco);    
}

//Solicita o CPF para efetuar a busca de um cliente e imprime seus dados
//retorna o indice do cliente encontrado ou -1 se não encontrar
int buscaClienteCPF(struct Cliente *clientes, int tamanho, long int cpf)
{
    if(cpf ==-1){
        printf("Digite o CPF do Cliente: ");
        scanf("%ld", &cpf);
    }
    for (int i = 0; i < tamanho; i++)
    {
        if (clientes[i].cpf == cpf)
        {
            // imprimeDetalhesCliente(clientes[i]);
            return i;
        }
    }
    // printf("\nCliente nao encontrado!\n");
    return -1;
}

void gravarClienteArquivo(struct Cliente cliente){
    FILE *fp = abrirArquivo("clientes.txt");

    if(fp!=NULL)
    {
        fprintf(fp, "%ld\n", cliente.cpf);
        fprintf(fp, "%s\n", cliente.nome);
        fprintf(fp, "%s\n\n", cliente.endereco);
        printf("Cliente gravado com Sucesso!");
        fclose(fp);
    }
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
    system("clear");
    printf("----------Menu Clientes----------");
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
    int index = 0;
    // abrirArquivo(fp, "/Users/Rafael/Faculdade/C-Projects/Programação2/C/trabalho/clientes.txt");
    // printf("%d", fprintf(fp, "%s", "teste2"));

    //Mostra o Menu, espera a entrada da opção
    //até que seja digitado 0 para voltar ao Menu Principal
    do
    {
        system("clear");
        imprimeMenuCliente();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastraCliente(clientes, tamanho);
            gravarClienteArquivo(clientes[*tamanho]);
            (*tamanho)++;
            break;
        case 2:
            index = buscaClienteCPF(clientes, *tamanho, -1);
            if(index == -1)
                printf("\nCliente não encontrado!");
            else
                imprimeDetalhesCliente(clientes[index]);
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
        //Pausa o programa até o usuário teclar enter
        //Não mostra se a opção escolhida foi 0 - Voltar 
        if(opcao!=0){
            imprimePause();
        }
    } while (opcao != 0);
}
