#include <stdio.h>

float calcDelta(float a, float b, float c)
{
    return b * b - 4 * a * c;
}
int main()
{
    float a, b, c;

    do
    {
        printf("Digite o valor de a: ");
        scanf("%f", &a);

        if (a == 0)
        {
            printf("a nao pode ser 0 em uma equacao do 2 grau!\n");
        }
    } while (a == 0);

    printf("Digite o valor de b: ");
    scanf("%f", &b);

    printf("Digite o valor de c: ");
    scanf("%f", &c);

    printf("Delta: %0.2f", calcDelta(a, b, c));
    return 0;
}