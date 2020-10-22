#include <stdio.h>

int main()
{
    float celsius, fahrenheit;

    printf("Exercicio 8\n");
    
    printf("Informe a temperatura em Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = (9 * celsius + 160) / 5;

    printf("%.2f graus Celsius equivalem a %.2f graus Fahrenheit", celsius, fahrenheit);

    return 0;
}