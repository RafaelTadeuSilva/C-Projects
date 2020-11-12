#include <stdio.h>

char retornaConceito(float mediaFinal)
{
    char conceito = ' ';
    if (mediaFinal < 5)
        conceito = 'D';
    else if (mediaFinal < 7)
        conceito = 'C';
    else if (mediaFinal < 9)
        conceito = 'B';
    else if (mediaFinal <= 10)
        conceito = 'A';
    
    return conceito;
}
int main()
{
    float mediaFinal;
    printf("Informe a media final do aluno: ");
    scanf("%f", &mediaFinal);
    printf("Conceito: %c", retornaConceito(mediaFinal));
}