#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NOVA_CELULA() ((TipoApontador) malloc(sizeof(TipoCelula)))

typedef struct TipoItem{
    char nome[20];
}TipoItem;

typedef struct xxCelula *TipoApontador;

typedef struct xxCelula{
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila
{
    TipoApontador Frente;
    TipoApontador Tras;
}TipoFila;

void FFVazia (TipoFila *Fila){
    Fila->Frente=NOVA_CELULA();
    Fila->Tras= Fila->Frente;
    Fila->Frente->Prox = NULL;
}

int Vazia(TipoFila Fila){
    return (Fila.Frente == Fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *Fila){
    Fila->Tras->Prox = NOVA_CELULA();
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item=x;
    Fila->Tras->Prox = NULL;
    printf("\nChave enfileirada com sucesso!");
}

void Imprime(TipoFila Fila){
    TipoApontador Aux;
    Aux = Fila.Frente->Prox;

    while (Aux!=NULL)
    {
        printf("\nNome: %s\n", Aux->Item.nome);
        Aux=Aux->Prox;
    }
}

void BuscaPessoa(char pessoa[], TipoFila fila)
{
    TipoApontador Aux;
    Aux = fila.Frente->Prox;
    int encontrou = 0;

    while (Aux!=NULL)
    {
        if(strcmp(pessoa, Aux->Item.nome)==0)
        {
            encontrou = 1;
            break;
        }
        Aux=Aux->Prox;
    }
    if(encontrou == 1)
        printf("Pessoa Encontrada\n");
    else
        printf("Pessoa Nao Encontrada\n");
}

int main(){
    TipoFila f;
    TipoItem item;
    int opcao;
    char pessoa[20];
    FFVazia(&f);

    // printf("\nDigite a chave q deseja enfileirar: ");
    // scanf("%s", item.nome);
    // Enfileira(item, &f);
    // printf("\nDigite a chave q deseja enfileirar: ");
    // scanf("%s", item.nome);
    // Enfileira(item, &f);
    // printf("\nDigite a chave q deseja enfileirar: ");
    // scanf("%s", item.nome);
    // Enfileira(item, &f);
    // printf("\nDigite a chave q deseja enfileirar: ");
    // scanf("%s", item.nome);
    // Enfileira(item, &f);
    // Imprime(f);

    printf("\nDigite o nome q deseja procurar: ");
    scanf("%s", pessoa);
    
    BuscaPessoa(pessoa, f);
}