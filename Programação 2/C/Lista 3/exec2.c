#include <stdio.h>
#include <string.h>

int main(){
    char nomes[10][31];
    char busca[30];
    int encontrou = 0;
    
    for (int i = 0; i < 10; i++)
    {
        printf("Digite um nome de pessoa: ");
        gets(nomes[i]);
    }
    
    printf("\nDigite um nome para procurar: ");
    gets(busca);
    
    for (int i = 0; i < 10; i++)
    {
        if(stricmp(busca, nomes[i])==0){
            printf("ACHEI");
            return 0;
        }
    }
    printf("NAO ACHEI");

    return 0;
}