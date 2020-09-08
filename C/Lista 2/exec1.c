#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[31];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    for (int i = strlen(palavra) - 1; i >= 0; i--)
    {
        printf("%c", palavra[i]);
    }

    return 0;
}