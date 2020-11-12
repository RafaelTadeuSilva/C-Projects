#include <stdio.h>
#include "calculadora.h"

int main()
{
    int opcao = 0;
    do
    {
        printf("Calculadora: \n1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n5 - Potencia\n6 - Raiz Quadrada\n7 - Muda Sinal\n0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:{
                int x, y;
                printf("Digite dois valoes inteiros:");
                scanf("%d %d", &x, &y);
                printf("Soma = %d\n", soma(x,y));
                break;
                }
            
            case 2:{
                int x, y;
                printf("Digite dois valoes inteiros:");
                scanf("%d %d", &x, &y);
                printf("Sutracao = %d\n", subtracao(x,y));
                break;
                }
            
            case 3:{
                int x, y;
                printf("Digite dois valoes inteiros:");
                scanf("%d %d", &x, &y);
                printf("Multiplicacao = %d\n", multiplicacao(x,y));
                break;
                }
            case 4:{
                int x, y;
                printf("Digite dois valoes inteiros:");
                scanf("%d %d", &x, &y);
                if(y == 0)
                    printf("Impossivel divisão por 0");
                else
                    printf("Divisao = %d\n", divisao(x,y));
                break;
                }
            case 5:{
                int x, y;
                printf("Digite um valor para a base:");
                scanf("%d", &x);
                printf("Digite um valor para o expoente:");
                scanf("%d", &y);
                printf("Potência = %d\n", potencia(x,y));
                break;
                }
            case 6:{
                int x;
                printf("Digite um valor: ");
                scanf("%d", &x);
                float resultado = raizQuadrada(x);
                if(resultado != -1)
                    printf("Potência = %.2f\n", resultado);
                else
                    printf("Impossivel calcular raiz quadrada de numeros negativos\n");
                break;
                }
            case 7:{
                int x;
                printf("Digite um valor: ");
                scanf("%d", &x);
                printf("Sinal Trocado = %d\n", mudaSinal(x));            
                break;
                }
            default:
                break;
        }
    } while (opcao!=0);
    
    printf("Encerrando Execucao\n");
    return 0;
}
