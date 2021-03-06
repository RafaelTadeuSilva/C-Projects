#include <stdlib.h>
#include <stdio.h>

#define NOVA_CELULA() ((TipoApontador) malloc(sizeof(TipoCelula)))

typedef struct TipoItem
{
    int Chave;
} TipoItem;

typedef struct xxCelula *TipoApontador;

typedef struct xxCelula
{
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila{
    TipoApontador Frente;
    TipoApontador Tras;
} TipoFila;

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
void Desenfileira(TipoFila *Fila, TipoItem *Item)
{
    TipoApontador q;
    if(Vazia(*Fila))
        printf("Erro fila esta vazia\n");
    else
    {
        q=Fila->Frente;
        Fila->Frente=Fila->Frente->Prox;
        *Item = Fila->Frente->Item;
        free(q);
    }
}

void Imprime(TipoFila Fila){
    TipoApontador Aux;
    Aux = Fila.Frente->Prox;

    while (Aux!=NULL)
    {
        printf("Chave: %d\n", Aux->Item.Chave);
        Aux=Aux->Prox;
    }
}

void Menu()
{
    printf("\n|----------Menu-----------");
    printf("\n|    1 - Enfileirar      |");
    printf("\n|    2 - Desenfileirar   |");
    printf("\n|    3 - Exibir Fila     |");
    printf("\n|    0 - Sair            |");
    printf("\n|------------------------|");

    printf("\n Digite a opcao desejada: ");
}

void printPause(){
    printf("\nTecle ENTER para continuar...");
    fpurge(stdin);
    getchar();
    system("clear");
}

int main()
{
    TipoFila f;
    TipoItem item;
    int opcao;
    FFVazia(&f);
    system("clear");
    do
    {
        Menu();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nDigite a chave q deseja enfileirar: ");
            scanf("%d", &item.Chave);
            Enfileira(item, &f);
            printPause();
            break;
        case 2:
            Desenfileira(&f, &item);
            printf("\nChave %d desenfileirada: ", item.Chave);
            printPause();
            break;

        case 3:
            Imprime(f);
            printPause();
            break;

        default:
            break;
        }
        // printf("\nDigite a chave q deseja enfileirar:");
        // scanf("%d");
        
    } while (opcao != 0);
    
    return 0;
}