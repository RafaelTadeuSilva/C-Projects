#include <stdio.h>
#include <string.h>
int main()
{
    int opcao;
    float totalJogos = 0;
    int jogadaX = 0;
    int jogadaY = 0;
    float empate = 0;
    float vitX = 0;
    float vitO = 0;

    do
    {
        printf("Menu\n1 - Novo Jogo\n2 - Imprimir Ranking\n3 - Imprimir estatisticas\n0 - Para Finalizar\n\n");
        printf("Digite a opcao desejada -> ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            /* novo jogo */
            system("cls");
            char mat[3][3] = {"   ", "   ", "   "};
            int vitoria = 0;
            int erro;
            char jogadorAtual = 'X';
            int jogadas = 0;
            totalJogos++;
            printf("Jogo Atual:\n\n");

            printf("  %c  |  %c  |  %c\n", mat[0][0], mat[0][1], mat[0][2]);
            printf("-----------------\n");
            printf("  %c  |  %c  |  %c\n", mat[1][0], mat[1][1], mat[1][2]);
            printf("-----------------\n");
            printf("  %c  |  %c  |  %c\n", mat[2][0], mat[2][1], mat[2][2]);

            do
            {
                do
                {
                    erro = 0;
                    printf("\nJogada de %c, digite a linha (0-2):", jogadorAtual);
                    scanf("%d", &jogadaX);
                    printf("digite a coluna (0-2):");
                    scanf("%d", &jogadaY);
                    if (jogadaX > 2 || jogadaX < 0 || jogadaY > 2 || jogadaY < 0)
                    {
                        erro = 1;
                        printf("\nValores digitados invalidos\nDigite novamente!");
                    }
                    else if (mat[jogadaX][jogadaY] == ' ') //Verifica se já esta preenchida
                    {
                        mat[jogadaX][jogadaY] = jogadorAtual;
                    }
                    else
                    {
                        erro = 1;
                        printf("\nEspaco ja marcado\nEscolha outro!");
                    }
                } while (erro == 1);
                jogadas++;
                /* verifica vitória */
                int vitlinha = 1;
                int vitcoluna = 1;
                int vitdiag1 = 1;
                int vitdiag2 = 1;

                for (int i = 0; i < 3; i++)
                {
                    if (jogadorAtual != mat[jogadaX][i]) //Verifica linha ultima jogada
                    {
                        vitlinha = 0;
                    }
                    if (mat[i][jogadaY] != jogadorAtual) //Verifica coluna ultima jogada
                    {
                        vitcoluna = 0;
                    }
                    if (mat[i][i] != jogadorAtual) //Verifica diagonal 1
                    {
                        vitdiag1 = 0;
                    }
                    if (mat[i][2 - i] != jogadorAtual) //Verifica diagonal 1
                    {
                        vitdiag2 = 0;
                    }
                }

                system("cls");

                printf("Jogo Atual:\n\n");

                printf("  %c  |  %c  |  %c\n", mat[0][0], mat[0][1], mat[0][2]);
                printf("-----------------\n");
                printf("  %c  |  %c  |  %c\n", mat[1][0], mat[1][1], mat[1][2]);
                printf("-----------------\n");
                printf("  %c  |  %c  |  %c\n", mat[2][0], mat[2][1], mat[2][2]);

                if (vitlinha == 1 || vitcoluna == 1 || vitdiag1 == 1 || vitdiag2 == 1)
                {
                    printf("\nVitoria do Jogador %c!\n", jogadorAtual);
                    vitoria = 1;
                    if (jogadorAtual == 'X')
                        vitX++;
                    else
                        vitO++;
                }
                else if (jogadas == 9) //Empate
                {
                    printf("\nJogo terminado em Empate.\n\n");
                    empate++;
                    break;
                }
                else
                {
                    jogadorAtual = jogadorAtual == 'X' ? 'O' : 'X'; //Muda jogadorAtual
                }
            } while (vitoria == 0);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            printf("Ranking Atual:\n\n");

            if (totalJogos == 0)
                printf("Nenhuma partida foi realizada!\n\n");
            else
            {
                printf("Jogos realizados: %0.f\n", totalJogos);
                printf("Vitorias de X: %0.f\n", vitX);
                printf("Vitorias de O: %0.f\n", vitO);
                printf("Empates: %0.f\n", empate);
            }
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            printf("Estatisticas Atuais:\n\n");

            if (totalJogos == 0)
                printf("Nenhuma partida foi realizada!\n\n");
            else
            {
                printf("Jogos realizados: %0.f\n", totalJogos);
                printf("Vitorias de X: %0.2f%%\n", vitX / totalJogos * 100);
                printf("Vitorias de O: %0.2f%%\n", vitO / totalJogos * 100);
                printf("Empates: %0.2f%%\n", empate / totalJogos * 100);
            }
            system("pause");
            system("cls");
            break;
        case 0:
            printf("\n\nFim da Execucao.");
        default:
            break;
        }
    } while (opcao != 0);
    return 0;
}