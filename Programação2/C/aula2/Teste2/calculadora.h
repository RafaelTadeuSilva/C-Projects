#include <math.h>
int soma(int x, int y)
{
    return x+y;
}
int subtracao(int x, int y)
{
    return x-y;
}
int multiplicacao(int x, int y)
{
    return x*y;
}
int divisao(int x, int y)
{
    if(y!=0)
        return x/y;
    else
        return 0;
}
int potencia(int base, int expoente){
    return pow(base,expoente);
}
float raizQuadrada(int numero){
    if(numero < 0)
        return -1;
    else
        return sqrt(numero);
}
int mudaSinal(int numero){
    return -numero;
}