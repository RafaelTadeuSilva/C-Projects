#include<stdio.h>

int main(){
    char nome[10][30], pesquisa[30];
    int encontrou = 0;
    printf("Informe o nome de 10 pessoas:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%s",nome[i]);
    }
    
    printf("Digite o nome a ser pesquisado:\n");
    scanf("%s",pesquisa);
    
    for (int i = 0; i < 10; i++)
    {
        if(strcmp(nome[i],pesquisa)==0){
            encontrou = 1;
            break;
        }
    }
    if(encontrou == 1)
        printf("ACHEI");
    else
        printf("NAO ACHEI");

    return 0;
}