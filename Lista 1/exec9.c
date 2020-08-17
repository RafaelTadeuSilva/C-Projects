#include <stdio.h>

int main()
{
    int prazo, vista, codigo;
    float valor, val_prazo, val_vista;
    prazo = 0;
    vista = 0;

    printf("Exercicio 8\n");

    for (int i = 0; i < 20; i++)
    {
        printf("Informe o codigo da transacao %i: 0 - a Prazo ou 1 - a Vista: ", i+1);
        scanf("%d", &codigo);

        if (codigo < 0 || codigo > 1)
        {
            printf("Codigo invalido!\n");
            i--;
            continue;
        }

        printf("Informe o valor da compra: ");
        scanf("%f", &valor);
        if (valor < 0)
        {
            printf("Valor invalido!\n");
            i--;
            continue;
        }

        if (codigo == 0)
        {
            val_prazo += valor;
            prazo++;
        }
        else
        {
            val_vista += valor;
            vista++;
        }
    }
    printf("Foram feitas %d compras a Vista no valor de R$ %.2f\n", vista, val_vista);
    printf("Foram feitas %d compras a Prazo no valor de R$ %.2f\n", prazo, val_prazo);

    printf("Total de compras: %d no valor de R$ %.2f", vista + prazo, val_vista + val_prazo);

    return 0;
}