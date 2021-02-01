#include <stdio.h>
#include <math.h>

int calculaEquacao(float a, float b, float c, float *x1, float *x2)
{
    int result = 1;
    float delta = pow(b, 2) - 4 * a * c;
    if (delta < 0)
    {
        result = 0;
    }
    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
    return result;
}

int main()
{
    float a, b, c, x1, x2;

    do
    {
        printf("Digite o valor do coeficiente A: ");
        scanf("%f", &a);
    } while (a == 0);

    printf("Digite o valor do coeficiente B: ");
    scanf("%f", &b);

    printf("Digite o valor do coeficiente C: ");
    scanf("%f", &c);

    if (calculaEquacao(a, b, c, &x1, &x2) == 1)
    {
        if (x1 == x2)
        {
            printf("Raiz encontrada: %.2f\n", x1);
        }
        else
        {
            printf("Raizes encontradas: %.2f e %.2f\n", x1, x2);
        }
    }
    else
    {
        printf("Não existem raizes para a equacao informada\n");
    }

    return 0;
}
