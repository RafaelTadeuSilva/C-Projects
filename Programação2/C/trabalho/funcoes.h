void imprimePause(){
    printf("\nTecle ENTER para continuar...");
    fpurge(stdin);
    getchar();
}

void abrirArquivo(FILE *fp, char *nomeArquivo){
    fp = fopen(nomeArquivo, "w");
    if(fp==NULL)
        printf("Problemas ao abrir/criar o arquivo!");
}
