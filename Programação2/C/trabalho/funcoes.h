void imprimePause(){
    printf("\nTecle ENTER para continuar...");
    fpurge(stdin);
    getchar();
}

FILE *abrirArquivo(char *nomeArquivo){
    FILE *fp = fopen(nomeArquivo, "a+");
    if(fp==NULL)
        printf("Problemas ao abrir/criar o arquivo!");
    return fp;
    //printf("%d", fprintf(fp, "%s", "teste"));
    // fclose(fp);
}

FILE *carregaArquivo(char *nomeArquivo){
    FILE *fp = fopen(nomeArquivo, "r");
    if(fp==NULL)
        printf("Problemas ao abrir/criar o arquivo!");
    return fp;
}