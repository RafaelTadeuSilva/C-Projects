#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p;
    p= (int *)malloc(sizeof(int));
    if(!p){
      printf("Erro Memória insuficiente");
      exit;
    }
    printf("\nDigite um valor inteiro: ");
    scanf("%d", p);
    printf("Valor digitado é: %d", *p);
    getchar();

    return 0;
}