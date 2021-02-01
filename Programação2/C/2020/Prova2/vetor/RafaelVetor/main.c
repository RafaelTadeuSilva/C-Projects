#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(){
    int tamanho;
    printf("\nInforme o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int *vetor = malloc(tamanho*sizeof(int));

    lerVetor(vetor, tamanho);
    imprimeVetor(vetor, tamanho);
    printf("\n\nQuantidade de numeros pares: %d", contaPares(vetor, tamanho));
    printf("\n\nSoma dos numeros: %d\n\n", somaVetor(vetor, tamanho));

    return 0;
}