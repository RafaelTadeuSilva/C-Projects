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
    //Se a lista não estiver vazia, mostra todos os detalhes dos clientes
    if (tamanho == 0)
        printf("\nLista de Clientes Vazia!");
    else
        for (int i = 0; i < tamanho; i++)
        {
            imprimeDetalhesCliente(clientes[i]);
        }
}

//Solicita dados para criação de um novo Cliente
void cadastraCliente(struct Cliente *clientes, int tamanho)
{
    printf("Digite o CPF: ");
    scanf("%ld", &clientes[tamanho].cpf);
    printf("Digite o nome: ");
    scanf("%s", clientes[tamanho].nome);
    printf("Digite o endereco residencial: ");
    scanf("%s", clientes[tamanho].endereco);    
}

//Solicita o CPF para efetuar a busca de um cliente
//retorna o indice do cliente encontrado ou -1 se não encontrar
int buscaClienteCPF(struct Cliente *clientes, int tamanho, long int cpf)
{
    for (int i = 0; i < tamanho; i++)
    {
        //Compara o cpf informado com todos os clientes
        if (clientes[i].cpf == cpf)
        {
            return i;
        }
    }
    return -1;
}

//Funcao para escrever no arquivo clientes.txt os dados informados
void gravarClienteArquivo(struct Cliente cliente){
    FILE *fp = abrirArquivo("clientes.txt");

    //verifica se o arquivo foi aberto e grava os dados
    if(fp!=NULL)
    {
        fprintf(fp, "CPF: %ld\n", cliente.cpf);
        fprintf(fp, "Nome: %s\n", cliente.nome);
        fprintf(fp, "Endereço: %s\n\n", cliente.endereco);
        printf("Cliente gravado com Sucesso!");
        fclose(fp);
    }
}

//Mostra Opções que o usuário pode escolher
void imprimeMenuCliente()
{
    system("clear");
    printf("----------Menu Clientes----------");
    printf("\n|  1 - Cadastrar Novo Cliente   |");
    printf("\n|  2 - Buscar Cliente por CPF   |");
    printf("\n|  3 - Listar Todos os Clientes |");
    printf("\n|  0 - Voltar                   |");
    printf("\n---------------------------------");
    printf("\nDigite sua opcao: ");
}

//Funcao para gerenciar opção escolhida
void opcoesCliente(struct Cliente *clientes, int *tamanho)
{
    int opcao = 0;
    int index = 0;
    long int cpf;

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
            cadastraCliente(clientes, *tamanho);
            gravarClienteArquivo(clientes[*tamanho]);
            (*tamanho)++;
            break;
        case 2:
            printf("Digite o CPF do Cliente: ");
            scanf("%ld", &cpf);
            index = buscaClienteCPF(clientes, *tamanho, cpf);
            
            //verifica se o cliente foi encontrado
            if(index == -1)
                printf("\nCliente não encontrado!");
            else
                imprimeDetalhesCliente(clientes[index]);
            break;
        case 3:
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
