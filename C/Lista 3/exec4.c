#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    char nome[21] = {' '};
    char consoantes[21] = {' '};
    int qtdeCons[20] = {0};
    char vogais[] = "aeiou ";
    bool ehVogal;
    int contCons = 0;

    printf("Digite uma palavra: ");

    gets(nome);

    for (int i = 0; i < strlen(nome); i++)
    {
        ehVogal = false;

        for (int j = 0; j < strlen(vogais); j++)
        {
            if (tolower(nome[i]) == tolower(vogais[j]))
            {
                ehVogal = true;
                break;
            }
        }

        if (ehVogal == false)
        {
            bool encontrou = false;
            for (int l = 0; l < strlen(consoantes); l++)
            {
                if(consoantes[l]==tolower(nome[i])){
                    qtdeCons[l]++;
                    encontrou = true;
                    break;
                }
            }
            if(encontrou == false){
                qtdeCons[strlen(consoantes)]++;
                consoantes[strlen(consoantes)] = tolower(nome[i]);
            }
            contCons++;
        }
    }
    if (contCons == 0)
        printf("Nao foi digitada nenhuma consoante.");
    else if (contCons == 1)
        printf("Foi lida %d consoante, sendo ela: %s", contCons, consoantes);
    else
    {
        printf("Foram lidas %d consoantes, sendo elas:\n", contCons);

        for (int i = 1; i < strlen(consoantes); i++)
        {
            printf("%c: %d\n", consoantes[i], qtdeCons[i]);
        }
    }   

    return 0;
}