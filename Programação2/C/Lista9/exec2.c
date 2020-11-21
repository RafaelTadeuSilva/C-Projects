#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct xxVenda
{
    char nomeCliente[30];
    char produtos[10][30];
    char data[10];
    float valorTotal;
    int condPagamento;
}Venda;

void imprimeMenu()
{
    printf("---------------------------Menu---------------------------");
    printf("\n|   1 - Cadastrar uma nova venda                         |");
    printf("\n|   2 - Imprimir uma venda                               |");
    printf("\n|   3 - Imprimir todas as vendas                         |");
    printf("\n|   4 - Apresentar media das vendas                      |");
    printf("\n|   5 - Apresentar vendas por condicao de pagamento      |");
    printf("\n|   6 - Sair                                             |");
    printf("\n----------------------------------------------------------");
    printf("\n\nDigite sua Opcao: ");
}

void printPause(){
  printf("\n\nTecle enter para continuar...\n");
  fpurge(stdin);
  getchar();
  system("clear");
}

void imprimeVendas(Venda *vendas, int tamanho, int condicao){
    for (int i = 0; i < tamanho; i++)
    {
        if (condicao == 0 || vendas[i].condPagamento == condicao){
            printf("\n\nVenda %d\n  Nome do Cliente: %s\n  Data da Venda: %s\n  Valor da Venda: R$ %.2f\n  Condicao de Pagamento: %d\n", i, vendas[i].nomeCliente, vendas[i].data, vendas[i].valorTotal, vendas[i].condPagamento);
            printf("\nLista de Produtos: ");
            
            for (int j = 0; j < 10; j++)
            {
                printf("\n  Item %d - %s", j, vendas[i].produtos[j]);
            }
        }
    }
}

int main()
{
    Venda vendas[50];
    
    int opcao;
    int contVendas = 0;
    float valor = 0;
    float media = 0;
    int num = 0;

    do
    {
        system("clear");

        imprimeMenu();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            system("clear");
            if (contVendas < 50)
            {
                printf("Cadastro de Venda: \n");
                printf("Digite o Nome do Cliente: ");
                scanf("%s", vendas[contVendas].nomeCliente);
                printf("Digite a Data: ");
                scanf("%s", vendas[contVendas].data);
                printf("Digite o Valor Total: ");
                scanf("%f", &vendas[contVendas].valorTotal);
                printf("Digite a Condicao de Pagamento: ");
                scanf("%d", &vendas[contVendas].condPagamento);

                for (int i = 0; i < 10; i++)
                {
                    printf("Digite o Nome do Produto %d: ",i);
                    scanf("%s", vendas[contVendas].produtos[i]);
                }
                
                contVendas++;
                
                printf("Venda cadastrada com sucesso!");
            }
            else
                printf("Limite de Vendas alcancado.\n");

            printPause();
            break;
        case 2:     
            system("clear");
            if (contVendas == 0)
                printf("Nenhuma Venda Cadastrada!");   
            else
            {
                printf("Informe a Venda que deseja buscar :\n");            
                scanf("%d", &num);
                if (num>=0 && num < contVendas)
                {
                    printf("\nVenda %d\n  Nome do Cliente: %s\n  Data da Venda: %s\n  Valor da Venda: R$ %.2f\n  Condicao de Pagamento: %d\n", num, vendas[num].nomeCliente, vendas[num].data, vendas[num].valorTotal, vendas[num].condPagamento);
                    printf("\nLista de Produtos: ");
                    for (int i = 0; i < 10; i++)
                    {
                        printf("\n  Item %d - %s", i, vendas[num].produtos[i]);
                    }
                }
            }
            printPause();
            break;
        case 3:
            system("clear");
            if (contVendas == 0)
                printf("Nenhuma Venda Cadastrada!");
            else{
                
                imprimeVendas(vendas, contVendas, 0);
            }
            printPause();
            break;
        case 4:
            system("clear");
            if (contVendas == 0)
                printf("Nenhuma Venda Cadastrada!");
            else
            {
                media = 0;
                for (int i = 0; i < contVendas; i++)
                {
                    media += vendas[i].valorTotal;
                }
                printf("Media do valor total das vendas: R$ %.2f", media/contVendas);
            }
            printPause();
            break;
        case 5:
            system("clear");

            if (contVendas == 0)
                printf("Nenhuma Venda Cadastrada!");
            else{
                printf("\nInforme a condicao de pagamento: ");
                scanf("%d", &num);
                if(num > 0){
                    imprimeVendas(vendas, contVendas, num);
                }
                else
                    printf("Condicao invalida!");
                
            }
            printPause();
            break;
        
        default:
            break;
        }

    } while (opcao != 6);
    printf("Fim da Execucao!");
    return 0;
}