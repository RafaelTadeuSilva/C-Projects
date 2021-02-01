#include <stdio.h>
#include <stdlib.h>

#define NOVA_CELULA() ((TipoApontador) malloc(sizeof(TipoCelula)))

typedef struct
{
    int Chave;
}TipoItem;

typedef struct xxCelula *TipoApontador;

typedef struct xxCelula
{
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct
{
    TipoApontador Fundo;
    TipoApontador Topo;
    int Tamanho;
} TipoPilha;

void FPVazia(TipoPilha *Pilha){
    Pilha->Topo = NOVA_CELULA();
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}
void Empilha(TipoItem x, TipoPilha *Pilha){
    TipoApontador Aux;
    Aux = NOVA_CELULA();
    Pilha->Topo->Item =x ;
    Aux->Prox = Pilha->Topo;
    Pilha ->Topo = Aux;
    Pilha->Tamanho++;
    printf("\nChave empilhada com sucesso!");
}

int Vazia(TipoPilha Pilha){
    return (Pilha.Topo == Pilha.Fundo);
}



void Desempilha(TipoPilha *Pilha, TipoItem *Item){
    TipoApontador q;
    if(Pilha->Topo == Pilha->Fundo)
        printf("\nErro: Pilha Vazia!");
    else
    {
        q=Pilha->Topo;
        Pilha->Topo = q->Prox;
        *Item = q->Prox->Item;
        free(q);
        Pilha->Tamanho--;
    }   
}

void Imprime(TipoPilha *Pilha){
    TipoItem item;
    while (!Vazia(*Pilha))
    {
        Desempilha(Pilha, &item);
        printf("\nChave: %d", item.Chave);
    }
}


int main (){
    TipoPilha Pilha;
    TipoItem item;

    FPVazia(&Pilha);
    
    printf("\nDigite a chave q deseja enfileirar: ");
    scanf("%d", &item.Chave);
    
    Empilha(item, &Pilha);

    printf("\nDigite a chave q deseja enfileirar: ");
    scanf("%d", &item.Chave);
    
    Empilha(item, &Pilha);

    printf("\nDigite a chave q deseja enfileirar: ");
    scanf("%d", &item.Chave);
    
    Empilha(item, &Pilha);
    
    Desempilha(&Pilha, &item);

    printf("\nChave Desempilhada: %d\n", item.Chave);

    Imprime(&Pilha);
}