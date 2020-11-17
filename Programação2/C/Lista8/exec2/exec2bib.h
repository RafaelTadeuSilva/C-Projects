#include <stdio.h>
#include <stdlib.h>

void inserirHoras(int *vagas, int horas, int num){
    if(num < 0 || num > 19){
        printf("Vaga invalida.");
    }
    else
    {
        vagas[num] = horas;
        printf("%d hora(s) registrado para a vaga %d.",horas, num);
    }
}

float valorVaga(int *vagas, int num){
    if(num < 0 || num > 19){
        printf("Vaga invalida.");
        return -1;
    }
    return vagas[num] * 5.0;
}

void vagasOcupadas(int *vagas){
    printf("Vagas Ocupadas: ");
    for (int i = 0; i < 20; i++)
    {
        if(vagas[i]!=0)
            printf("\n%d", i);
    }
}

void retirarCarro(int *vagas, int num){
    if(num < 0 || num > 19){
        printf("Vaga invalida.");
    }
    else if(vagas[num]==0)
    {
        printf("A vaga %d nao esta ocupada.", num);
    }
    else
    {
        vagas[num] = 0;
        printf("Carro retirado da vaga %d.", num);
    }
}
