int soma(int a, int *b){
    *b = 2;
    return a + *b;
}

void funcaoTeste(int *v){
    for (int i = 0; i < 10; i++)
        printf("%d\n", v[i]);
}