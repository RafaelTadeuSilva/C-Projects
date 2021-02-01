void imprimePause(){
    printf("\nTecle ENTER para continuar...");
    fflush(stdin);
    getchar();
}

FILE *abrirArquivo(char *nomeArquivo){
    FILE *fp = fopen(nomeArquivo, "a+");
    if(fp==NULL)
        printf("Problemas ao abrir/criar o arquivo!");
    return fp;
}