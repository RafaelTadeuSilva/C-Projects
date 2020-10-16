#include <stdio.h>
#define n 10

float square(float num){
    return num * num;
}
float somatoria(float *vetor, float media){
    float soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += square(vetor[i]-media);
    }
    return soma;
}

int main()
{
    float vetor[] = {5, 3, 4, 8, 6, 2, 7, 9, 1, 5};
    float soma = 0;
    float m = 0;
    float desvioPadrao = 0;
    for (int i = 0; i < n; i++)
    {
        soma += vetor[i];
    }
    m = soma/n;

    desvioPadrao = sqrt((somatoria(vetor, m))/(n-1));
    printf("%.2f", desvioPadrao);
    return 0;
}