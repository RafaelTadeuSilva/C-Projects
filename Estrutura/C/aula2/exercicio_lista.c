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
  Lista->Ultimo->Prox = NOVA_CELULA();
  Lista->Ultimo = Lista->Ultimo->Prox; 
  Lista->Ultimo->item = x;
  Lista->Ultimo->Prox=NULL;
  
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

void Retira(int p, TipoLista *Lista, TipoItem *Item){
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

int ImprimeMenu(){
  int opcao;
  printf("====================Menu====================");
  printf("\n|| Digite 1 para inserir novo Item        ||");
  printf("\n|| Digite 2 para retirar um item.         ||");
  printf("\n|| Digite 3 para exibir a lista.          ||");
  printf("\n|| Digite 4 para finalizar o programa.    ||");
  printf("\n============================================");
  printf("\nDigite sua opção: ");
  scanf("%d", &opcao);
  return opcao;
}

int main(void) {
  int opcao;
  TipoItem item;
  TipoLista lista;
  FLVazia(&lista);

  int chave;
  
  do{
    opcao = ImprimeMenu();
    switch (opcao){
      case 1:
        printf("Digite a chave: ");

        scanf("%d", &chave);
        item.Chave = chave;

        Insere(item, &lista);
        printf("\nNovo item incluido com sucesso\n");
        printf("\nTecle enter para continuar...\n");

        fpurge(stdin);
        getchar();

        system("clear");
        break;
      case 2:
        printf("Digite a chave que deseja remover: ");
        scanf("%d", &chave);
        Retira(chave, &lista, &item);
        
        printf("\nTecle enter para continuar...\n");

        
        fpurge(stdin);
        getchar();
        system("clear");
        break;
      case 3:
        printf("Lista Atual\n");
        imprimeLista(lista);
        printf("\nTecle enter para continuar...\n");

        fpurge(stdin);
        getchar();
        system("clear");
        break;
      
      
    }
  }while (opcao != 4);
  
  printf("\nFim do programa");

  return 0;
}