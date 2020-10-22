#include <stdio.h>

int main()
{
    float n1, n2, n3, media;
    printf("Exercicio 2\n");

    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &n1);

    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &n2);

    printf("Digite a nota 3 do aluno: ");
    scanf("%f", &n3);

    media = n1 * 3 + n2 * 4 + n3 * 3;
    printf("Media final do aluno: %.2f", media / 10);

    return 0;
}