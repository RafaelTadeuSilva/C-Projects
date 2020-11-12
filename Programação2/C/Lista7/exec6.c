#include <stdio.h>

void troca(float *a, float *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
int main()
{
    float a, b;
    printf("Digite o valor da variavel a: ");
    scanf("%f", &a);

    printf("Digite o valor da variavel b: ");
    scanf("%f", &b);

    troca(&a, &b);

    printf("Valores Trocados: a = %.2f e b = %.2f\n", a, b);

    return 0;
}
