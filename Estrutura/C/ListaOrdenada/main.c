//Fabio 
//Rafael Tadeu da Silva
#include <stdio.h>
#include <stdlib.h>

#define NOVA_CELULA() ((TipoApontador) malloc(sizeof(TipoCelula)))

typedef struct
{
  int Chave;
} TipoItem;

typedef struct xxCelula *TipoApontador;

typedef struct xxCelula
{
  TipoItem item;
  TipoApontador Prox;
} TipoCelula;

typedef struct
{
  TipoApontador Primeiro;
  TipoApontador Ultimo;
}TipoLista;

void FLVazia(TipoLista *Lista){
  Lista->Primeiro = NOVA_CELULA();
  Lista->Ultimo = Lista->Primeiro;
  Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista){
  return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista){
  TipoApontador auxAnterior, auxProximo, aux;
  
  auxAnterior = Lista->Primeiro;
  auxProximo = auxAnterior->Prox;

  while ((auxProximo !=NULL) && (x.Chave > auxProximo->item.Chave))
  {
    auxAnterior = auxProximo;
    auxProximo = auxAnterior->Prox;
  } 

  if(auxProximo==NULL)
  {
    Lista->Ultimo->Prox = NOVA_CELULA();
    Lista->Ultimo = Lista->Ultimo->Prox; 
    Lista->Ultimo->item = x;
    Lista->Ultimo->Prox=NULL;
  }
  else
  {
    aux = auxProximo;
    auxProximo = NOVA_CELULA();
    auxProximo->item = x;
    auxProximo->Prox = aux;
    auxAnterior->Prox = auxProximo;
  }
  
  printf("\nChave inserida com sucesso");
}

void imprimeLista(TipoLista Lista){
  TipoApontador aux;
  aux = Lista.Primeiro->Prox;
  while (aux != NULL)
  {
    printf("Chave %d\n",aux->item.Chave);
    aux = aux->Prox;
  } 
}

void retira(int p, TipoLista *Lista, TipoItem *Item){
  TipoApontador aux, aux2;
  if(Vazia(*Lista)){
    printf("\nErro! Lista vazia.");
    return;
  }
  aux = Lista->Primeiro;
  while ((aux->Prox !=NULL) && (p!=aux->Prox->item.Chave))
    aux = aux->Prox;
  
  if(aux->Prox==NULL)
    printf("\nItem nao encontrado!");
  else
  {
    aux2 = aux->Prox;
    *Item = aux2->item;
    aux->Prox = aux2->Prox;
    if(aux->Prox == NULL){
      Lista->Ultimo = aux;
    }
    free(aux2);
    printf("\nChave removida com sucesso.");
  }  
}
void buscarChave(int x, TipoLista *Lista){
  TipoApontador aux;
  if(Vazia(*Lista)){
    printf("\nErro! Lista vazia.");
    return;
  }
  aux = Lista->Primeiro;
  while ((aux->Prox !=NULL) && (x!=aux->Prox->item.Chave))
    aux = aux->Prox;

  if(aux->Prox==NULL)
    printf("\nItem nao encontrado!");
  else
    printf("\nItem encontrado!");
  }
void printPause(){
  printf("\n\nTecle enter para continuar...\n");
  fpurge(stdin);
  getchar();
  system("clear");
}

void verificaOpcaoInvalida(int opcao){
  if(opcao <0 || opcao >5){
    printf("\nOpcao Invalida.");
    printPause();
  }
}

int imprimeMenu(){
  system("clear");

  int opcao;
  printf("┌────────────────────Menu─────────────────┐");
  printf("\n|    1 - Inserir uma nova chave.          |");
  printf("\n|    2 - Retirar uma chave da lista.      |");
  printf("\n|    3 - Buscar uma chave na lista.       |");
  printf("\n|    4 - Exibir a lista.                  |");
  printf("\n|    5 - Finalizar o programa.            |");
  printf("\n└─────────────────────────────────────────┘");
  printf("\nDigite sua opcao: ");
  scanf("%d", &opcao);
  verificaOpcaoInvalida(opcao);
  return opcao;
}

int main(void) {
  int opcao;
  TipoItem item;
  TipoLista lista;
  FLVazia(&lista);

  int chave;
  
  do{
    opcao = imprimeMenu();
    switch (opcao){
     case 1:
        printf("Digite a chave: ");

        scanf("%d", &chave);
        item.Chave = chave;

        Insere(item, &lista);
        printPause();
        break;

      case 2:
        printf("Digite a chave que deseja remover: ");
        scanf("%d", &chave);
        retira(chave, &lista, &item);
        
        printPause();
        break;

      case 3:
        printf("Digite a chave que deseja buscar: ");
        scanf("%d", &chave);
        buscarChave(chave, &lista);
        printPause();

        break;

      case 4:
        printf("Lista Atual\n");
        imprimeLista(lista);
        printPause();

        break;
    }
  }while (opcao != 5);
  
  printf("\nFim do programa");

  return 0;
}