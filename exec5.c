#include <stdio.h>

int main()
{
    int v1[10], v2[10];
    char v3[10] ={'a'};
    printf("Digite 10 numeros: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%i", &v1[i]);
    }
    printf("Digite mais 10 numeros: ");

    for (int i = 0; i < 10; i++)
    {
        scanf("%i", &v2[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (v1[i] == v2[j]) {
                v3[i] = v1[i];
                break;
            }
        }
    }

    printf("Os numeros digitados foram: ");

    for (int i = 0; i < 10; i++)
    {
        if (v3[i] != 'a') {
            printf("%i\t", v3[i]);
        }
    }

    return 0;
}