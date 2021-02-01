#include "exec2bib.h"

void imprimeMenu(int *opcao){
  printf("========================Menu============================");
  printf("\n|| Digite 1 para Inserir quantidade de horas.         ||");
  printf("\n|| Digite 2 para Valor de pagamento da vaga.          ||");
  printf("\n|| Digite 3 para Imprimir vagas ocupadas.             ||");
  printf("\n|| Digite 4 para Retirar um carro.                    ||");
  printf("\n|| Digite 5 para finalizar o programa.                ||");
  printf("\n========================================================");
  printf("\nDigite sua opção: ");
  scanf("%d", opcao);
}


void printPause(){
  printf("\n\nTecle enter para continuar...\n");
  fpurge(stdin);
  getchar();
  system("clear");
}

int main(){
    int opcao = 0;
    int vagas[20] = {0};
    int num = 0;
    int horas = 0;

    system("clear");
    do
    {
        imprimeMenu(&opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o numero da vaga: ");
            scanf("%d", &num);
            printf("Digite a quantidade de horas: ");
            scanf("%d", &horas);
            inserirHoras(vagas, horas, num);
            printPause();
            break;
        case 2:
            printf("Digite o numero da vaga: ");
            scanf("%d", &num);
            float valor = valorVaga(vagas, num);
            if(valor != -1){
                printf("Valor da Vaga %d: R$ %.2f" , num, valor);
            }
            printPause();
            break;
        case 3:
            vagasOcupadas(vagas);
            printPause();
            break;
        case 4:
            printf("Digite o numero da vaga do carro que vai sair: ");
            scanf("%d", &num);
            retirarCarro(vagas, num);
            printPause();
            break;
        default:
            break;
        }
    } while (opcao != 5);
    
    printf("\nFim da Execução.\n");
    
     return 0;
}