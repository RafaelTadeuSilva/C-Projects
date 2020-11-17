#include "exec1bib.h"

void imprimeMenu(int *opcao){
  printf("========================Menu============================");
  printf("\n|| Digite 1 para Informar os nomes.                   ||");
  printf("\n|| Digite 2 para Imprimir os nomes.                   ||");
  printf("\n|| Digite 3 para Pesquisar um nome.                   ||");
  printf("\n|| Digite 4 para Imprimir os nomes iniciados em vogal.||");
  printf("\n|| Digite 5 para finalizar o programa.                ||");
  printf("\n========================================================");
  printf("\nDigite sua opção: ");
  scanf("%d", opcao);
}

void printPause(){
  printf("\n\nTecle enter para continuar...\n");
  fpurge(stdin);
  getchar();
  system("clear");
}

int main(){
    int lin;
    int opcao =  0;
    char **nomes = NULL;
    nomes = malloc(lin*sizeof(char*));
    system("clear");
    
    do
    {
        printf("Informe o tamanho do array: ");
        scanf("%d", &lin);
        if (lin <= 0)
        {
            printf("tamanho inválido!");
            printPause();
        }
        
    } while (lin <= 0);
    
    
    for (int i = 0; i < lin; i++)
    {
       nomes[i] = (char*)malloc(sizeof(char)*30);
    }
    system("clear");
    
    do
    {
        imprimeMenu(&opcao);
        switch (opcao)
        {
        case 1:
            lerNomes(nomes, lin);
            printPause();
            break;
        case 2:
            imprimirNomes(nomes, lin);
            printPause();
            break;
        case 3:
            printf("\nDigite um nome para pesquisar: ");

            char nomePesq[30];
            scanf("%s", nomePesq);
            if(pesquisaNome(nomePesq, nomes, lin)==1)
                printf("1 - encontrado");
            else
                printf("0 - não encontrado");
            printPause();
            break;
        case 4:
            imprimirNomesIniciadoVogais(nomes, lin);
            printPause();
            break;
        default:
            break;
        }
    } while (opcao!=5);
    
    printf("\nFim da Execução.\n");

    return 0;
}