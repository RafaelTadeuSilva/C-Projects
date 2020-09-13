#include <stdio.h>
#include <string.h>

int main()
{
    char nome[21] = {' '};
    char consoantes[21] = {' '};
    char vogais[] = "aeiou ";
    int ehVogal;

    gets(nome);

    int qtdeCons = 0;

    printf("Digite uma palavra: ");

    for (int i = 0; i < strlen(nome); i++)
    {
        ehVogal = 0;

        for (int j = 0; j < strlen(vogais); j++)
        {
            if (nome[i] == vogais[j])
            {
                ehVogal = 1;
                break;
            }
        }

        if (ehVogal == 0)
        {
            consoantes[qtdeCons] = nome[i];
            qtdeCons++;
        }
    }
    if (qtdeCons == 0)
        printf("Não foi digitada nenhuma consoante.");
    else if (qtdeCons == 1)
        printf("Foi lida %d consoante, sendo ela: %s", qtdeCons, consoantes);
    else
        printf("Foram lidas %d consoantes, sendo elas: %s", qtdeCons, consoantes);

    return 0;
}