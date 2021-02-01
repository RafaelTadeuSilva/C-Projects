#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerNomes(char **nomes, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o nome: ");
        scanf("%s", nomes[i]);
    }
}

void imprimirNomes(char **nomes, int tamanho){
    printf("\nLista de Nomes digitados");
    for (int i = 0; i < tamanho; i++)
    {
        printf("\n%s", nomes[i]);
    }
}

void imprimirNomesIniciadoVogais(char **nomes, int tamanho){
    char vogais[10]={'a','e', 'i', 'o', 'u','A','E','I','O','U'};

    printf("\nLista de Nomes digitados iniciados por vogais");
    
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(nomes[i][0] == vogais[j]){
                printf("\n%s", nomes[i]);
            }
        }
    }
}

int pesquisaNome(char *nomePesq, char **nomes, int tamanho){
    int retorno = 0;
    for (int i = 0; i < tamanho; i++)
    {        
        if(strcasecmp(nomePesq,nomes[i])==0){
            retorno = 1;
            break;
        }  
    }
    return retorno;
}