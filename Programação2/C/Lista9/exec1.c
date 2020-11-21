#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct xxAcao
{
    char nomeCompanhia[30];
    char areaAtuacao[20];
    float valorAtual;
    float valorAnterior;
    float porcentagem;
}Acao;

void imprimeMenu()
{
    printf("------------------Menu------------------");
    printf("\n|   1 - Cadastrar uma nova acao        |");
    printf("\n|   2 - Imprimir acoes                 |");
    printf("\n|   3 - Imprimir acoes abaixo valor    |");
    printf("\n|   4 - Apresentar media acoes         |");
    printf("\n|   5 - Apresentar desvio padrao       |");
    printf("\n|   6 - Atualizar valor acao           |");
    printf("\n|   7 - Sair                           |");
    printf("\n----------------------------------------");
    printf("\n\nDigite sua Opcao: ");
}

void printPause(){
  printf("\n\nTecle enter para continuar...\n");
  fpurge(stdin);
  getchar();
  system("clear");
}

void imprimeAcoes(Acao *acoes, int tamanho, float valor){
    for (int i = 0; i < tamanho; i++)
    {
        if (valor == 0 || acoes[i].valorAtual < valor)
            printf("\nCompanhia: %s\n  Area Atuacao: %s\n  Valor: R$ %.2f\n  Valor Anterior: R$ %.2f\n  Porcentagem de Variacao: %.2f%%\n", acoes[i].nomeCompanhia, acoes[i].areaAtuacao, acoes[i].valorAtual, acoes[i].valorAnterior, acoes[i].porcentagem);
    }
}

double desvioPadrao(Acao *acoes, int tamanho){
    float media = 0;
    float soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        media += acoes[i].valorAtual;
    }
    media = media/tamanho;

    for (int i = 0; i < tamanho; i++)
    {
        soma += pow(acoes[i].valorAtual-media,2);

    }
    return sqrt(soma/(tamanho-1));
}

int main()
{
    Acao acoes[30];
    
    int opcao;
    int contAcoes = 0;
    float valor=0;
    float media = 0;
    int num=0;

    do
    {
        system("clear");
     
        imprimeMenu();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            system("clear");
            if (contAcoes < 30)
            {
                printf("Cadastro de Acao: \n");
                printf("Digite o Nome da Companhia: ");
                scanf("%s", acoes[contAcoes].nomeCompanhia);
                printf("Digite a Area de Atuacao: ");
                scanf("%s", acoes[contAcoes].areaAtuacao);
                printf("Digite o Valor da Acao: ");
                scanf("%f", &acoes[contAcoes].valorAtual);
                contAcoes++;
                printf("Acao cadastrada com sucesso!");
            }
            else
                printf("Limite de Acoes alcancado.\n");

            printPause();
            break;
        case 2:     
            system("clear");
            if (contAcoes == 0)
                printf("Nenhuma Acao Cadastrada!");   
            else
            {            
                printf("Listando Acoes Cadastradas:\n");
                imprimeAcoes(acoes, contAcoes, 0);
            }
            printPause();
            break;
        case 3:
            system("clear");
            if (contAcoes == 0)
                printf("Nenhuma Acao Cadastrada!");
            else{
                printf("Informe um valor para a busca: ");
                scanf("%f", &valor);
                imprimeAcoes(acoes, contAcoes, valor);
            }
            printPause();
            break;
        case 4:
            system("clear");
            if (contAcoes == 0)
                printf("Nenhuma Acao Cadastrada!");
            else
            {
                media= 0;
                for (int i = 0; i < contAcoes; i++)
                {
                    media += acoes[i].valorAtual;
                }
                printf("Media do valor atual das acoes: R$ %.2f", media/contAcoes);
            }
            printPause();
            break;
        case 5:
             system("clear");

            if (contAcoes == 0)
                printf("Nenhuma Acao Cadastrada!");
            else
                printf("Desvio padrao das acoes: %.2f", desvioPadrao(acoes, contAcoes));
            printPause();
            break;
        
        case 6:
            system("clear");

            if (contAcoes == 0)
                printf("Nenhuma Acao Cadastrada!");
            else{
                printf("\nAtualizar Valor de Acao");
                printf("\nInforme o numero da acao que deseja atualizar: ");
                scanf("%d", &num);
                if(num >=0 && num <contAcoes){
                    printf("Informe a porcentagem para atualizacao: ");
                    
                    scanf("%f", &acoes[num].porcentagem);
                    acoes[num].valorAnterior = acoes[num].valorAtual;
                    acoes[num].valorAtual += acoes[num].valorAtual * acoes[num].porcentagem / 100;
                    printf("Acao atualizada com sucesso!");
                }
                else
                    printf("Acao invalida!");
                
            }
            printPause();
            break;
        default:
            break;
        }

    } while (opcao != 7);
    printf("Fim da Execucao!");
    return 0;
}