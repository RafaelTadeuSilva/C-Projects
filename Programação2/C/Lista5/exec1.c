#include <stdio.h>

void parImpar(int num){
    if(num%2 == 0)
        printf("%d eh Par", num);
    else
        printf("%d eh Impar", num);
} 

int main(){ 
    int num;
    printf("Digite um numero: ");
    scanf("%d",&num);

    parImpar(num);

    return 0;
}