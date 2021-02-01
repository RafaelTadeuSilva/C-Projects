#include <stdio.h>
#include "vetores.h"

int main()
{   
    int vetor[10];
    leitura(vetor,10);
    printf("Maior = %d\n", maiorValor(vetor, 10));
  
    printf("Menor = %d\n", menorValor(vetor, 10));
    return 0;
}
