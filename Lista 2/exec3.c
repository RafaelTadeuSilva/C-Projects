#include <stdio.h>

int main()
{
    int num, u, d, c, m, soma, resto, dig = 0;
    scanf("%d", &num);

    m = num / 1000;
    c = num / 100 - m * 10;
    d = num / 10 - c * 10 - m * 100;
    u = num - d * 10 - c * 100 - m * 1000;
    soma = u * 2 + d * 3 + c * 4 + m * 5;
    resto = soma % 11;
    dig = 11 - resto;

    printf("soma = %d*2 + %d*3 + %d*4 + %d*5 = %d\n", u, d, c, m, soma);
    printf("resto = %d %% 11 = %d\n", soma, resto);
    printf("digito = 11 - %d = %d\n", resto, dig);
    if(dig > 9)
    {
        dig = 0;
        printf("digito calculado > 9, entao digito final sera %d", dig);
    }


    return 0;
}