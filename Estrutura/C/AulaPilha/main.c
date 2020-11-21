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

int Tamanho(TipoPilha Pilha){
    return (Pilha.Tamanho);
}

void Imprime(TipoPilha *Pilha){
    TipoItem item;
    while (!Vazia(*Pilha))
    {
        Desempilha(Pilha, &item);
        printf("\nChave: %d", item.Chave);
    }
    
}

void Menu(){
    printf("\n-----Menu------");
    printf("\n 1-Empilha");
    printf("\n 2-Desempilha");
    printf("\n 3-Exibir Pilha");
    printf("\n 0-Sair");
    printf("\n--------------");

    printf("\n Digite a opcao");


}

int main(){
    TipoPilha p;
    TipoItem item;
    int opcao = -1;
    char continua='n';
    FPVazia(&p);

    system("cls");

    while (opcao !=0)
    {
        printf("\nDigite a chave q deseja empilhar")
    }
    
    return 0;
}