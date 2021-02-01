void lerVetor(int *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }
}

void imprimeVetor(int *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        printf("\nValor Posicao %d: %d", i, vetor[i]);
    }
}

int contaPares(int *vetor, int tamanho){
    int pares = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if(vetor[i]%2 == 0)
            pares++;
    }
    
    return pares;
}

int somaVetor(int *vetor, int tamanho){
    int soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma+=vetor[i];
    }
    return soma;
}

