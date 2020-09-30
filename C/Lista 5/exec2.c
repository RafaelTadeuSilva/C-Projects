#include <stdio.h>

float calcDelta(float a, float b, float c)
{
    return b*b - 4 * a * c;
}
int main()
{
    float a, b, c;

    printf("Digite o valor de a: ");
    scanf("%f",&a);
    
    printf("Digite o valor de b: ");
    scanf("%f",&b);

    printf("Digite o valor de c: ");
    scanf("%f",&c);

    printf("Delta: %0.2f", calcDelta(a,b,c));
    return 0;
}