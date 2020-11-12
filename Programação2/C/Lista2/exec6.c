#include<stdio.h>

int main(){
    int num, maior, menor = 0;
    float media = 0;
    
    printf("Digite 10 valores inteiros: ");

    for (int i = 0; i < 10; i++)
    {   
        scanf("%d", &num);

        if(i==0 || num > maior)
            maior = num;

        if(i==0 || num < menor)
            menor = num;
        
        media += num;
    }
    
    printf("O maior valor digitado foi: %d\n", maior);
    printf("O menor valor digitado foi: %d\n", menor);
    printf("Media dos valores digitados: %.1f", media/10);

    return 0;
}