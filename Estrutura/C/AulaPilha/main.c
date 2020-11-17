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
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct
{
    TipoApontador Fundo;
    TipoApontador Topo;
    int Tamanho;
}TipoPilha;

void FPVazia(TipoPilha *Pilha){
    Pilha->Topo = NOVA_CELULA();
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->Tamanho = 0;
}

int Vazia(TipoPilha Pilha){
    return (Pilha.Topo == Pilha.Fundo);
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

void Desempilha(TipoPilha *Pilha, TipoItem *item){
    TipoApontador q;
    if(Vazia(*Pilha))
        printf("\nErro: Pilha Vazia!");
    else
    {
        q=Pilha->Topo;
        Pilha->Topo = q->Prox;
        *item = q->Prox->Item;
        free(q);
        Pilha->Tamanho--;
    }   
}