#include <stdio.h>

int main()
{
    float n1, n2, n3, media;
    printf("Calculo de media de notas\n");
    printf("Digite a primeira nota: \n");
    scanf("%f", &n1);

    printf("Digite a segunda nota: \n");
    scanf("%f", &n2);

    printf("Digite a terceira nota: \n");
    scanf("%f", &n3);

    media = (n1 + n2 + n3) / 3;
    printf("Notas digitadas: %.1f, %.1f, %.1f\n", n1, n2, n3);

    printf("Media do aluno: %.1f", media);

    return 0;
}