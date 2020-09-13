#include <stdio.h>

int main(){
    char palavras[3][21] = {' '};

    for (int i = 0; i < 3; i++)
    {
        printf("\nDigite uma palavra: ");
        scanf("%s", palavras[i]);    
    }
    printf("\nAs palavras digitadas em ordem inversa: ");
    for (int i = 2; i >= 0; i--)
    {
        printf("\n%s", palavras[i]);
    }
    
    return 0;
}