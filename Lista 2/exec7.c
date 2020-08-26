#include <stdio.h>

int main()
{
    char nome[101] = {' '};
    char iniciais[101] = {' '};

    printf("Digite seu nome completo:\n");

    gets(nome);

    iniciais[0] = nome[0];
    for (int i = 1; i < strlen(nome); i++)
    {
        if (nome[i] == ' ' && nome[i + 1] != ' ')
            iniciais[strlen(iniciais)] = nome[i + 1];
    }

    printf("%s", iniciais);

    return 0;
}