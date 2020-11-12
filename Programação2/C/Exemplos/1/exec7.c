#include<stdio.h>

int main(){
    int pares = 0;
    float media = 0;

    int matriz[3][4]={{4,5,9,5},
                      {6,8,9,6},
                      {7,1,2,9}};
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(matriz[i][j] % 2 == 0)
            {
                pares++;
            }
            media += matriz[i][j];
        }        
    }
    printf("Numeros pares: %d\n",pares);
    printf("Numeros impares: %d\n",12-pares);
    printf("Media dos numeros: %f",(media/12));

    return 0;
}