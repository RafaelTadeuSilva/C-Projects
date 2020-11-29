#include<stdio.h>

#include "Carro.h"
#include "Cliente.h"

struct Aluguel
{
    struct Carro carro;
    struct Cliente cliente;
    char data[10];
    int diasAlugados;
    int kmRodados;
    float total;
};
