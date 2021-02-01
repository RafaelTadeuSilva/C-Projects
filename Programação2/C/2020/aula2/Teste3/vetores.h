void leitura(int *v, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite um valor: ");
        scanf("%d", &v[i]);
    }
}

void imprime(int *v, int tamanho){
    for (int i = 0; i < 10; i++)
    {
        printf("%d - ", v[i]);
    }
}

int maiorValor(int *v, int tamanho){
    int maior = v[0];
    for (int i = 1; i < tamanho; i++)
    {
        if(maior<v[i])
            maior = v[i];
    }
    return maior;
}
int menorValor(int *v, int tamanho){
    int menor = v[0];
    for (int i = 1; i < tamanho; i++)
    {
        if(menor>v[i])
            menor = v[i];
    }
    return menor;
}
int somatorio(int *v, int tamanho){
    int soma;
    for (int i = 0; i < tamanho; i++)
    {
        soma += v[i];;
            
    }
    return soma;
}