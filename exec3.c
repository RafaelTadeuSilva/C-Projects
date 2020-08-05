#include<stdio.h>

int main(){
    const float m = 700;
    float a, f;
    printf("Calculo de Forca\n");
    printf("Digite a aceleracao do carro\n");
    scanf("%f", &a);
    f = m*a;
    printf("Forca exercida pelo motor: %0.1fN", f);

    return 0;
}