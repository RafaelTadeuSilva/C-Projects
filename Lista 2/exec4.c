#include <stdio.h>
#include <string.h>

int main()
{
    char str1[30], str2[30];

    printf("Digite a primeira palavra: ");
    scanf("%s", str1);

    printf("Digite a segunda palavra: ");
    scanf("%s", str2);

    if (strcmp(str1, str2) == 0)
    {
        printf("Strings iguais");
    }
    else
    {
        printf(strcat(str1, str2));
    }
    return 0;
}