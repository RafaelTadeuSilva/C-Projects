#include <stdio.h>

int main()
{
    int num;
    printf("Exercicio 4\n");

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    printf("Sucessor do numero %d: %d\n", num, num + 1);
    printf("Antecessor do numero %d: %d\n", num, num - 1);

    return 0;
}