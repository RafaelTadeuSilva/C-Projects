#include<stdio.h>

int main(){
    float saldo;
    printf("Exercicio 6\n");
    printf("Informe o saldo atual: ");
    scanf("%f", &saldo);
    printf("Saldo com reajuste: %.2f", saldo*1.15);
    return 0;
}