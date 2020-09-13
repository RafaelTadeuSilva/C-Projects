#include <stdio.h>

int main(){
    float num[10] = {0};
    int menorElemento = 0;
    float media = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite um numero: ");
        scanf("%f", &num[i]);
        
        media += num[i];
        if (i == 0 || num[menorElemento] > num[i])
            menorElemento = i;
    }
    
    printf("\nO Menor Elemento esta na posicao %d e com valor de: %.2f\n", menorElemento, num[menorElemento]);
    printf("\nMedia: %.2f\n", media/10);
    
    return 0;
}