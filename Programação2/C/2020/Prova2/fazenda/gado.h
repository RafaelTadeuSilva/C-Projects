struct Gado
{
    int codigo;
    float leite;
    float alimento;
    char abate[1];
};

void lerVetor(struct Gado *cabecas, int tamanho, int *contCabecas)
{
    int codigo = 0;
    for (int i = *contCabecas; i < tamanho; i++)
    {
        printf("\nInforme o código da posicao %d (ou 0 para sair): ", i);
        scanf("%d", &codigo);

        if (codigo == 0)
            break;
        else
        {
            cabecas[i].codigo = codigo;
            (*contCabecas)++;
            printf("Quantidade litros de Leite produzido por semana: ");
            scanf("%f", &cabecas[i].leite);

            printf("Quantidade quilos de Alimento consumido por semana: ");
            scanf("%f", &cabecas[i].alimento);

            if (cabecas[i].leite < 40)
                *cabecas[i].abate = 'S';
            else if ((cabecas[i].leite >= 50 && cabecas[i].leite <= 70) && cabecas[i].alimento > 50)
                *cabecas[i].abate = 'S';
            else
                *cabecas[i].abate = 'N';
        }
    }
}

void imprimeProducaoLeite(struct Gado *cabecas, int tamanho)
{
    float producao = 0;
    for (int i = 0; i < tamanho; i++)
    {
        producao += cabecas[i].leite;
    }
    printf("\nSao produzidos %.2f litros de leite por semana.", producao);
}

void imprimeConsumoAlimento(struct Gado *cabecas, int tamanho)
{
    float consumo = 0;
    for (int i = 0; i < tamanho; i++)
    {
        consumo += cabecas[i].alimento;
    }
    printf("\nSao consumidos %.2f quilos de alimento por semana.", consumo);
}

void imprimeProducaoLeiteAbate(struct Gado *cabecas, int tamanho)
{
    float producao = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (*cabecas[i].abate == 'N')
            producao += cabecas[i].leite;
    }
    printf("\nSerao produzidos %.2f litros de leite por semana após o abate.", producao);
}

void imprimeConsumoAlimentoAbate(struct Gado *cabecas, int tamanho)
{
    float consumo = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (*cabecas[i].abate == 'N')
            consumo += cabecas[i].alimento;
    }
    printf("\nSerao consumidos %.2f quilos de alimento por semana após o abate.", consumo);
}

void imprimeCabecasParaAbate(struct Gado *cabecas, int tamanho)
{
    int total = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (*cabecas[i].abate == 'S')
            total++;
    }
    printf("\n\nSerao abatidas %d cabecas.\n", total);
}