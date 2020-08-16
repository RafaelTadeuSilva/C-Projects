#include<stdio.h>

int main(){
    int a,b,c;
    float r,s,d;
    printf("Exercicio 1\n");

    printf("Informe o valor de A: ");
    scanf("%d",&a);

    printf("Informe o valor de B: ");
    scanf("%d",&b);

    printf("Informe o valor de C: ");
    scanf("%d",&c);

    r = a + b;
    s = b + c;

    d = (r*r + s*s)/2;

    printf("Resultado: D = %.1f",d);
    return 0;
}