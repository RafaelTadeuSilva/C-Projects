#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimeMenu(int *opcao){
  printf("=========================Menu=============================");
  printf("\n|| Digite 1 para Informar os nomes.                   ||");
  printf("\n|| Digite 2 para Imprimir os nomes.                   ||");
  printf("\n|| Digite 3 para Pesquisar um nome.                   ||");
  printf("\n|| Digite 4 para Imprimir os nomes iniciados em vogal ||");
  printf("\n|| Digite 5 para finalizar o programa.                ||");
  printf("\n========================================================");
  printf("\nDigite sua opção: ");
  scanf("%d", opcao);
}

void printPause(){
  printf("\nTecle enter para continuar...\n");
  fpurge(stdin);
  getchar();
  system("clear");
}


int main(){
    int lin;
    int opcao =  0;
    char **nomes = NULL;
    nomes = malloc(lin*sizeof(char*));
    
    printf("Informe o tamanho do array: ");
    scanf("%d", &lin);

    for (int i = 0; i < lin; i++)
    {
       nomes[i] = malloc(sizeof(char)*30);
    }
    imprimeMenu(&opcao);
    printPause();
    lerNomes(nomes, lin);
    
    imprimirNomes(nomes, lin);

    printf("\nDigite um nome para pesquisar: ");

    char nomePesq[30];
    scanf("%s", nomePesq);
    if(pesquisaNome(nomePesq, nomes, lin)==1)
        printf("1 - encontrado");
    else
        printf("0 - não encontrado");

    imprimirNomesIniciadoVogais(nomes, lin);

    printf("\n\n");
}