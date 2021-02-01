#include <stdio.h>

float maiorNum(float num1, float num2, float num3)
{
    float result = num1 > num2 ? num1 : num2;
    return result > num3 ? result : num3;
}
int main()
{
    float num1, num2, num3 = 0;
    printf("Digite 3 numeros: ");
    scanf("%f %f %f", &num1, &num2, &num3);
    printf("O maior numero digitado foi: %0.2f", maiorNum(num1, num2, num3));
    return 0;
}