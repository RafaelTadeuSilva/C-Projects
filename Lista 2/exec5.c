#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[31];
    int vogais = 0;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    
    for (int i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u'
        || palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U')
            vogais++;
    }
    
    if(vogais == 0)
        printf("A palavra %s nao possui vogais.", palavra);
    else
        printf("A palavra %s possui %d vogais.", palavra, vogais);

    return 0;
}