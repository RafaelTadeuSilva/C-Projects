#include <stdio.h>
#include <string.h>

int main()
{
    int qtParc = 0;
    int dia, mes, ano = 0;
    int dataValida = 1;
    
    do
    {
        printf("Informe o numero de parcelas: ");
        scanf("%d", &qtParc);
        if (qtParc <= 0)
        {
            printf("Quantidade invalida.\n");
        }
    } while (qtParc <= 0);

    do
    {
        dataValida = 1;
        printf("Informe a data da primeira parcela\n");

        printf("Dia: ");
        scanf("%d", &dia);

        printf("Mes: ");
        scanf("%d", &mes);

        printf("Ano: ");
        scanf("%d", &ano);
        
        if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 0)
        {
            dataValida = 0;
        }
        else if (mes == 2 && ((ano%4 > 0 && dia > 28)||(ano%4 == 0 && dia > 29)))
        {
            dataValida = 0;
        }
        else if (dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11))
        {
            dataValida = 0;
        }

        if (dataValida == 0)
            printf("Data invalida!\n\n");
            
    } while (dataValida == 0);

    for (int i = 1; i <= qtParc; i++)
    {
        mes++;
        if (mes > 12)
        {
            mes = 1;
            ano++;
        }

        if (mes == 2 && (ano%4 > 0 && dia > 28))
        {
            printf("Parcela %d: %d/%d/%d\n", i, 28, mes, ano);
        }
        else if (mes == 2 && (ano%4 == 0 && dia > 29))
        {
            printf("Parcela %d: %d/%d/%d\n", i, 29, mes, ano);
        }
        else if (dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11))
        {
            printf("Parcela %d: %Fd/%d/%d\n", i, 30, mes, ano);
        }
        else
        {
            printf("Parcela %d: %Fd/%d/%d\n", i, dia, mes, ano);
        }
    }

    return 0;
}