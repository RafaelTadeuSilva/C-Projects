#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, delta, x1, x2;
    printf("Exercicio 6\n");

    printf("Equacao do segundo grau\n");

    printf("informe o valor do coeficiente a: ");
    scanf("%f", &a);

    printf("informe o valor do coeficiente b: ");
    scanf("%f", &b);

    printf("informe o valor do coeficiente c: ");
    scanf("%f", &c);

    delta = pow(b,2) - 4 * a * c;
    if (delta < 0)
    {
        printf("Nao existem raizes para esta equacao.");
    }
    else if (delta == 0)
    {
        x1 = (-b) / (2 * a);
        printf("Raiz da equacao: %.2f",x1);
    }
    else
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Raiz 1 da equacao: %.2f\n",x1);
        printf("Raiz 2 da equacao: %.2f",x2);
    }

    return 0;
}