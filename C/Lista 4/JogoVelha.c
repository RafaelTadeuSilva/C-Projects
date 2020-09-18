#include <stdio.h>

int main()
{
    int opcao;
    int totalJogos = 0;
    int jogadaX = 0;
    int jogadaY = 0;
    int empate = 0;
    int vitX = 0;
    int vitO = 0;

    do
    {
        printf("Menu\n1 - Novo Jogo\n2 - Imprimir Ranking\n3 - Imprimir estatísticas\n0 - Para Finalizar\n\n");
        printf("Digite a opcao desejada ->");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            /* novo jogo */
            system("cls");
            char mat[3][4] = {"   ", "   ", "   "};
            int vitoria = 0;
            int erro;
            char jogadorAtual = 'X';
            int jogadas = 0;
            do
            {
                printf("Jogo Atual:\n\n");

                printf("  %c  |  %c  |  %c\n", mat[0][0], mat[0][1], mat[0][2]);
                printf("-----------------\n");
                printf("  %c  |  %c  |  %c\n", mat[1][0], mat[1][1], mat[1][2]);
                printf("-----------------\n");
                printf("  %c  |  %c  |  %c\n", mat[2][0], mat[2][1], mat[2][2]);
                if (jogadas == 9) //Empate
                {
                    printf("\nJogo terminado em Empate.\n\n");
                    empate++;
                    break;
                }
                do
                {
                    erro = 0;
                    printf("\nJogada de %c, digite a linha (0-2):", jogadorAtual);
                    scanf("%d", &jogadaX);
                    printf("digite a coluna (0-2):");
                    scanf("%d", &jogadaY);
                    if (mat[jogadaX][jogadaY] == ' ') //Verifica se já esta preenchida
                        mat[jogadaX][jogadaY] = jogadorAtual;
                    else
                    {
                        erro = 1;
                        printf("\nEspaco ja marcado\nEscolha outro!");
                    }
                } while (erro == 1);
                jogadas++;
                /* verifica vitória */
                vitoria = 1;
                for (int i = 0; i < 2; i++) //Verifica linha ultima jogada
                {
                    printf(vitoria);
                    printf("%mat[jogadaX, i]);
                    if(mat[jogadaX, i] != jogadorAtual)
                    {
                        vitoria = 0;
                        break;
                    }
                }
                if(vitoria != 1){
                    vitoria = 1;
                    for (int j = 0; j < 2; j++) //Verifica coluna ultima jogada
                    {
                        if(mat[j, jogadaY] != jogadorAtual)
                        {
                            vitoria = 0;
                            break;
                        }
                    }
                }
                
                if (vitoria == 1)
                {
                    printf("Vitoria do Jogador %c.", jogadorAtual);
                }
                else
                {
                    jogadorAtual = jogadorAtual == 'X' ? 'O' : 'X'; //Muda jogadorAtual
                    system("cls");
                }
            } while (vitoria == 0);

            break;
        case 2:
            /* imprimir ranking */
            break;
        case 3:
            /* estatisticas numero jogos - vencedor x vencedor o, empate */
            break;
        case 0:
            printf("\n\nFim da Execucao.");
        default:
            break;
        }
    } while (opcao != 0);
    return 0;
}